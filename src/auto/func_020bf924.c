/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK func_02091d4c(s32, void *, M2C_UNK, s32);
extern M2C_UNK func_020bf8b8(M2C_UNK);
extern u8 data_02124cf8[];
extern u8 data_0213b890[];
extern u8 data_0213f7e8[];

void func_020bf924(s32 arg0, u8 *arg1) {
    s32 idx;
    u8 k;
    u16 w;

    func_020bf8b8(0);
    idx = arg0 * 6 + *(s32 *) (data_0213b890 + 0x4C);
    k   = arg1[idx];
    w   = *(u16 *) (data_02124cf8 + k * 12);
    func_02091d4c(w | 0xE900, data_0213f7e8, 0x40, 0x01003100);
}
