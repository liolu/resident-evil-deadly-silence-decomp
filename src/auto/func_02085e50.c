/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0207cd2c(M2C_UNK, M2C_UNK);
void func_02085db8(void);
void func_02085de8(void);
void func_02085e1c(void);
void func_02088204(M2C_UNK, M2C_UNK);
M2C_UNK func_020885f0(void);

extern M2C_UNK data_021374cc;

void func_02085e50(s32 arg0, s32 arg1) {
    s32 var_r4;

    var_r4 = 0;
    func_02085db8();
    if ((arg1 != 0) && (func_020885f0() == 0)) {
        M2C_FIELD(&data_021374cc, u16 *, 0x12) = (u16) (M2C_FIELD(&data_021374cc, u16 *, 0x12) + 1);
    }
    M2C_FIELD(&data_021374cc, u16 *, 0x20) = (u16) (M2C_FIELD(&data_021374cc, u16 *, 0x20) + 1);
    func_02085de8();
    switch (arg0) {                                 /* irregular */
        default:
        case 0:
            M2C_FIELD(&data_021374cc, u16 *, 0x22) = 0U;
            break;
        case 2:
            M2C_FIELD(&data_021374cc, u16 *, 0x18) = (u16) (M2C_FIELD(&data_021374cc, u16 *, 0x18) + 1);
            M2C_FIELD(&data_021374cc, u16 *, 0x22) = (u16) (M2C_FIELD(&data_021374cc, u16 *, 0x22) + 1);
            func_02085e1c();
            func_0207cd2c(1, 1);
            var_r4 = 1;
            break;
        case 1:
            var_r4 = 1;
            break;
    }
    func_02088204((s32) M2C_FIELD(&data_021374cc, u16 *, 0x20), var_r4);
}
