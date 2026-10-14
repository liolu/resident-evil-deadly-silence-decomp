/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02104800(M2C_UNK, M2C_UNK);
void func_02104814(M2C_UNK, M2C_UNK);
M2C_UNK func_02104828(M2C_UNK);
M2C_UNK func_02104910(M2C_UNK);

extern s32 data_02158ad8;

void func_02104ae4(void) {
    if (data_02158ad8 != 0) {
        return;
    }
    data_02158ad8 = 1;
    func_02104814(0, func_02104910(0));
    func_02104800(0, func_02104828(0));
    func_02104800(2, 0);
    func_02104814(2, 0);
    func_02104814(3, func_02104910(3));
    func_02104800(3, func_02104828(3));
    func_02104814(4, func_02104910(4));
    func_02104800(4, func_02104828(4));
    func_02104814(5, func_02104910(5));
    func_02104800(5, func_02104828(5));
    func_02104814(6, func_02104910(6));
    func_02104800(6, func_02104828(6));
}
