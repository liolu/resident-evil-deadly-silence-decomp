/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0200af20 from projets/code-lyoko/src/donor/func_0200af20.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed long long int s64;
typedef volatile u16 vu16;
typedef u16 REGType16;
typedef vu16 REGType16v;
typedef struct OSiAlarm OSAlarm;
typedef enum {
    OS_TIMER_PRESCALER_1    = (0UL << 0),
    OS_TIMER_PRESCALER_64   = (1UL << 0),
    OS_TIMER_PRESCALER_256  = (2UL << 0),
    OS_TIMER_PRESCALER_1024 = (3UL << 0)
} OSTimerPrescaler;
typedef enum {
    OS_TIMER_0 = 0,
    OS_TIMER_1 = 1,
    OS_TIMER_2 = 2,
    OS_TIMER_3 = 3
} OSTimer;
static inline void OS_SetTimerCount(OSTimer id, u16 count) {
    *((REGType16 *) ((u32) & (*(REGType16v *) 0x4000100) + id * 4)) = count;
}
static inline void OS_SetTimerControl(OSTimer id, u16 control) {
    *((REGType16 *) ((u32) & (*(REGType16v *) 0x4000102) + id * 4)) = control;
}
typedef u64 OSTick;
extern OSTick func_02104e70(void);
typedef void (*OSAlarmHandler)(void *);
struct OSiAlarm {
    OSAlarmHandler handler;
    void *arg;

    u32 tag;
    OSTick fire;
    OSAlarm *prev;
    OSAlarm *next;

    OSTick period;
    OSTick start;
};
extern void func_02105044(void *arg);
typedef u32 OSIrqMask;
extern void func_0210287c(u32 timerNo, void (*callback)(void *), void *arg);
extern OSIrqMask func_02102810(OSIrqMask mask);
#pragma thumb off
void func_0210538c(OSAlarm *alarm) {
    OSTick tick = func_02104e70();

    OS_SetTimerControl(OS_TIMER_1, 0);

    s64 delta = (s64) (alarm->fire - tick);

    func_0210287c(OS_TIMER_1, func_02105044, ((void *) 0));

    u16 timerCount;
    if (delta < 0) {
        timerCount = (u16) ~1;
    } else if (delta < 0x10000) {
        timerCount = (u16) (~delta);
    } else {
        timerCount = 0;
    }

    OS_SetTimerCount((OSTimer) OS_TIMER_1, timerCount);
    OS_SetTimerControl(OS_TIMER_1, (u16) (0x0080 | 0x0040 | OS_TIMER_PRESCALER_64));

    (void) func_02102810((1UL << 4));
}
