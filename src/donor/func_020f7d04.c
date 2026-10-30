/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02077a28 from projets/nintendogs-dachshund/src/donor/func_02077a28.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned long u32;
typedef volatile u32 vu32;
typedef vu32 REGType32v;
extern void func_021060d0(const void *srcp, volatile void *destp, u32 size);
static inline void MI_CpuSend32(const void *src, volatile void *dest, u32 size) {
    ((void) 0);
    ((void) 0);
    ((void) 0);

    func_021060d0(src, dest, size);
}
typedef struct NNSG3dGeBuffer_ {
    u32 idx;
    u32 data[192];
} NNSG3dGeBuffer;
extern void func_020f7cec(void);
extern void func_020f7d04(void);
extern volatile int data_02157310;
extern NNSG3dGeBuffer *data_0215730c;
static inline void sendNB(const void *src, void *dst, u32 szByte) {
    MI_CpuSend32(src, dst, szByte);
}
void func_020f7d04(void) {
    if (data_02157310) {
        func_020f7cec();
    }

    if (data_0215730c && data_0215730c->idx > 0) {
        sendNB(&data_0215730c->data[0], (void *) &(*(REGType32v *) (0x04000000 + 0x400)), data_0215730c->idx << 2);
        data_0215730c->idx = 0;
    }
}
extern void func_020f7cec(void);
