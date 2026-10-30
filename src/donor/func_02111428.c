/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* __round_decimal from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/msl/round_decimal.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned int u32;
typedef signed short s16;
typedef struct Decimal {
    u8 sign;
    u8 unk_01;
    s16 exp;
    u8 length;
    u8 digits[32];
    u8 pad_25;
} Decimal;
extern void func_02111428(Decimal *dec, int newLength);
void func_02111428(Decimal *dec, int newLength) {
    u8 *p;
    u8 *tail;
    u32 digit;
    u32 carry;
    u8 *digits;
    int length;

    if (newLength < 0) {
    zero:
        dec->exp       = 0;
        dec->length    = 1;
        dec->digits[0] = '0';
        return;
    }
    length = dec->length;
    if (newLength >= length) {
        return;
    }

    digits = dec->digits;
    p      = digits + newLength + 1;
    digit  = (u8) (*--p - '0');
    if (digit == 5) {
        tail = digits + length;
        do {
            tail--;
        } while (tail > p && *tail == '0');
        if (tail == p) {
            carry = p[-1] & 1;
        } else {
            carry = 1;
        }
    } else {
        carry = digit > 5;
    }

    while (newLength != 0) {
        digit = (u8) (*--p - '0' + carry);
        carry = digit > 9;
        if (carry || digit == 0) {
            newLength--;
        } else {
            *p = digit + '0';
            break;
        }
    }

    if (carry) {
        dec->exp++;
        dec->length    = 1;
        dec->digits[0] = '1';
        return;
    }
    if (newLength == 0) {
        goto zero;
    }
    dec->length = newLength;
}
