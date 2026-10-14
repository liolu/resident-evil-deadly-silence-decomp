/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020ebde0(void);

extern s32 data_0215411c;

void func_020e9e80(void) {
    s32 temp_r1;

    temp_r1 = data_0215411c - 1;
    data_0215411c = temp_r1;
    if (temp_r1 != 0) {
        return;
    }
    func_020ebde0();
}
