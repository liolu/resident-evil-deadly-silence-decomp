/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

extern M2C_UNK data_0213bc6c;
extern u16 data_0213bd18;

s32 func_0209563c(s32 arg0) {
    if (data_0213bd18 & (1 << arg0)) {
        return (0x18 * arg0) + (s32) &data_0213bc6c;
    }
    return 0;
}
