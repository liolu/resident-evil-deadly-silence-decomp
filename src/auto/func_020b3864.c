/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02095090(M2C_UNK);
void func_02095104(M2C_UNK);
void func_02095874(M2C_UNK);
M2C_UNK func_020b39e4(M2C_UNK, M2C_UNK);
void func_020b3a24(M2C_UNK, M2C_UNK);
M2C_UNK func_0211851c(M2C_UNK, M2C_UNK);

extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213bb18;
extern M2C_UNK data_0213bd20;
extern M2C_UNK data_0213be30;

void func_020b3864(s32 arg0) {
    s32 temp_r0;
    s32 temp_r0_2;
    s32 temp_r6;
    s32 temp_r6_2;
    s32 temp_r6_3;
    u16 temp_r1;
    u16 temp_r4;

    if ((M2C_FIELD(&data_0213ad48, u8 *, 4) != 0) && ((func_020b39e4((s32) &data_0213be30, (s32) M2C_FIELD(arg0, u16 *, 0x172)) == 0) || (M2C_FIELD(arg0, u16 *, 0x172) == 0xFF))) {
        temp_r1 = M2C_FIELD(arg0, u16 *, 0x172);
        if (((u32) temp_r1 >= 0x40U) && (temp_r1 != 0xFF)) {
            if (((u32) (M2C_FIELD(&data_0213bb18, s32 *, 0x1FC) << 0x1E) >> 0x1F) == 1) {
                func_02095104((s32) (u8) temp_r1);
            }
            temp_r4 = M2C_FIELD(arg0, u16 *, 0x172);
            if ((u32) temp_r4 < 0x80U) {
                temp_r6 = temp_r4 - 0x40;
                if (!((1 << (temp_r6 & 0x1F)) & *((M2C_UNK *)((s8 *)&data_0213bd20 + (func_0211851c(temp_r6, 0x20) * 4))))) {
                    if ((u32) temp_r4 >= 0x60U) {
                        if (M2C_FIELD(arg0, u8 *, 0x169) & 2) {
                            func_02095090(2);
                            temp_r6_2 = M2C_FIELD(arg0, u16 *, 0x172) - 0x40;
                            temp_r0 = func_0211851c(temp_r6_2, 0x20);
                            *((M2C_UNK *)((s8 *)&data_0213bd20 + (temp_r0 * 4))) = *((M2C_UNK *)((s8 *)&data_0213bd20 + (temp_r0 * 4))) | (1 << (temp_r6_2 & 0x1F));
                        }
                    } else if (((u32) temp_r4 >= 0x40U) && (M2C_FIELD(arg0, u8 *, 0x169) & 4)) {
                        func_02095090(1);
                        temp_r6_3 = M2C_FIELD(arg0, u16 *, 0x172) - 0x40;
                        temp_r0_2 = func_0211851c(temp_r6_3, 0x20);
                        *((M2C_UNK *)((s8 *)&data_0213bd20 + (temp_r0_2 * 4))) = *((M2C_UNK *)((s8 *)&data_0213bd20 + (temp_r0_2 * 4))) | (1 << (temp_r6_3 & 0x1F));
                    }
                }
            }
        }
        func_02095874(arg0);
    }
    func_020b3a24((s32) &data_0213be30, (s32) M2C_FIELD(arg0, u16 *, 0x172));
}
