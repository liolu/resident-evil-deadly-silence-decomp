/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned char u8;

/* func_0205fba8 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/fs/fs_archive.c (license: none), reused by
 * tools/donor_match.py */
int func_021089e8(const char *a, const char *b, u32 len) {
    u32 i;
    for (i = 0; i < len; ++i) {
        u32 c = (u32) (*(u8 *) (a + i) - 'A');
        u32 d = (u32) (*(u8 *) (b + i) - 'A');
        if (c <= 'Z' - 'A') {
            c += 'a' - 'A';
        }
        if (d <= 'Z' - 'A') {
            d += 'a' - 'A';
        }
        if (c != d) {
            return (int) (c - d);
        }
    }
    return 0;
}
