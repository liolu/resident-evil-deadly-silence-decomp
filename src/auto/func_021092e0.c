/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
extern u32 func_021092e0(const char *name, s32 nameLen);

/* func_02060548 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fs/fs_archive.c (license: none), reused by
 * tools/donor_match.py */
u32 func_021092e0(const char *name, s32 nameLen) {
    u32 ret = 0;
    if (nameLen <= 3) {
        int i = 0;
        for (; i < nameLen; ++i) {
            u32 c = (u32) (*(u8 *) (name + i));
            if (c == 0) {
                break;
            }
            c = (u32) (c - 'A');
            if (c <= (u32) ('Z' - 'A')) {
                c = (u32) (c + 'a');
            } else {
                c = (u32) (c + 'A');
            }
            ret |= (u32) (c << (i * 8));
        }
    }
    return ret;
}
