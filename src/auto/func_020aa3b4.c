/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020aa388(void *);                      /* extern */
M2C_UNK func_020adad0(u16);                         /* extern */
extern M2C_UNK data_02121fac;

void func_020aa3b4(void *arg0) {
    u8 temp_r3;
    u8 temp_r3_2;

    M2C_FIELD(arg0, s8 *, 0x93)  = 4;
    M2C_FIELD(arg0, s8 *, 0xA2)  = 0;
    M2C_FIELD(arg0, s8 *, 0xA3)  = 0;
    M2C_FIELD(arg0, s8 *, 0x98)  = 3;
    M2C_FIELD(arg0, s16 *, 0xA6) = 1;
    temp_r3                      = M2C_FIELD(arg0, u8 *, 0x16B);
    M2C_FIELD(arg0, s8 *, 0xA1)  = (s8) (((((s32) (temp_r3 & 0x20) >> 5) + 1) * 6) + (((s32) (temp_r3 & 0x80) >> 7) * 3));
    temp_r3_2                    = M2C_FIELD(arg0, u8 *, 0x16B);
    func_020adad0((u16) (*((u16 *) ((s8 *) &data_02121fac + (M2C_FIELD(arg0, u8 *, 0xA) * 2))) +
                         ((s32) (temp_r3_2 & 0x80) >> 7) + ((s32) (temp_r3_2 & 0x20) >> 4)));
    func_020aa388(arg0);
}
