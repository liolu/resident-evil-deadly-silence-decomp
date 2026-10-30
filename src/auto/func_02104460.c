/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* Mutex_PopOldestHeld from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/os/mutex_pop_oldest_held.c
 * (license: CC0-1.0), reused by tools/donor_match.py */
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
OSMutex *func_02104460(OSThread *thread) {
    OSMutex *head = thread->mutexQueue.head;
    OSMutex *next = head->next;

    if (next == ((void *) 0)) {
        thread->mutexQueue.tail = ((void *) 0);
    } else {
        next->prev = ((void *) 0);
    }
    thread->mutexQueue.head = next;
    return head;
}
