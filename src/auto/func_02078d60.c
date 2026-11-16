/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_02078de0(u8);
s8 func_020789d8(s32, s32, s32);
void func_02078c44(void);
s32 func_020c447c(void);
void func_021060a4(s32, s32, s32);
extern u8 data_0213b2b4[];
extern u8 data_0213b890[];

void func_02078d60(s32 arg0, s32 arg1, s32 arg2) {
    volatile s32 sp0;

    func_02078de0((u8) (arg1 & 0xF));
    sp0 = 0;
    func_021060a4(sp0, *(s32 *) (data_0213b2b4 + 0xC8), 0x5000);
    *(s8 *) (data_0213b890 + 0x91) = func_020789d8(arg0, arg1, arg2);
    *(s8 *) (data_0213b890 + 0x95) = 1;
    if (func_020c447c() == 0) {
        func_02078c44();
    }
}
