/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207c870 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/wm/wm_system.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
extern void func_0210469c(void *ptr, u32 size);
typedef char *va_list;
typedef void (*UnkWmCallbackFunc)(void *arg);
typedef struct UnkWmStatus {
    u16 state;
    u8 unk_002[0xa];
    u32 unk_00c;
    u8 unk_010[0x2c];
    u16 unk_03c;
    u16 unk_03e;
    u8 unk_040[0x32];
    u16 unk_072;
    u8 unk_074[0x8];
    u32 unk_07c;
    u8 unk_080[0x6];
    u16 unk_086;
    u8 unk_088[0x14];
    u16 unk_09c;
    u8 unk_09e[0x1e];
    u16 unk_0bc;
    u8 unk_0be[0x8];
    u16 unk_0c6;
    u8 unk_0c8[0x30];
    u16 unk_0f8;
    u8 unk_0fa[0x88];
    u16 unk_182;
    u8 unk_184[0x4];
    u16 unk_188;
} UnkWmStatus;
typedef struct UnkWmArm9Buf {
    void *unk_000;
    UnkWmStatus *status;
    void *unk_008;
    void *unk_00c;
    void *unk_010;
    u16 dmaNo;
    u16 unk_016;
    UnkWmCallbackFunc callbackTable[0x2c];
    UnkWmCallbackFunc indCallback;
    UnkWmCallbackFunc portCallbackTable[16];
    void *portCallbackArgument[16];
    u32 connectedAidBitmap;
    u16 myAid;
} UnkWmArm9Buf;
extern u32 func_0210d918(void);
extern u32 func_0210d814(s32 paramNum, ...);
extern UnkWmArm9Buf *data_0215b1ac;
u32 func_0210d918(void);
u32 func_0210d814(s32 paramNum, ...) {
    u32 result;
    u16 now;
    va_list args;

    result = func_0210d918();
    if (result != 0) {
        return result;
    }
    func_0210469c(&data_0215b1ac->status->state, 2);
    now = data_0215b1ac->status->state;

    result = 3;
    ((args) = ((va_list) ((char *) ((unsigned int) (&paramNum) & ~3U) + ((((unsigned int) (sizeof(paramNum))) + 3U) & ~3U))));
    for (; paramNum; paramNum--) {
        if ((*(u32 *) ((args += ((((unsigned int) (sizeof(u32))) + 3U) & ~3U)) -
                       ((((unsigned int) (sizeof(u32))) + 3U) & ~3U))) == now) {
            result = 0;
        }
    }
    ((void) 0);
    return result;
}
