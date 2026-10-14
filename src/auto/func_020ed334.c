/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_020ed194(M2C_UNK);
void func_020ed1ac(M2C_UNK);
void func_020ed248(M2C_UNK);

void func_020ed334(s32 arg0) {
    s32 temp_r0;

    temp_r0 = func_020ed194(arg0 + 8);
    switch (temp_r0) {                              /* irregular */
    case 1:
        func_020ed1ac(arg0);
        return;
    case 2:
        func_020ed248(arg0);
        return;
    }
}
