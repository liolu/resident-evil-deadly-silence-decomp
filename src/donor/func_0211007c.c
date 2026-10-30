/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020206d8 from https://github.com/RonyxDumb/mkds src/arm9/020206d8_func_020206d8.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef u16 MATHCRC16Context;
struct MATHCRC16Table {
    u16 table[256];
};
extern void func_0211007c(const struct MATHCRC16Table *table, MATHCRC16Context *context, const void *input, u32 length);
extern void func_0211007c(const struct MATHCRC16Table *table, MATHCRC16Context *context, const void *input, u32 length);
#pragma thumb off
void func_0211007c(const struct MATHCRC16Table *table, MATHCRC16Context *context, const void *input, u32 length) {
    u32 r, i;
    const u16 *t = table->table;
    u8 *data     = (u8 *) input;

    r = *context;
    for (i = 0; i < length; i++) {
        r = (r >> 8) ^ t[(r ^ *data) & 0xff];
        data++;
    }
    *context = (MATHCRC16Context) r;
}
