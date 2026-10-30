/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* OS_SPrintf from https://github.com/RonyxDumb/mkds src/arm9/0200d118_Util_VSNPrintF.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long u32;
typedef signed char s8;
typedef signed long s32;
extern s32 func_02103720(s8 *buffer, const s8 *format, ...);
extern s32 func_02103708(s8 *buffer, const s8 *format, void *args);
s32 func_02103720(s8 *buffer, const s8 *format, ...) {
    void *args = (void *) ((u32 *) ((u32) &format & ~0x3) + 1);
    return func_02103708(buffer, format, args);
}
s32 func_02103708(s8 *buffer, const s8 *format, void *args);
