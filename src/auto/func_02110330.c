/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02110330 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/mem.c (license: none), reused by
 * tools/donor_match.py
 */
void *func_02110330(const void *src, int val, int n) {
    const unsigned char *p;

    unsigned int v = (val & 0xff);

    for (p = (unsigned char *) src, n++; --n;) {
        if (*p++ == v) {
            return ((void *) (p - 1));
        }
    }

    return 0;
}
