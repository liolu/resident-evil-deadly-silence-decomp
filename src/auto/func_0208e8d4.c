/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02086014(void);
void func_02087e38(M2C_UNK, M2C_UNK);
void func_0208881c(void);
void func_0208e710(M2C_UNK);
void func_0209093c(void);
void func_02095d64(void);
void func_020b5fa0(void);
void func_020b6314(void);
void func_020c440c(void);
void func_020c46d4(M2C_UNK, M2C_UNK);
void func_020c47b8(void);
void func_020d69c0(void);

extern M2C_UNK *data_02137894;
extern M2C_UNK *data_02137898;
extern M2C_UNK *data_0213789c;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213af7c;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8ac;
extern M2C_UNK data_0213b8e0;

void func_0208e8d4(void) {
    if (M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) == 0) {
        M2C_FIELD(&data_0213b2b4, u8 *, 0xB4) = 1U;
        func_020c47b8();
        func_020c46d4(0x25, 0);
        data_02137894 = &data_0213b8ac;
        data_02137898 = &data_0213b8e0;
        data_0213789c = &data_0213b8e0;
        func_0208881c();
        func_0209093c();
        M2C_FIELD(&data_0213af7c, s8 *, 0x20) = 2;
        M2C_FIELD(&data_0213ad48, s8 *, 6)    = 0;
        M2C_FIELD(&data_0213b2b4, u8 *, 0xB1) = 1U;
        M2C_FIELD(&data_0213b2b4, u8 *, 0xB2) = 0U;
    }
    func_020c440c();
    if (M2C_FIELD(&data_0213b890, u8 *, 1) == 5) {
        if (M2C_FIELD(&data_0213b2b4, u8 *, 0xB0) == 1) {
            func_02086014();
            func_02087e38((s32) M2C_FIELD(&data_0213b2b4, u8 *, 0xB1), (s32) M2C_FIELD(&data_0213b2b4, u8 *, 0xB2));
            M2C_FIELD(&data_0213ad48, s8 *, 6) = 1;
            M2C_FIELD(&data_0213ad48, u8 *, 2) = (u8) M2C_FIELD(&data_0213b2b4, u8 *, 0xB3);
            M2C_FIELD(&data_0213ad48, s8 *, 1) = 0;
            M2C_FIELD(&data_0213ad48, s8 *, 4) = 0;
            func_02095d64();
            M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_020b5fa0;
        } else {
            M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_020d69c0;
            M2C_FIELD(&data_0213af7c, s8 *, 0x20)        = 0;
            func_0208e710(0);
            func_0208e710(1);
        }
    }
    func_020b6314();
}
