/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* ADXERR_ItoA from https://github.com/Yotona/twewy libs/cri/src/adx_errs.c (license: CC0-1.0), reused by tools/donor_match.py
 */
extern char data_0214f1cc[32];
void func_020dea60(int value, char *str, int base) {
    int i;
    int len;

    for (i = 0; i < 32; i++) {
        str[i] = value % 10;
        value /= 10;

        if (value == 0) {
            str[i] = '\0';
            break;
        }
    }

    len = func_0211282c(data_0214f1cc);
    len = (len < base - 1) ? len : base - 1;

    for (i = 0; i < len; i++) {
        str[i] = data_0214f1cc[len - 1 - i];
    }

    str[i] = '\0';
}
