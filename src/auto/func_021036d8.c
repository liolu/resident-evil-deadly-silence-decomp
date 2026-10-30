/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* OS_SNPrintf from https://github.com/RonyxDumb/mkds src/arm9/0200d118_Util_VSNPrintF.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long u32;
typedef signed char s8;
typedef signed long s32;
extern s32 func_021036d8(s8 *buffer, s32 bufsz, const s8 *format, ...);
extern s32 func_02102e10(s8 *buffer, s32 bufsz, const s8 *format, void *args);
s32 func_021036d8(s8 *buffer, s32 bufsz, const s8 *format, ...) {
    void *args = (void *) ((u32 *) ((u32) &format & ~0x3) + 1);
    return func_02102e10(buffer, bufsz, format, args);
}
s32 func_02102e10(s8 *buffer, s32 bufsz, const s8 *format, void *args);
