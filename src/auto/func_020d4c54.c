/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef void (*Fn)(void);

s32 func_020c0148(s32);                             /* extern */
M2C_UNK func_020c4798(M2C_UNK);                     /* extern */
extern Fn data_02126754[];
extern M2C_UNK data_0213b890;

void func_020d4c54(void) {
    data_02126754[M2C_FIELD(&data_0213b890, u8 *, 0x21)]();
    if (((u32) M2C_FIELD(&data_0213b890, u8 *, 0x21) < 1U) &&
        (func_020c0148(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0xBC) == 1)) {
        func_020c4798(2);
    }
}
