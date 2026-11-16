/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern s32 func_020d9764(void *obj);
extern s32 func_020d98fc(s16 a, s16 b, void *obj);
extern u8 data_02143cc0[];
extern u8 data_02144c34[];

s32 func_0203d1d0(s32 arg0, s32 arg1) {
    if (func_020d98fc((s16) arg0, (s16) arg1, data_02144c34) == 0) {
        return 0;
    }
    if (func_020d9764(data_02144c34) != 0) {
        return 0;
    }
    if (data_02143cc0[0xFDA] == 0) {
        return 1;
    }
    return 0;
}
