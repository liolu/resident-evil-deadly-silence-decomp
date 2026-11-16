/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_020063d0(s32);
void func_020c3b9c(void *);
s32 func_020c447c(void);
void func_020c44c4(s32, s32, s32);
void func_021060a4(s32, void *, s32);
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8e0;
extern void func_020c2b4c(void);
extern void func_020c3258(void);

void func_020c32b4(s32 arg0) {
    volatile s32 sp0;

    if ((arg0 == 0) || (arg0 != 1) || (func_020c447c() != 0)) {
        func_020063d0(1);
        func_020c3b9c(&data_0213b8e0);
        sp0 = 0;
        func_021060a4(sp0, &data_0213b8e0, 0x34);
        M2C_FIELD(&data_0213b890, s32 *, 0x60) = arg0;
        M2C_FIELD(&data_0213b890, s32 *, 0x74) = (s32) func_020c3258;
        func_020c44c4((s32) func_020c3258, (s32) func_020c2b4c, 0);
    }
}
