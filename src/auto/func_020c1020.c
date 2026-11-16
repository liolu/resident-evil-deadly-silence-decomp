/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020d5298(void);                           /* extern */
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_02147cc0;

void func_020c1020(void) {
    if (M2C_FIELD(&data_0213b890, u8 *, 0x21) == 0) {
        M2C_FIELD(&data_0213daa8, u16 *, 0x74)                            = 0xFFFF;
        M2C_FIELD(&data_02147cc0, s8 *, 0x543)                            = 0;
        M2C_FIELD(M2C_FIELD(&data_02147cc0, void **, 0x544), s16 *, 0x46) = 0;
    }
    func_020d5298();
}
