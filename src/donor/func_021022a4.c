/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0200736c from projets/code-lyoko/src/donor/func_0200736c.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned long u32;
extern void func_021060b8(register const void *srcp, register void *destp, register u32 size);
typedef void (*MIDmaCallback)(void *);
extern void func_02105a1c(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void func_021022a4(void *src, u32 offset, u32 size);
static inline void GXi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg) {
    if (dmaNo != -1) {
        func_02105a1c(dmaNo, src, dest, size, callback, arg);
    } else {
        func_021060b8(src, dest, size);
    }
}
extern u32 data_0215880c;
extern u32 data_02136b8c;
#pragma thumb off
void func_021022a4(void *src, u32 offset, u32 size) {
    GXi_DmaCopy32Async(data_02136b8c, src, (void *) (data_0215880c + offset), size, ((void *) 0), ((void *) 0));
}
