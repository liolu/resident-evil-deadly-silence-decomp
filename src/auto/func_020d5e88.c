#include "m2c.h"
typedef struct {
    u8 pad[0x18];
} Rec;
extern Rec data_021268bc[];
extern u8 data_0213ad48[];
void func_02005fcc(s32);

void func_020d5e88(s32 arg0) {
    s32 *tbl = (s32 *) (data_021268bc + arg0);
    func_02005fcc(tbl[data_0213ad48[3]]);
}
