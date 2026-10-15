/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_020fd1ec();                      /* extern */
M2C_UNK func_020fd920();                      /* extern */
M2C_UNK func_02104520();                   /* extern */
M2C_UNK func_02104590();                   /* extern */
extern s32 data_02157d5c;
extern M2C_UNK data_02158204;

void func_020fd994(void *arg0) {
    func_02104590(&data_02158204);
    if (data_02157d5c != 0) {
        func_02104590(data_02157d5c + 0x498);
    }
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x10C) << 0x1E) >> 0x1F) != 0) {
        func_020fd1ec(arg0);
    }
    if (((s32) (M2C_FIELD(arg0, s32 *, 0x10C) << 0x1F) >> 0x1F) != 0) {
        M2C_FIELD(arg0, M2C_UNK(**)(void *), 0x168)(arg0);
    }
    func_020fd920(arg0);
    func_02104520(&data_02158204);
    if (data_02157d5c == 0) {
        return;
    }
    func_02104520(data_02157d5c + 0x498);
}
