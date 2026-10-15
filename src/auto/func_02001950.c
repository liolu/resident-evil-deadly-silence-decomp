/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_01ff8078(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
M2C_UNK func_02018204(u8, u8, s32, M2C_UNK *, M2C_UNK *, s32); /* extern */
M2C_UNK func_0209fc40(void *, M2C_UNK, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_027e003c;
extern M2C_UNK data_027e0054;
extern M2C_UNK data_027e009c;
extern M2C_UNK data_027e0148;

void func_02001950(void *arg0, void *arg1) {
    func_0209fc40(arg1, 0, &data_027e0148, &data_027e003c);
    func_01ff8078(&data_027e0148, &data_027e003c, &data_027e009c);
    func_02018204(3U, 8U, (M2C_FIELD(&data_02144bc0, s16 *, 0x88) - M2C_FIELD(arg1, s16 *, 0x44)) + 0x800, &data_027e009c,
                  &data_027e0054, 0);
    func_02018204(M2C_FIELD(arg0, u8 *, 5), M2C_FIELD(arg0, u8 *, 6),
                  (M2C_FIELD(&data_02144bc0, s16 *, 0x88) - M2C_FIELD(arg1, s16 *, 0x44)) + 0x800, &data_027e009c,
                  &data_027e0054, 0);
}
