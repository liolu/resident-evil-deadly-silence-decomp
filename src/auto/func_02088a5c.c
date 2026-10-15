/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

M2C_UNK func_02091014(M2C_UNK, M2C_UNK, M2C_UNK);
void func_020a7e70(M2C_UNK, M2C_UNK, M2C_UNK);
void func_020a7f98(void);

extern M2C_UNK data_021375ac;
extern s32 data_027e000c;

void func_02088a5c(s32 arg0) {
    data_027e000c = arg0;
    func_020a7f98();
    M2C_FIELD(arg0, s8 *, 0xA) = 1;
    if (M2C_FIELD(M2C_FIELD(&data_021375ac, void **, 0x64), u8 *, 0x4C4) != 0) {
        func_020a7e70(arg0, 0x4E, 1);
    } else {
        func_020a7e70(arg0, 0x51, 1);
    }
    func_020a7f98();
    M2C_FIELD(arg0, s8 *, 0x98) = 0;
    func_02091014(0, 0x1000, 0);
}
