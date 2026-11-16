/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    u8 pad0[4];
    s16 a4;
    u8 pad6[0xE];
    u16 a14;
    u8 pad16[0xE];
    u8 a24;
    u8 pad25[2];
    u8 a27;
    u8 pad28[0x1C];
} Buf;

M2C_UNK func_01ffc510(M2C_UNK *);
void func_020b8818(M2C_UNK *);
M2C_UNK func_0210626c(M2C_UNK *, M2C_UNK *, M2C_UNK);
extern M2C_UNK data_0213aaf0;
extern M2C_UNK data_02144b40;

void func_020aec84(void) {
    Buf b;

    if (M2C_FIELD(&data_0213aaf0, u16 *, 8) != 0x7FFF) {
        func_0210626c(&data_02144b40, (M2C_UNK *) &b, 0x44);
        b.a14 = M2C_FIELD(&data_0213aaf0, u16 *, 8);
        b.a4  = 2;
        b.a24 = M2C_FIELD(&data_0213aaf0, u8 *, 0xA);
        b.a27 = 0x29;
        func_020b8818((M2C_UNK *) &b);
        func_01ffc510((M2C_UNK *) &b);
    }
}
