#include "m2c.h"
#include "engine.h"

void func_0208e6ac(void);

extern void *data_0213789c;
extern u16 data_0213ad84;

void func_0208d95c(void) {
    if (data_0213ad84 != 0) {
        return;
    }
    M2C_FIELD(data_0213789c, void (**)(), 0x24) = func_0208e6ac;
    M2C_FIELD(data_0213789c, s8 *, 4) = 0;
    M2C_FIELD(data_0213789c, s32 *, 0x28) = 0;
}
