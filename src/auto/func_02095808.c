/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_020956d8(s32);
void func_0209572c(void);
extern M2C_UNK data_0212036c;
extern M2C_UNK data_0212041c;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;

void func_02095808(u32 arg0) {
    u32 sel;
    u8 *tbl;

    if ((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && (arg0 <= 0x20U)) {
        sel = (M2C_FIELD(&data_0213bb18, u32 *, 0x1FC) << 0x1E) >> 0x1F;
        tbl = (u8 *) &data_0212036c;
        func_020956d8(((u32 *) ((u8 *) &data_0212041c + sel * 0x2C))[tbl[arg0]]);
        func_0209572c();
    }
}
