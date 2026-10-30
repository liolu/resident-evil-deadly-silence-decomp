/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* OS_InitException from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/os/os_init_exception.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
typedef unsigned int u32;
typedef volatile u32 vu32;
extern u32 data_02158ae0;
extern u32 data_02158ae8;
extern void func_02104c40(void);
extern u32 func_021041b8(void);
void func_02104dc4(void) {
    u32 userHandler = (*(vu32 *) 0x027ffd9c);
    vu32 *dtcm      = (vu32 *) 0x27e3000;

    if (userHandler >= 0x02600000 && userHandler < 0x02800000) {
        data_02158ae8 = userHandler;
    } else {
        data_02158ae8 = 0;
    }
    if (data_02158ae8 == 0 || (func_021041b8() & 0x40000000) == 0) {
        (*(vu32 *) 0x027ffd9c) = (u32) func_02104c40;
        dtcm[0xfdc / 4]        = (u32) func_02104c40;
    }
    data_02158ae0 = 0;
}
