/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020038b8(M2C_UNK);
M2C_UNK func_02005fcc(M2C_UNK);
void func_0200f6e0(M2C_UNK);
void func_0200f768(M2C_UNK);
void func_0200f7f0(M2C_UNK);
void func_0200f884(void);
void func_0200fa98(void);
void func_0200fae8(void);
void func_020ff204(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_02120c1c;
extern M2C_UNK data_02120c2c;

void func_0209f870(void) {
    func_0200fae8();
    func_0200fa98();
    func_0200f884();
    func_020ff204(1, 0, 0);
    *(u16 *)0x04000304 &= ~0x8000;
    func_0200f7f0(8);
    func_0200f768(0xC);
    func_0200f6e0(2);
    *(s32 *)0x04000000 = (*(s32 *)0x04000000 & ~0x1F00) | 0x1000;
    *(s32 *)0x04001000 = (*(s32 *)0x04001000 & ~0x1F00) | 0x1000;
    func_020038b8((s32) &data_02120c1c);
    func_02005fcc((s32) &data_02120c2c);
}
