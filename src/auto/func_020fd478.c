/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef s32 BOOL;
typedef struct UnkLink {
    void *prev;
    void *next;
} UnkLink;
extern BOOL func_020fcb40(u32 chBitMask);
typedef struct UnkSleepCallbackInfo {
    void (*func)(void *);
    void *arg;
    struct UnkSleepCallbackInfo *next;
} UnkSleepCallbackInfo;
typedef void (*UnkStrmCallback)(int status, int chNum, void **buffer, u32 len, int format, void *arg);
typedef struct UnkSndStrm {
    UnkLink link;
    UnkSleepCallbackInfo preSleepInfo;
    UnkSleepCallbackInfo postSleepInfo;
    int format;
    BOOL active : 1;
    BOOL started : 1;
    u32 bufSize;
    int interval;
    UnkStrmCallback callback;
    void *arg;
    int curBlock;
    int volume;
    int alarmNo;
    u32 chBitMask;
    int chNum;
    u8 chNo[16];
} UnkSndStrm;

/* func_02073c7c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/snd/snd_stream.c (license: none),
 * reused by tools/donor_match.py */
BOOL func_020fd478(UnkSndStrm *strm, int chNum, const u8 *chNoList) {
    u32 chBitMask = 0;
    int i;

    for (i = 0; i < chNum; i++) {
        strm->chNo[i] = chNoList[i];
        chBitMask |= 1 << chNoList[i];
    }

    if (!func_020fcb40(chBitMask)) {
        return 0;
    }

    strm->chNum     = chNum;
    strm->chBitMask = chBitMask;
    return 1;
}
