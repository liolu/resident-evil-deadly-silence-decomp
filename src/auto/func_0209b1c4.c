/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0209fb40(void);
void func_020b7db8(void);
void func_020b8374(void);
void func_020b84ec(void);
void func_020d69c0(void);
void func_020d914c(void);

extern M2C_UNK data_0213b2b4;
extern M2C_UNK data_0213caa0;

void func_0209b1c4(void) {
    func_020d914c();
    func_020b84ec();
    func_020b8374();
    func_020b7db8();
    if (M2C_FIELD(&data_0213caa0, u8 *, 0x71A) != 0) {
        M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_020d69c0;
        return;
    }
    M2C_FIELD(&data_0213b2b4, void (**)(), 0xA8) = func_0209fb40;
}
