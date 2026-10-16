/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_021124f4 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/string.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long size_t;
extern int func_021124f4(char *str1, char *str2, size_t num);
int func_021124f4(char *str1, char *str2, size_t n) {
    const unsigned char *p1 = (unsigned char *) str1;
    const unsigned char *p2 = (unsigned char *) str2;
    unsigned int c1, c2;

    n++;

    while (--n) {
        if ((c1 = *p1++) != (c2 = *p2++)) {
            return (c1 - c2);
        } else if (!c1) {
            break;
        }
    }

    return 0;
}
