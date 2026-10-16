/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed long s32;
extern u32 func_020ff7ac();
extern void func_02102534();
extern u32 data_02158808;
extern u32 data_0215881c;
extern u32 data_02158818;
extern s32 data_02158814;
extern const struct {
    u16 blk1;
    u16 blk2;
    u16 szBlk1;
} data_0212bd08[16];

/* func_0214c6a8 from https://github.com/RonyxDumb/mkds src/arm9/0214c6a8_func_0214c6a8.c (license: none), reused by
 * tools/donor_match.py */
void func_02102534() {
    u32 temp      = func_020ff7ac();
    data_02158814 = (s32) temp;
    data_02158808 = (u32) (data_0212bd08[temp].blk1 << 0xC);
    data_02158818 = (u32) (data_0212bd08[temp].blk2 << 0xC);
    data_0215881c = (u32) (data_0212bd08[temp].szBlk1 << 0xC);
}
