/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef short s16;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef volatile s16 vs16;
extern void func_021046d4(void *ptr, u32 size);
typedef struct UnkSndPlayerWork {
    s16 variable[16];
    u32 tickCounter;
} UnkSndPlayerWork;
typedef struct UnkSndSharedWork {
    vu32 finishCommandTag;
    vu32 playerStatus;
    vu16 channelStatus;
    vu16 captureStatus;
    vu32 unk_0c[5];
    UnkSndPlayerWork player[16];
    vs16 globalVariable[16];
} UnkSndSharedWork;
extern void func_0210743c(UnkSndSharedWork *work);

/* func_0207afa8 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/snd/snd_work.c (license: none), reused by
 * tools/donor_match.py */
void func_0210743c(UnkSndSharedWork *work) {
    s32 i;
    s32 j;

    work->playerStatus     = 0;
    work->channelStatus    = 0;
    work->captureStatus    = 0;
    work->finishCommandTag = 0;
    for (i = 0; i < 16; i++) {
        work->player[i].tickCounter = 0;
        for (j = 0; j < 16; j++) {
            work->player[i].variable[j] = -1;
        }
    }
    for (i = 0; i < 16; i++) {
        work->globalVariable[i] = -1;
    }
    func_021046d4(work, sizeof(UnkSndSharedWork));
}
