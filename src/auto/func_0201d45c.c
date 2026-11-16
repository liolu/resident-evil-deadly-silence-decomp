/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

s32 func_020d9764(M2C_UNK *);                       /* extern */
s32 func_020d98fc(s16, s16, M2C_UNK *);             /* extern */
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144c34;

s32 func_0201d45c(s32 arg0, s32 arg1) {
    s32 ret;

    if (M2C_FIELD(&data_02143cc0, u8 *, 0xFDA) != 0) {
        ret = 0;
        goto end;
    }
    if (func_020d98fc(arg0, arg1, &data_02144c34) == 0) {
        ret = 0;
        goto end;
    }
    if (func_020d9764(&data_02144c34) == 0) {
        ret = 1;
    } else {
        ret = 0;
    }
end:
    return ret;
}
