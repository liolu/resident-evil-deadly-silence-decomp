/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* vsnprintf from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/printf.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long size_t;
typedef char *va_list;
typedef struct {
    char *CharStr;
    size_t MaxCharCount;
    size_t CharsWritten;
} __OutStrCtrl;
int func_02110550(void *(*WriteProc)(void *, const char *, size_t), void *WriteProcArg, const char *format_str, va_list arg);
void *func_02110500(void *wosc, const char *buffer, size_t numchars);
int func_0211048c(char *s, unsigned int n, const char *format, va_list arg) {
    unsigned int end;
    __OutStrCtrl osc;

    osc.CharStr      = s;
    osc.MaxCharCount = n;
    osc.CharsWritten = 0;

    end = func_02110550(&func_02110500, &osc, format, arg);

    if (s != 0) {
        if (end < n) {
            s[end] = 0;
        } else if (n > 0) {
            *(s + n - 1) = 0;
        }
    }

    return end;
}
