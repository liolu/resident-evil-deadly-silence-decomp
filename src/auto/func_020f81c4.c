/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020f4d6c(void);
void func_02100e08(void);

void func_020f81c4(void) {
    func_02100e08();
    func_020f4d6c();
    *(s32 *) 0x04000600 = (*(s32 *) 0x04000600 & ~0xC0000000) | 0x80000000;
}
