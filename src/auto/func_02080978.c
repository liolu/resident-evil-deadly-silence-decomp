#include "m2c.h"

M2C_UNK func_02080998(u8);                          /* extern */
extern M2C_UNK data_0212df68;

void func_02080978(s32 arg0) {
    func_02080998(*((u8 *) ((s8 *) &data_0212df68 + (arg0 * 0xC))));
}
