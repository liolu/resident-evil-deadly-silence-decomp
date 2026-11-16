/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_0206fc08(void *);
void func_0206fcdc(void);
void func_020ff1bc(void *, s32);
extern M2C_UNK data_0213ad86;
extern M2C_UNK data_0213ad8e;

void func_0206fc74(void) {
    u8 *p;
    s32 v;

    p = (u8 *) &data_0213ad86;
    func_0206fc08(p);
    v = M2C_FIELD(p, u8 *, 7);
    if (M2C_FIELD(p, u8 *, 1) == 1) {
        v = 0 - v;
    }
    func_020ff1bc((void *) 0x0400006C, v);
    p = (u8 *) &data_0213ad8e;
    func_0206fc08(p);
    v = M2C_FIELD(p, u8 *, 7);
    if (M2C_FIELD(p, u8 *, 1) == 1) {
        v = 0 - v;
    }
    func_020ff1bc((void *) 0x0400106C, v);
    func_0206fcdc();
}
