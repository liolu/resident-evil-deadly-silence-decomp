/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02098248(void);
void func_020985cc(void);

extern void *data_02137ed8;

void func_02098fec(void) {
    if (((u32) (M2C_FIELD(data_02137ed8, u8 *, 0x24AF) << 0x1D) >> 0x1F) == 0) {
        func_02098248();
        M2C_FIELD(data_02137ed8, u8 *, 0x24AF) = (u8) (M2C_FIELD(data_02137ed8, u8 *, 0x24AF) | 4);
    }
    func_020985cc();
}
