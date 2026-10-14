/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020779b4(void);
void func_02092b2c(void);
M2C_UNK func_020b1c60(void);
void func_020c440c(void);
void func_020c46d4(M2C_UNK, M2C_UNK);
void func_020c47b8(void);

extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;

void func_020aff50(void) {
    s32 temp_r0;

    if (M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) == 0) {
        func_020c47b8();
        M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) = 1U;
        temp_r0 = func_020b1c60();
        if (temp_r0 != 0) {
            func_020c46d4(0x28, temp_r0);
        } else {
            func_020c46d4(0x27, 0);
        }
    }
    func_02092b2c();
    func_020c440c();
    if (M2C_FIELD(&data_0213b890, u8 *, 1) == 5) {
        M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_020779b4;
    }
}
