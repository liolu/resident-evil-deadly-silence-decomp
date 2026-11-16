/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_02125b38;
extern M2C_UNK data_0213b890;

void func_020c9580(void) {
    void *obj;

    obj = M2C_FIELD(&data_0213b890, void **, 0x4C);
    obj = M2C_FIELD(obj, void **, 0x2F8);
    (*(void (**)(void))((u8 *) &data_02125b38 + (M2C_FIELD(obj, u8 *, 2) * 4)))();
}
