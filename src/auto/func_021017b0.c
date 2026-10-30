/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0214b720 from https://github.com/RonyxDumb/mkds src/arm9/0214b720_func_0214b720.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long u32;
typedef signed long s32;
extern u32 func_020ff7c0();
extern void func_021017b0();
extern s32 data_02158804;
extern u32 data_02158800;
extern u32 data_021587fc;
#pragma thumb off
void func_021017b0() {
    data_02158804 = (s32) func_020ff7c0();
    switch (data_02158804) {
        case 0:
            break;
        case 0x10:
            data_02158800 = 0x06880000;
            data_021587fc = 0x0;
            break;
        case 0x40:
            data_02158800 = 0x06894000;
            data_021587fc = 0x4000;
            break;
        case 0x20:
        case 0x60:
            data_02158800 = 0x06890000;
            data_021587fc = 0x0;
            break;
    }
}
