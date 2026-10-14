/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0206fcf8(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_02072cb4(void);
void func_02072dc8(M2C_UNK, M2C_UNK);
void func_020883f4(void);
M2C_UNK func_02088648(void);
void func_020b68dc(void);
void func_020b6f14(void);
void func_020b8374(void);
void func_020c3dc8(void);

extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_0214ccc0;
extern s32 data_027e000c;

void func_020c3ee8(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0) == 2) {
        func_020b8374();
        func_020b6f14();
        if (func_02088648() != 0) {
            func_020883f4();
        } else if ((M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) != 3) && (M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) != 6)) {
            func_020c3dc8();
        } else {
            func_020b68dc();
        }
        if (M2C_FIELD(&data_0214ccc0, s32 *, 0xF88) != 0) {
            M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 1;
            data_027e000c = M2C_FIELD(&data_0214ccc0, s32 *, 0xF90);
            func_02072dc8(M2C_FIELD(&data_0214ccc0, s32 *, 0xF88), M2C_FIELD(&data_0214ccc0, s32 *, 0xF8C));
            M2C_FIELD(&data_02143cc0, s8 *, 0xF) = 0;
            func_02072cb4();
            M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 0;
        }
    }
    M2C_FIELD(&data_0213b890, s8 *, 0x16) = 0;
    M2C_FIELD(&data_0213b890, s8 *, 1) = 5;
    func_0206fcf8(0, 2, 0, 0x100);
}
