/* compiler: 1.2/sp2p3  */
#include "m2c.h"

s32 func_02079148();                                /* extern */
extern M2C_UNK data_0211e778;

u8 func_02079680(void) {
    return *((u8 *) ((s8 *) &data_0211e778 + (func_02079148() & 0xF)));
}
