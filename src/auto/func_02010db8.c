/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0209566c(void);
void func_020c46d4(M2C_UNK, M2C_UNK);

extern void *data_0213ad2c;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213bb18;

void func_02010db8(void) {
    func_020c46d4(0x1F, 0);
    M2C_FIELD(&data_0213b2b4, s8 *, 0xB4) = 3;
    M2C_FIELD(&data_0213bb18, u8 *, 0x1C8) = (u8) (M2C_FIELD(&data_0213bb18, u8 *, 0x1C8) | 8);
    if ((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && (M2C_FIELD(data_0213ad2c, u8 *, 0xD) == 0xFF)) {
        func_0209566c();
    }
    M2C_FIELD(&data_0213b890, s8 *, 0x94) = 1;
}
