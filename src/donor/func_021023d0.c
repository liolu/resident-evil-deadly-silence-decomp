/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02008358 from projets/code-lyoko/src/donor/func_02008358.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned long u32;
extern void func_021060b8(register const void *srcp, register void *destp, register u32 size);
typedef void (*MIDmaCallback)(void *);
extern void func_02105c14(u32 dmaNo, const void *src, void *dest, u32 size);
extern void func_02105a1c(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg);
extern void func_021023d0(void *src, u32 offset, u32 size);
static inline void GXi_DmaCopy32(u32 dmaNo, const void *src, void *dest, u32 size) {
    if (dmaNo != -1 && size > 0x30) {
        func_02105c14(dmaNo, src, dest, size);
    } else {
        func_021060b8(src, dest, size);
    }
}
static inline void GXi_DmaCopy32Async(u32 dmaNo, const void *src, void *dest, u32 size, MIDmaCallback callback, void *arg) {
    if (dmaNo != -1) {
        func_02105a1c(dmaNo, src, dest, size, callback, arg);
    } else {
        func_021060b8(src, dest, size);
    }
}
extern u32 data_02158818;
extern u32 data_02158808;
extern u32 data_0215881c;
extern u32 data_02136b8c;
#pragma thumb off
void func_021023d0(void *src, u32 offset, u32 size) {
    void *temp;
    if (!data_02158818) {
        temp = (void *) (data_02158808 + offset);
    } else {
        if ((offset + size) < data_0215881c) {
            temp = (void *) (data_02158808 + offset);
        } else if (offset >= data_0215881c) {
            temp = (void *) (data_02158818 + offset - data_0215881c);
        } else {
            void *temp2 = (void *) data_02158818;
            u32 temp1   = data_0215881c - offset;
            temp        = (void *) (data_02158808 + offset);
            GXi_DmaCopy32(data_02136b8c, src, temp, temp1);
            GXi_DmaCopy32Async(data_02136b8c, (void *) ((u8 *) src + temp1), temp2, (size - temp1), ((void *) 0),
                               ((void *) 0));
            return;
        }
    }
    GXi_DmaCopy32Async(data_02136b8c, src, temp, size, ((void *) 0), ((void *) 0));
}
