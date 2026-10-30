/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02077a9c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_printf.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef int s32;
typedef struct UnkPrintfDst {
    u32 len;
    char *cur;
    char *base;
} UnkPrintfDst;
void func_021037b0(UnkPrintfDst *p, char c, s32 n) {
    if (n > 0) {
        u32 i;
        u32 k = p->len;
        if (k > n) {
            k = n;
        }
        for (i = 0; i < k; ++i) {
            p->cur[i] = c;
        }
        p->len -= k;
        p->cur += n;
    }
}
