/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213ba90;

void func_020d4aac(void) {
    u8 *obj;

    if ((s32) M2C_FIELD(&data_0213ba90, s16 *, 0x70) > -0x4000) {
        obj                                    = *(u8 **) ((u8 *) &data_0213b890 + 0x4C);
        *(s16 *) (obj + 0x68)                  = (s16) (*(s16 *) (obj + 0x68) - 0x200);
        M2C_FIELD(&data_0213ba90, s16 *, 0x70) = (s16) (M2C_FIELD(&data_0213ba90, s16 *, 0x70) - 0x200);
    } else {
        M2C_FIELD(&data_0213b890, s16 *, 0x26) = 0x3C;
        M2C_FIELD(&data_0213b890, s8 *, 0x21)  = 2;
    }
}
