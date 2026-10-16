/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_021102f0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/mem.c (license: none), reused by
 * tools/donor_match.py
 */
int func_021102f0(const void *src1, const void *src2, int n) {
    const unsigned char *p1;
    const unsigned char *p2;

    for (p1 = (const unsigned char *) src1, p2 = (const unsigned char *) src2, n++; --n;) {
        if (*p1++ != *p2++) {
            return ((*--p1 < *--p2) ? -1 : +1);
        }
    }

    return 0;
}
