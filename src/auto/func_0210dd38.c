/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207d100 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/wm/wm_system.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef volatile u32 vu32;
u16 func_0210dd38(void) {
    u8 mac[6];
    u16 sum;
    s32 i;

    func_02105714(mac);
    for (i = 0, sum = 0; i < 6; i++) {
        sum += mac[i];
    }
    sum += *(vu32 *) 0x027ffc3c;
    sum *= 13;
    return (u16) (30 + (sum % 10));
}
