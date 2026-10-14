/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020b82f0(M2C_UNK);                     /* extern */
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bd18;
extern M2C_UNK data_02144cc0;

void func_02095090(s32 arg0) {
    switch (arg0) {                                 /* irregular */
    case 2:
        M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = (s32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) | 0x20000);
        break;
    case 1:
        M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = (s32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) | 0x10000);
        break;
    }
    M2C_FIELD(&data_0213bd18, s16 *, 4) = 0;
    M2C_FIELD(&data_0213bd18, s16 *, 6) = 0;
    func_020b82f0(0x17);
    M2C_FIELD(&data_02144cc0, s8 *, 0xAD) = 1;
}
