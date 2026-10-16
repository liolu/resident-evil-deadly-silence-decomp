/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
extern u32 func_021054ac(void);
extern u32 func_021054c0(u32 state);
extern u32 data_02158ba8;
extern u16 data_02158bac[9];
u32 func_02105730(register u32 value);

/* func_02079f00 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/os/os_vramexclusive.c (license: none),
 * reused by tools/donor_match.py */
void func_02105738(u32 bank, u16 lockID) {
    u32 mask;
    u32 enabled = func_021054ac();

    mask = bank & data_02158ba8 & 0x1ff;

    while (1) {
        s32 i = 31 - func_02105730(mask);
        if (i < 0) {
            break;
        }
        mask &= ~(1 << i);
        if (data_02158bac[i] == lockID) {
            data_02158bac[i] = 0;
            data_02158ba8 &= ~(1 << i);
        }
    }
    func_021054c0(enabled);
}
