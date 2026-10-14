/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02074f38(void);
void func_020c4798(M2C_UNK);

extern M2C_UNK data_0213b890;

void func_020c2068(void) {
    M2C_UNK (*temp_r1)();
    s32 var_r0;

    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0xE) = 0;
    temp_r1 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), M2C_UNK (**)(), 0x10);
    if (temp_r1 != NULL) {
        temp_r1();
    } else {
        if (M2C_FIELD(&data_0213b890, u8 *, 0x279) & 0xC0) {
            M2C_FIELD(&data_0213b890, s32 *, 0x2C) = 3;
            var_r0 = 5;
        } else if (M2C_FIELD(&data_0213b890, u8 *, 0x279) & 1) {
            var_r0 = 3;
        } else if (M2C_FIELD(&data_0213b890, u8 *, 0x279) & 0xA) {
            var_r0 = 1;
        } else {
            var_r0 = 2;
        }
        func_020c4798(var_r0);
    }
    func_02074f38();
}
