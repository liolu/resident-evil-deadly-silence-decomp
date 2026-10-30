/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207ccb0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/wm/wm_system.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned short u16;
extern void func_0210d458(void);
void func_0210d458(void) {
    u16 *flag = &(*(u16 *) 0x027fff96);

    if (*flag & 1) {
        *flag &= ~1;
    }
}
