/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s32 w0;
    s32 w1;
    s32 w2;
    s32 w3;
} Quad4;

s32 func_02084b48(void *, Quad4 *);
s32 func_0211851c(s32, M2C_UNK);
extern Quad4 data_0212d63c;

void func_0207dd50(void *arg0) {
    Quad4 loc;

    loc                                                = *(Quad4 *) &data_0212d63c;
    M2C_FIELD(arg0, s32 *, 0x1CC)                      = func_02084b48(arg0, &loc);
    M2C_FIELD(arg0, s32 *, 0x1CC)                      = func_0211851c(M2C_FIELD(arg0, s32 *, 0x1CC), 0x17);
    M2C_FIELD(arg0, s32 *, 0x1D0)                      = 0x22;
    M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x92) = (u8) (M2C_FIELD(M2C_FIELD(arg0, void **, 0), u8 *, 0x92) + 1);
}
