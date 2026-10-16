/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207bfe4 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/spi/pm.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef s32 BOOL;
typedef void (*UnkPmCallback)(u32 result, void *arg);
extern u32 data_0215a890;
extern u32 func_0210b358(u32 type, UnkPmCallback callback, void *arg);
extern u32 func_0210b31c(u32 type);
extern BOOL func_0210adb4(u32 sw, u32 backLight, BOOL skipWait, BOOL isSync);
u32 func_0210b358(u32 type, UnkPmCallback callback, void *arg);
u32 func_0210b31c(u32 type);
BOOL func_0210adb4(u32 sw, u32 backLight, BOOL skipWait, BOOL isSync) {
    switch (sw) {
        case 1:
            if (!skipWait) {
                if ((u32) ((*(vu32 *) 0x027ffc3c) - data_0215a890) <= 7) {
                    return 0;
                }
            }
            if (backLight) {
                if (isSync) {
                    func_0210b31c(backLight);
                } else {
                    func_0210b358(backLight, 0, 0);
                }
            }
            (*(vu16 *) 0x04000304) |= 1;
            break;
        case 0:
            (*(vu16 *) 0x04000304) &= ~1;
            data_0215a890 = (*(vu32 *) 0x027ffc3c);
            if (backLight) {
                if (isSync) {
                    func_0210b31c(backLight);
                } else {
                    func_0210b358(backLight, 0, 0);
                }
            }
            break;
    }
    return 1;
}
