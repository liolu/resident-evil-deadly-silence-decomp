/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 data_021402e8;

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} T12;

void func_020911d0(void **arg0, s32 arg1, void *arg2, s32 arg3) {
    s32 temp_ip;
    s32 temp_r2;
    T12 loc;

    temp_r2       = (M2C_FIELD(M2C_FIELD(*arg0, void **, 0x14), u8 *, 1) * 0x58) + data_021402e8;
    temp_ip       = (arg1 * 0x58) + temp_r2;
    loc           = *(T12 *) (temp_ip + 0x4c);
    *(T12 *) arg2 = loc;
    if (arg3 != 0) {
        M2C_FIELD(temp_ip, s32 *, 0) = M2C_FIELD(temp_ip, s32 *, 0) | 4;
    }
}
