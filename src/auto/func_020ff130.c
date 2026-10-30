/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02063920 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/gx/gx.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
extern u32 data_02136b8c;
extern void func_021059ac(u32 dmaNo);
extern u32 data_02136b8c;
u32 func_020ff130(u32 dmaNo) {
    u32 prev = data_02136b8c;
    u32 e;
    if (prev != -1) {
        func_021059ac(prev);
    }
    e             = func_021054ac();
    data_02136b8c = dmaNo;
    func_021054c0(e);
    return prev;
}
