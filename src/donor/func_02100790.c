/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* UpdateBldcntBldalphaBldy from https://github.com/RonyxDumb/mkds src/arm9/0214a390_UpdateBldcntBldalphaBldy.c (license:
 * none), reused by tools/donor_match.py */
typedef unsigned short int u16;
typedef signed long s32;
typedef s32 fx32;
extern void func_02100790(u16 *ptr, fx32 a, fx32 b, fx32 c, fx32 d, fx32 brightness);
#pragma thumb off
#pragma thumb off
void func_02100790(u16 *ptr, fx32 a, fx32 b, fx32 c, fx32 d, fx32 brightness) {
    ptr[1] = (u16) (c | (d << 0x8));
    if (brightness < 0) {
        ptr[0] = (u16) (0xC0 | a | (b << 0x8));
        ptr[2] = (u16) (-brightness);
    } else {
        ptr[0] = (u16) (0x80 | a | (b << 0x8));
        ptr[2] = (u16) brightness;
    }
}
