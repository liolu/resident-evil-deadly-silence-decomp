/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02005898(void);
void func_0200642c(void);
void func_02056ed4(void);
void func_020763c4(void);
void func_02077ef4(void);
void func_02077fb8(void);
void func_020f7d04(void);
void func_021060b8(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b2c0;
extern M2C_UNK data_027e01ac;

void func_02078240(void) {
    func_020f7d04();
    *(s32 *) 0x04000540 = 3;
    func_021060b8((s32) &data_027e01ac, (s32) &data_0213b2c0, 0x98);
    M2C_FIELD(&data_0213b2b4, volatile s8 *, 3) = 1;
    func_02005898();
    do {

    } while (M2C_FIELD(&data_0213b2b4, volatile s8 *, 3) != 0);
    M2C_FIELD(&data_0213b2b4, volatile u8 *, 2) = (u8) M2C_FIELD(&data_0213b2b4, volatile u8 *, 1);
    func_02077ef4();
    func_020763c4();
    func_02056ed4();
    func_02077fb8();
    func_0200642c();
}
