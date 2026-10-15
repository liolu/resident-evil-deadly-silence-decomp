/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_01ff87b4(M2C_UNK, M2C_UNK);
M2C_UNK func_020b39e4(M2C_UNK, M2C_UNK);
void func_020b5550(void);
void func_020b5698(M2C_UNK);

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213be20;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_0213e324;
extern M2C_UNK data_02143cc0;
extern M2C_UNK data_02144bc0;
extern M2C_UNK data_02144c46;
extern M2C_UNK data_0214d0c0;
extern M2C_UNK data_0214e5c0;

void func_020b5728(s32 arg0) {
    func_01ff87b4((s32) &data_02144c46, (s32) &data_0213e324);
    M2C_FIELD(&data_0213daa8, s32 *, 0x890) = (s32) M2C_FIELD(&data_02143cc0, s32 *, 0xF74);
    M2C_FIELD(&data_0213daa8, s32 *, 0x894) = (s32) M2C_FIELD(&data_02143cc0, s32 *, 0xF78);
    M2C_FIELD(&data_0213daa8, s32 *, 0x898) = (s32) M2C_FIELD(&data_02143cc0, s32 *, 0xF7C);
    if ((M2C_FIELD(&data_0213daa8, u16 *, 0x74) & 0x101) == 0x101) {
        func_020b5550();
        if ((s32) M2C_FIELD(&data_02144bc0, s16 *, 0xD8) < 0) {
            M2C_FIELD(&data_0213ad98, u16 *, 0x20) = (u16) (M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 3);
            M2C_FIELD(&data_0213ad98, u16 *, 0x22) = (u16) (M2C_FIELD(&data_0213ad98, u16 *, 0x22) & 3);
            M2C_FIELD(&data_0213b890, s8 *, 3)     = 4;
        }
    }
    if (func_020b39e4((s32) &data_0213be20, 0x3E) != 0) {
        M2C_FIELD(&data_0214d0c0, u16 *, 0x3C) = (u16) M2C_FIELD(&data_0214e5c0, u16 *, 0x76);
    }
    func_020b5698(arg0);
}
