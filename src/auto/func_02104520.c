/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* OS_UnlockMutex from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/os/os_unlock_mutex.c (license:
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
typedef void (*ThreadSwapHook)(OSThread *from, OSThread *to);
typedef struct OSThreadInfo {
    u16 isNeedRescheduling;
    u16 maxEntry;
    u16 inIrq;
    u16 pad_6;
    OSThread *current;
    OSThread *list;
    ThreadSwapHook switchCallback;
    OSThread *threads[16];
} OSThreadInfo;
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
extern int func_021054ac(void);
extern void func_021054c0(int state);
extern OSThreadInfo data_02158894;
extern void func_02104488(OSThread *thread, OSMutex *mutex);
extern void func_02103a8c(OSThreadQueue *queue);
void func_02104520(OSMutex *mutex) {
    int irqState      = func_021054ac();
    OSThread *current = data_02158894.current;

    if (mutex->thread == current) {
        mutex->count--;
        if (mutex->count == 0) {
            func_02104488(current, mutex);
            mutex->thread = ((void *) 0);
            func_02103a8c(&mutex->queue);
        }
    }
    func_021054c0(irqState);
}
