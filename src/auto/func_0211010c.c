/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef volatile u16 vu16;
typedef s32 BOOL;
extern void func_021046b8(const void *addr, u32 count);
extern void func_0210626c(register const void *src, register void *dest, register u32 count);
typedef struct UnkWmBssDesc {
    u16 length;
    u8 unk_02[0x3a];
    u16 unk_3c;
    u8 unk_3e[6];
    u32 unk_44;
    u8 unk_48[8];
    u8 unk_50[8];
} UnkWmBssDesc;

/* func_0205e828 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/wm/wm_gameinfo.c (license: none), reused
 * by tools/donor_match.py */
BOOL func_0211010c(UnkWmBssDesc *desc) {
    vu16 info[4];

    if (desc == 0) {
        return 0;
    }
    if (desc->unk_3c == 0) {
        return 0;
    }
    func_0210626c(desc->unk_50, (void *) info, sizeof(info));
    func_021046b8((void *) info, sizeof(info));
    if (desc->unk_44 == 0 && (info[0] == 0x2348 || info[0] == 0xBD8A) && info[3] == 4) {
        return 1;
    }
    return 0;
}
