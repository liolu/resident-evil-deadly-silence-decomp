/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0214d964 from https://github.com/RonyxDumb/mkds src/arm9/0214d964_func_0214d964.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long u32;
typedef signed long s32;
#pragma thumb off
#pragma thumb off
#pragma thumb off
u32 func_0210b8f8(u32 bcd) {
    u32 hex = 0;
    s32 i;
    s32 w;

    for (i = 0; i < 8; i++) {
        if (((bcd >> (i * 4)) & 0x0000000f) >= 0x0a) {
            return hex;
        }
    }

    for (i = 0, w = 1; i < 8; i++, w *= 10) {
        hex += (((bcd >> (i * 4)) & 0x0000000f) * w);
    }

    return hex;
}
