/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* strtoul from https://github.com/Yotona/twewy libs/c/src/strtoul.c (license: CC0-1.0), reused by tools/donor_match.py */
extern int data_0215bda0;
typedef struct {
    char *NextChar;
    int NullCharDetected;
} __InStrCtrl;
extern int func_02112440(void *, int, int);
extern unsigned long func_021128e4(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg,
                                   int *chars_scanned, int *negative, int *overflow);
unsigned long func_021128e4(int base, int max_width, int (*ReadProc)(void *, int, int), void *ReadProcArg, int *chars_scanned,
                            int *negative, int *overflow);
unsigned long func_02112848(const char *restrict str, char **restrict end, int base) {
    unsigned long value;
    int count, negative, overflow;

    __InStrCtrl isc;
    isc.NextChar         = (char *) str;
    isc.NullCharDetected = 0;

    value = func_021128e4(base, 0x7fffffff, &func_02112440, (void *) &isc, &count, &negative, &overflow);

    if (end) {
        *end = (char *) str + count;
    }

    if (overflow) {
        value         = ~0;
        data_0215bda0 = 34;
    } else if (negative) {
        value = -value;
    }

    return (value);
}
