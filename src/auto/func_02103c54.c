/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* OS_CreateThread from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/os/os_create_thread.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef struct OSThread OSThread;
typedef struct OSMutex OSMutex;
typedef struct OSThreadQueue {
    u16 head;
    u16 tail;
} OSThreadQueue;
enum {
    OS_THREAD_STATE_WAITING    = 0,
    OS_THREAD_STATE_READY      = 1,
    OS_THREAD_STATE_TERMINATED = 2
};
typedef struct OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
} OSMutexQueue;
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutex *prev;
    OSMutex *next;
};
typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pcPlus4;
    u32 spSvc;
    u8 cpContext[0x1c];
} OSContext;
struct OSThread {
    OSContext context;
    u32 state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSMutex *mutex;
    OSMutexQueue mutexQueue;
    u32 stackTop;
    u32 stackBottom;
    u32 stackWarningOffset;
    OSThreadQueue joinQueue;
};
extern void func_02103fbc(OSContext *context, u32 pc, u32 sp);
extern int func_021054ac(void);
extern void func_021054c0(int state);
extern OSThread *data_021588a8[];
extern int func_02103f8c(void);
extern void func_02103f24(OSThread *thread);
extern void func_021060a4(u32 value, void *dest, u32 size);
extern void func_02103c38(void);
void func_02103c54(OSThread *thread, void (*func)(void *), void *arg, void *stack, u32 stackSize, u32 priority) {
    int irqState;
    s32 id;
    OSContext *context;
    volatile u32 zero;

    irqState = func_021054ac();
    id       = func_02103f8c();
    if (id < 0) {
        func_021054c0(irqState);
        return;
    }
    thread->priority  = priority;
    thread->id        = id;
    thread->state     = OS_THREAD_STATE_WAITING;
    thread->profiler  = ((void *) 0);
    data_021588a8[id] = thread;
    func_02103f24(thread);

    thread->stackBottom                = (u32) stack;
    thread->stackTop                   = (u32) stack - stackSize;
    thread->stackWarningOffset         = 0;
    *(u32 *) (thread->stackBottom - 4) = 0xfddb597d;
    *(u32 *) thread->stackTop          = 0x7bf9dd5b;
    thread->joinQueue.head             = 0;

    context = &thread->context;
    func_02103fbc(context, (u32) func, (u32) stack - 4);
    context->r[0] = (u32) arg;
    context->lr   = (u32) func_02103c38;

    zero = 0;
    func_021060a4(zero, (void *) ((u32) stack - stackSize + 4), stackSize - 8);
    thread->mutex           = ((void *) 0);
    thread->mutexQueue.head = ((void *) 0);
    thread->mutexQueue.tail = ((void *) 0);
    func_021054c0(irqState);
}
