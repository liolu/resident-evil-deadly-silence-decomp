/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0200d5bc from projets/code-lyoko/src/donor/func_0200d5bc.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef int s32;
typedef volatile u32 vu32;
typedef volatile u16 vu16;
typedef s32 BOOL;
extern u32 func_021054ac(void);
extern u32 func_021054c0(u32 state);
extern s32 func_02107c3c(u32 tag, u32 data, BOOL err);
typedef union UnkPxiFifoMessage {
    struct {
        u32 tag : 5;
        u32 err : 1;
        u32 data : 26;
    } e;
    u32 raw;
} UnkPxiFifoMessage;
static inline s32 PxiSetToFifo(u32 data) {
    u32 enabled;

    if ((*(vu16 *) 0x04000184) & 0x4000) {
        (*(vu16 *) 0x04000184) |= 0xc000;
        return -1;
    }
    enabled = func_021054ac();
    if ((*(vu16 *) 0x04000184) & 2) {
        func_021054c0(enabled);
        return -2;
    }
    (*(vu32 *) 0x04000188) = data;
    func_021054c0(enabled);
    return 0;
}
s32 func_02107c3c(u32 tag, u32 data, BOOL err) {
    UnkPxiFifoMessage msg;

    msg.e.tag  = tag;
    msg.e.err  = err;
    msg.e.data = data;
    return PxiSetToFifo(msg.raw);
}
