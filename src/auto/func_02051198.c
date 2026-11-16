/* compiler: 1.2/sp2p3 */
#include "m2c.h"

u8 func_0200ea0c(void *, s32, u8);
typedef void (*Fn)(void);
extern Fn data_0211cefc[];
extern M2C_UNK data_0214bcc0;
extern void *data_027e000c;

void func_02051198(void) {
    u8 temp_r0;

    data_0211cefc[M2C_FIELD(data_027e000c, u8 *, 0x90)]();
    M2C_FIELD(data_027e000c, s32 *, 0x18) = 0;
    M2C_FIELD(data_027e000c, u8 *, 0xB)   = func_0200ea0c((u8 *) data_027e000c + 0x30, M2C_FIELD(&data_0214bcc0, s32 *, 0x7B0),
                                                          M2C_FIELD(data_027e000c, u8 *, 0xB));
    temp_r0                               = M2C_FIELD(data_027e000c, u8 *, 0x96);
    if (temp_r0 != 0) {
        M2C_FIELD(data_027e000c, u8 *, 0x96) = (u8) (temp_r0 - 1);
    }
}
