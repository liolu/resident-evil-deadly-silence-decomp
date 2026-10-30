/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0200ba68 from projets/code-lyoko/src/donor/func_0200ba68.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef int s32;
typedef volatile u32 vu32;
typedef s32 BOOL;
extern void func_021059ac(u32 dmaNo);
typedef void (*UnkDmaCallback)(void *arg);
typedef void (*UnkIrqHandler)(void);
typedef struct {
    volatile BOOL isBusy;
    u32 dmaNo;
    u32 src;
    u32 size;
    UnkDmaCallback callback;
    void *arg;
    u32 fifoCond;
    UnkIrqHandler fifoIntrHandler;
} UnkGxCmdDmaState;
extern UnkGxCmdDmaState data_02158bc0;
extern void func_021029a0(u32 mask, UnkIrqHandler handler);
extern UnkIrqHandler func_02102914(u32 mask);
extern void func_02102810(u32 mask);
extern void func_02105804(u32 dmaNo, u32 src, u32 size, u32 dir);
extern void func_02105e94(void);
static inline void UnkCallCallback(UnkDmaCallback callback, void *arg) {
    if (callback) {
        callback(arg);
    }
}
void func_02105f5c(u32 dmaNo, const void *src, u32 size, UnkDmaCallback callback, void *arg) {
    u32 e;

    if (size == 0) {
        UnkCallCallback(callback, arg);
        return;
    }
    while (data_02158bc0.isBusy) {
    }
    while (!((((*(vu32 *) 0x04000600) & 0x7000000) >> 24) & 2)) {
    }
    data_02158bc0.isBusy   = 1;
    data_02158bc0.dmaNo    = dmaNo;
    data_02158bc0.src      = (u32) src;
    data_02158bc0.size     = size;
    data_02158bc0.callback = callback;
    data_02158bc0.arg      = arg;
    func_02105804(dmaNo, (u32) src, size, 0);
    func_021059ac(dmaNo);

    e                             = func_021054ac();
    data_02158bc0.fifoCond        = ((*(vu32 *) 0x04000600) & 0xc0000000) >> 30;
    data_02158bc0.fifoIntrHandler = func_02102914(0x200000);
    (*(vu32 *) 0x04000600)        = ((*(vu32 *) 0x04000600) & ~0xc0000000) | 0x40000000;
    func_021029a0(0x200000, func_02105e94);
    func_02102810(0x200000);
    func_02105e94();
    func_021054c0(e);
}
extern void func_02105e94(void);
