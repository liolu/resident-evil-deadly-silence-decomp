/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020712a0 from https://github.com/tangosdev/sm64ds-decomp src/unnamed/arm9/0207/func_020712a0.c (license: MIT), reused
 * by tools/donor_match.py */
typedef struct Decimal {
    unsigned char sign;
    char unused;
    short exp;
    struct {
        unsigned char length;
        unsigned char text[32];
        unsigned char unused;
    } sig;
} Decimal;
extern void func_02115dec(Decimal *result, int length);
void func_02115a4c(Decimal *result, unsigned char *digits, short exp) {
    int i;
    unsigned char c;
    result->exp  = exp;
    result->sign = 0;
    i            = 0;
    while (i < 0x20 && digits[0] != 0) {
        result->sig.text[i++] = (unsigned char) (*digits++ - 0x30);
    }
    result->sig.length = (unsigned char) i;
    if (digits[0] == 0) {
        return;
    }
    if (digits[0] < 5) {
        return;
    }
    if (digits[0] > 5) {
        goto docall;
    }
    c = digits[1];
    digits++;
    while (c != 0) {
        if (c != 0x30) {
            goto docall;
        }
        c = *++digits;
    }
    if ((result->sig.text[i - 1] & 1) == 0) {
        return;
    }
docall:
    func_02115dec(result, result->sig.length);
}
