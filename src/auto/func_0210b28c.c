/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207bbb4 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/spi/pm.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef void (*UnkPmCallback)(u32 result, void *arg);
extern u32 func_0210b530(u32 data, UnkPmCallback callback, void *arg);
u32 func_0210b530(u32 data, UnkPmCallback callback, void *arg);
u32 func_0210b28c(u32 target, u32 on, UnkPmCallback callback, void *arg) {
    u32 command = 0;

    if (target == 0) {
        if (on == 1) {
            command = 6;
        }
        if (on == 0) {
            command = 7;
        }
    } else if (target == 1) {
        if (on == 1) {
            command = 4;
        }
        if (on == 0) {
            command = 5;
        }
    } else if (target == 2) {
        if (on == 1) {
            command = 8;
        }
        if (on == 0) {
            command = 9;
        }
    }
    if (command == 0) {
        return 0xffff;
    }
    return func_0210b530(command, callback, arg);
}
