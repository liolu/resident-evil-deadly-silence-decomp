/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020af1e0(void);
void func_020b64d0(void);

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213af7c;

void func_020b91a0(void) {
    M2C_FIELD(&data_0213ad98, s8 *, 3) = 0x1F;
    func_020b64d0();
    M2C_FIELD(&data_0213af7c, s16 *, 0x1E) = 0xFF;
    func_020af1e0();
}
