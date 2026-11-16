/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
} Pair;

s32 func_0210960c(void *arg0, u32 arg1);
void func_02109838(u32 arg0);
void func_02109538(u32 arg0, Pair arg1);

void func_0200d308(u32 arg0, u32 arg1, Pair *arg2) {
    Pair loc;

    if (func_0210960c(arg2, arg0) != 0) {
        func_02109838(arg1);
        loc = *arg2;
        func_02109538(arg1, loc);
    }
}
