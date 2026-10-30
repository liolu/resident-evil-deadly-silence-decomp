/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207c3f0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/wm/wm_system.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
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
extern u32 func_0210dd04(void *buf, u16 dmaNo);
extern u32 func_0210db24(void *buf, u16 dmaNo, u32 size);
extern UnkWmArm9Buf *data_0215b1ac;
u32 func_0210dd04(void *buf, u16 dmaNo) {
    u32 result = func_0210db24(buf, dmaNo, 0xf00);

    if (result != 0) {
        return result;
    }
    data_0215b1ac->unk_016 = 0;
    return result;
}
u32 func_0210db24(void *buf, u16 dmaNo, u32 size);
