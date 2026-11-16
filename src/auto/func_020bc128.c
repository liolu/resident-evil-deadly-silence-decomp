/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0212496c;
extern void *data_027e000c;

void func_020bc128(void) {
    (*(void (**)(void))((u8 *) &data_0212496c + ((M2C_FIELD(data_027e000c, u8 *, 9) - 0x20) * 4)))();
}
