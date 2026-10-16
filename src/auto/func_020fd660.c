/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef s32 BOOL;
extern BOOL func_021042ec(void *queue, void *msg, s32 flags);
extern void func_021067e4(u32 chBitMask, u32 capBitMask, u32 alarmBitMask, u32 flags);
extern void func_021065e4(int a, int b, int c, int d);
extern void func_02106e6c(int flag);
extern void func_02106ddc(u32 tag);
extern u32 func_02106d0c(void);
extern void func_020fcaec(u32 capBitMask);
extern BOOL func_020fcb08(u32 chBitMask);
extern void func_020fca88(int alarm);
typedef struct UnkSndFader {
    s32 origin;
    s32 target;
    s32 counter;
    s32 frames;
} UnkSndFader;
typedef void (*UnkCaptureCallback)(void *buf0, void *buf1, u32 size, int format, void *arg);
typedef struct UnkSndCapture {
    BOOL active;
    int type;
    int format;
    void *buf0;
    void *buf1;
    u32 bufSize;
    u32 unk_18;
    u32 unk_1c;
    u32 lockedChBitMask;
    u32 chBitMask;
    u32 capBitMask;
    int alarmNo;
    u32 unk_30;
    UnkCaptureCallback callback;
    void *arg;
    UnkSndFader fader;
    BOOL stopAfterFade;
    int volume;
} UnkSndCapture;
typedef struct UnkMessageQueue {
    u8 unk_00[0x20];
} UnkMessageQueue;
extern UnkMessageQueue data_02157cf4;
extern UnkSndCapture data_02157d08;
extern void func_020fd660(void);

/* func_020742fc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/snd/snd_capture.c (license: none),
 * reused by tools/donor_match.py */
void func_020fd660(void) {
    UnkSndCapture *capture = &data_02157d08;
    BOOL hasAlarm;

    if (!data_02157d08.active) {
        return;
    }

    hasAlarm = capture->alarmNo >= 0;
    func_021067e4(capture->chBitMask, capture->capBitMask, hasAlarm ? 1 << capture->alarmNo : 0, 0);

    if (hasAlarm) {
        u32 tag = func_02106d0c();
        func_02106e6c(1);
        func_02106ddc(tag);

        while (func_021042ec(&data_02157cf4, 0, 0)) {
        }
    }

    if (capture->capBitMask != 0) {
        func_020fcaec(capture->capBitMask);
    }
    if (capture->lockedChBitMask != 0) {
        func_020fcb08(capture->lockedChBitMask);
    }
    if (hasAlarm) {
        func_020fca88(capture->alarmNo);
    }
    if (capture->type == 1) {
        func_021065e4(0, 0, 0, 0);
    }

    capture->active = 0;
}
