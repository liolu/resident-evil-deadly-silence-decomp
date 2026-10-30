/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* sprintf from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/printf.c (license: none), reused by
 * tools/donor_match.py */
typedef char *va_list;
int func_0211048c(char *s, unsigned int n, const char *format, va_list arg);
int func_02110440(char *s, const char *format, ...) {
    return func_0211048c(
        s, 0xffffffffUL, format,
        ((va_list) ((char *) ((unsigned int) (&format) & ~3U) + ((((unsigned int) (sizeof(format))) + 3U) & ~3U))));
}
