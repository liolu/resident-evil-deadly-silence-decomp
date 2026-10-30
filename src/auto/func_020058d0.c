/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_020e5f4c(M2C_UNK);                     /* extern */
M2C_UNK func_02101c5c(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_021021f0(void *, M2C_UNK, M2C_UNK);    /* extern */
M2C_UNK func_021046d4(void *, M2C_UNK);             /* extern */
extern void *data_02137264;

void func_020058d0(void) {
    if (data_02137264 != NULL) {
        if (M2C_FIELD(data_02137264, u8 *, 2) != 0) {
            func_021046d4(data_02137264 + 0x8BF64, 0x200);
            func_021021f0(data_02137264 + 0x8BF64, 0, 0x200);
            func_021046d4(data_02137264 + 0x8C164, 0xC000);
            func_02101c5c(data_02137264 + 0x8C164, 0, 0xC000);
            M2C_FIELD(data_02137264, u8 *, 2) = 0U;
        }
        func_020e5f4c(0);
    }
}
