/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* GXx_GetMasterBrightness_ from https://github.com/Yokimitsuro/khdays-decomp libs/nitro/gx/auto/GXx_GetMasterBrightness_.c
 * (license: CC0-1.0), reused by tools/donor_match.py */
typedef unsigned short u16;
typedef volatile u16 vu16;
int func_020ff17c(vu16 *reg) {
    u16 mode = (u16) (*reg & 0xc000);

    if (mode == 0) {
        return 0;
    } else if (mode == (1 << 14)) {
        return *reg & 0x001f;
    } else if (mode == (2 << 14)) {
        return -(*reg & 0x001f);
    } else {
        return 0;
    }
}
