/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0211d888[];
extern u8 data_0213adbc[];
void func_02070088(void *arg0, u8 arg1, s32 arg2, u8 arg3);

void func_020700d8(s32 arg0, s32 arg1) {
    func_02070088(data_0213adbc, arg0 & 0xFF, arg1, data_0211d888[arg0]);
}
