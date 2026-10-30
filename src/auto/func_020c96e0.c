/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_020c8da8();                              /* extern */
extern M2C_UNK data_0213b890;

void *func_020c96e0(void) {
    s32 var_r0;
    void *temp_ip;
    void *temp_r0;
    void *temp_r3;

    temp_r3 = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
    var_r0  = M2C_FIELD(temp_r3, u16 *, 0x2C) & 0x3FFF;
    if (var_r0 == 0) {
        M2C_FIELD(temp_r3, s16 *, 0x14) = (s16) (M2C_FIELD(temp_r3, s16 *, 0x14) - 1);
        temp_ip                         = M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
        if (M2C_FIELD(temp_ip, s16 *, 0x14) == 0) {
            M2C_FIELD(temp_ip, u8 *, 2) = (u8) (M2C_FIELD(temp_ip, u8 *, 2) + 1);
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s16 *, 0x14) = 3;
            M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s16 *, 0x16) = 0;
            temp_r0                                                                                     = func_020c8da8();
            M2C_FIELD(temp_r0, s8 *, 1)                                                                 = 2;
            M2C_FIELD(temp_r0, s32 *, 8) =
                (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s32 *, 8);
            M2C_FIELD(temp_r0, s32 *, 0xC) =
                (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s32 *, 0xC);
            M2C_FIELD(temp_r0, u16 *, 0x2C) =
                (u16) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), u16 *, 0x2C);
            M2C_FIELD(temp_r0, void **, 0x18) = (void *) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
            return temp_r0;
        }
        var_r0                     = (s32) func_020c8da8();
        M2C_FIELD(var_r0, s8 *, 1) = 1;
        M2C_FIELD(var_r0, s32 *, 8) =
            (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s32 *, 8);
        M2C_FIELD(var_r0, s32 *, 0xC) =
            (s32) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), s32 *, 0xC);
        M2C_FIELD(var_r0, u16 *, 0x2C) =
            (u16) M2C_FIELD(M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8), u16 *, 0x2C);
        M2C_FIELD(var_r0, void **, 0x18) = (void *) M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), void **, 0x2F8);
        /* Duplicate return node #4. Try simplifying control flow for better match */
        return (void *) var_r0;
    }
    return (void *) var_r0;
}
