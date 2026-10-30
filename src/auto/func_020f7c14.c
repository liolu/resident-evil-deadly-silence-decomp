/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* NNS_G3dGeSendDL from https://github.com/RonyxDumb/mkds src/arm9/01ff9048_func_01ff9048.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long u32;
typedef int BOOL;
extern u32 data_02136b8c;
typedef void (*MIDmaCallback)(void *);
extern void func_02105f5c(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
extern void func_02105d60(u32 dmaNo, const void *src, u32 commandLength, MIDmaCallback callback, void *arg);
extern void func_020f7d04(void);
extern void func_020f7c14(const void *src, u32 szByte);
extern void func_020f7b18(u32 op, const u32 *args, u32 num);
extern volatile int data_02157310;
void func_020f7d04(void);
void func_020f7ce0(void *arg);
extern BOOL data_02157314;
void func_020f7c14(const void *src, u32 szByte) {
    ((void) 0);
    ((void) 0);

    if (szByte < 256 || (data_02136b8c) == ((u32) ~0)) {
        func_020f7b18(*(const u32 *) src, (const u32 *) src + 1, (szByte >> 2) - 1);
    } else {
        func_020f7d04();
        data_02157310 = 1;

        if (data_02157314) {
            func_02105d60((data_02136b8c), src, szByte, &func_020f7ce0, (void *) &data_02157310);
        } else {
            func_02105f5c((data_02136b8c), src, szByte, &func_020f7ce0, (void *) &data_02157310);
        }
    }
}
void func_020f7b18(u32 op, const u32 *args, u32 num);
