/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02078d60(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_02078f38(M2C_UNK, M2C_UNK, M2C_UNK);
M2C_UNK func_02079148(M2C_UNK, M2C_UNK);
void func_02079220(void);
void func_0207923c(void);

extern M2C_UNK data_0211e864;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;

void func_02079174(void) {
    s32 var_r5;
    u8 temp_r4;

    M2C_FIELD(&data_0213b890, u8 *, 0x92) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 0);
    M2C_FIELD(&data_0213b890, u8 *, 0x93) = (u8) M2C_FIELD(&data_0213ad98, u8 *, 1);
    temp_r4                               = M2C_FIELD(&data_0213b890, u8 *, 0x91);
    func_02078f38((s32) M2C_FIELD(&data_0213ad98, u8 *, 0), (s32) M2C_FIELD(&data_0213ad98, u8 *, 1),
                  (s32) M2C_FIELD(&data_0213ad98, u8 *, 2));
    if (M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) {
        var_r5 = 1;
    } else {
        var_r5 = 0;
    }
    func_02078d60(*((M2C_UNK *) ((s8 *) &data_0211e864 + (M2C_FIELD(&data_0213b890, u8 *, 0x92) * 4))),
                  func_02079148((s32) M2C_FIELD(&data_0213b890, u8 *, 0x92), (s32) M2C_FIELD(&data_0213b890, u8 *, 0x93)),
                  var_r5);
    if (temp_r4 != M2C_FIELD(&data_0213b890, u8 *, 0x91)) {
        func_0207923c();
        func_02079220();
    }
    M2C_FIELD(&data_0213b890, s16 *, 0x5A) = 0;
}
