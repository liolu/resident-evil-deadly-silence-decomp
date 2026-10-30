/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* SomeHashing from https://github.com/RonyxDumb/mkds src/arm9/02020720_SomeHashing.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
struct MATHCRC16Table {
    u16 table[256];
};
extern void func_021100c4(struct MATHCRC16Table *table, u16 poly);
#pragma thumb off
void func_021100c4(struct MATHCRC16Table *table, u16 poly) {
    u32 r, i, j;
    u16 *t = table->table;

    for (i = 0; i < 256; i++) {
        r = i;
        for (j = 0; j < 8; j++) {
            if (r & 1) {
                r = (r >> 1) ^ poly;
            } else {
                r >>= 1;
            }
        }
        t[i] = (u16) r;
    }
}
