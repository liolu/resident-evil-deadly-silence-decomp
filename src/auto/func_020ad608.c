/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ff8078(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_02018204(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK *, s32); /* extern */
M2C_UNK func_0209fc40(M2C_UNK, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_02121ff4;
extern M2C_UNK data_0212200c;
extern s32 data_0213aaec;
extern M2C_UNK data_0214ccc0;
extern M2C_UNK data_027e003c;
extern M2C_UNK data_027e0054;
extern M2C_UNK data_027e009c;
extern M2C_UNK data_027e0148;

void func_020ad608(M2C_UNK arg0) {
    s32 temp_r1;
    s32 temp_r5;

    if (!(data_0213aaec & 1)) {
        func_0209fc40(arg0, 1, &data_027e0148, &data_027e003c);
        func_01ff8078(&data_027e0148, &data_027e003c, &data_027e009c);
        if ((s32) M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), s32 *, 0x34) > (s32) (M2C_FIELD(&data_027e009c, s32 *, 0x18) + 0xFFFFFEA2)) {
            temp_r5 = (s32) data_0213aaec >> 1;
            M2C_FIELD(&data_027e0054, s32 *, 0) = (s32) (M2C_FIELD(&data_027e009c, s32 *, 0x14) + *((M2C_UNK *)((s8 *)&data_02121ff4 + (temp_r5 * 4))));
            M2C_FIELD(&data_027e0054, s32 *, 4) = (s32) M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), s32 *, 0x34);
            M2C_FIELD(&data_027e0054, s32 *, 8) = (s32) (M2C_FIELD(&data_027e009c, s32 *, 0x1C) + *((M2C_UNK *)((s8 *)&data_0212200c + (temp_r5 * 4))));
            func_02018204(0x17, 8, 0, 0, &data_027e0054, 0);
        }
    }
    temp_r1 = data_0213aaec + 1;
    data_0213aaec = temp_r1;
    if (temp_r1 >= 0xC) {
        data_0213aaec = 0;
    }
}
