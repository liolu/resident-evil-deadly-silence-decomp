/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_0206fcdc(void);

extern M2C_UNK data_0213ad86;

void func_0206fcf8(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 temp_ip;
    s32 var_r0;
    void *temp_r1;

    var_r0  = arg0;
    temp_ip = (s32) (*(u16 *) 0x04000304 & 0x8000) >> 0xF;
    switch (var_r0) {                               /* irregular */
        case 2:
            var_r0 = temp_ip ^ 1;
            break;
        case 3:
            var_r0 = temp_ip;
            break;
        case 4:
            func_0206fcf8(0, arg1, arg2, arg3);
            var_r0 = 1;
            break;
    }
    temp_r1 = (M2C_UNK *) ((s8 *) &data_0213ad86 + (var_r0 * 8));
    if (arg1 != 2) {
        M2C_FIELD(temp_r1, s8 *, 1) = (s8) arg1;
    }
    M2C_FIELD(temp_r1, s8 *, 2)  = (s8) arg2;
    M2C_FIELD(temp_r1, s16 *, 4) = (s16) arg3;
    M2C_FIELD(temp_r1, s8 *, 0)  = 1;
    func_0206fcdc();
}
