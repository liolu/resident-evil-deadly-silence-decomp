/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0200b82c from projets/code-lyoko/src/donor/func_0200b82c.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef int s32;
typedef s32 BOOL;
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
extern void func_02105d20(void *arg);
static inline void UnkCallCallback(UnkDmaCallback callback, void *arg) {
    if (callback) {
        callback(arg);
    }
}
void func_02105d20(void *arg) {
    data_02158bc0.isBusy = 0;
    UnkCallCallback(data_02158bc0.callback, data_02158bc0.arg);
}
