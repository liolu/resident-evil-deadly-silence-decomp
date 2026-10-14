/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020af574(void);
void func_020b1230(void);
void func_020b1764(void);

extern M2C_UNK data_0213b890;

void func_020b192c(void) {
    func_020b1764();
    M2C_FIELD(&data_0213b890, void (**)(), 0x44) = func_020af574;
    func_020b1230();
}
