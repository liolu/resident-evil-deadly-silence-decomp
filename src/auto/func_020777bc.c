/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020aff50(void);
void func_020b1d58(void);

extern u16 data_0213ad30;
extern u16 data_0213ad84;
extern M2C_UNK data_0213b2b4;

void func_020777bc(void) {
    M2C_FIELD(&data_0213b2b4, s8 *, 9) = 0;
    M2C_FIELD(&data_0213b2b4, s8 *, 0) = 1;
    if (data_0213ad84 != 0) {
        return;
    }
    if ((data_0213ad30 & 0x720) == 0x720) {
        M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_020aff50;
        return;
    }
    M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_020b1d58;
}
