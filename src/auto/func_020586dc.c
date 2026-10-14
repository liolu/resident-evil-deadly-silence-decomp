/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02079220(void);
void func_0207923c(void);

extern s16 data_0212d000;
extern s8 data_0213746c;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213daa8;

void func_020586dc(void) {
    data_0212d000 = -1;
    data_0213746c = 0;
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) | 0x80);
    M2C_FIELD(&data_0213b890, u8 *, 0x90) = (u8) (M2C_FIELD(&data_0213b890, u8 *, 0x90) & ~0x10);
    M2C_FIELD(&data_0213b890, s8 *, 0x94) = 0;
    func_0207923c();
    func_02079220();
}
