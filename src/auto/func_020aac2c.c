/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02094c10();                            /* extern */
M2C_UNK func_020aa59c(void *);                      /* extern */
M2C_UNK func_020ac214(M2C_UNK);                     /* extern */
M2C_UNK func_020adad0(u16);                         /* extern */
extern M2C_UNK data_02121fac;
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bdcc;

void func_020aac2c(void *arg0) {
    u8 temp_ip;
    u8 temp_r3;

    M2C_FIELD(arg0, s8 *, 0x93)  = 1;
    M2C_FIELD(arg0, s8 *, 0x98)  = 3;
    M2C_FIELD(arg0, s16 *, 0xA6) = 1;
    temp_ip                      = M2C_FIELD(arg0, u8 *, 0x16B);
    M2C_FIELD(arg0, s8 *, 0xA1)  = (s8) (((((s32) (temp_ip & 0x20) >> 5) + 1) * 6) + (((s32) (temp_ip & 0x80) >> 7) * 3));
    temp_r3                      = M2C_FIELD(arg0, u8 *, 0x16B);
    func_020adad0((u16) (*((u16 *) ((s8 *) &data_02121fac + (M2C_FIELD(arg0, u8 *, 0xA) * 2))) +
                         ((s32) (temp_r3 & 0x80) >> 7) + ((s32) (temp_r3 & 0x20) >> 4)));
    if (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 1) {
        func_020ac214(1);
    }
    M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) = (s32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) & ~0x400000);
    func_02094c10();
    func_020aa59c(arg0);
}
