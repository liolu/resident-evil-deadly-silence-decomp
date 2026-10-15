/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02105528(void);
void func_0210b1fc(void);
void func_0210d300(M2C_UNK, M2C_UNK);

void func_0210d364(void) {
    if (((s32) (*(u16 *) 0x027FFFA8 & 0x8000) >> 0xF) != 0) {
        func_0210b1fc();
    }
    func_0210d300(1, 1);
    func_02105528();
}
