/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0201075c from projets/code-lyoko/src/donor/func_0201075c.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed short s16;
typedef signed int s32;
typedef unsigned long long u64;
extern u32 func_021054ac(void);
extern void func_021054c0(u32 state);
typedef struct {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} TPCalibrateParam;
static inline void CP_SetDiv32_32(u32 numer, u32 denom) {
    (*(volatile u16 *) 0x4000280) = 0;
    (*(volatile u32 *) 0x4000290) = numer;
    (*(volatile u64 *) 0x4000298) = denom;
}
static inline void CP_WaitDiv(void) {
    while ((*(volatile u16 *) 0x4000280) & 0x8000) {
    }
}
static inline s32 CP_GetDivResult32(void) {
    CP_WaitDiv();
    return (s32) (*(volatile u32 *) 0x40002a0);
}
u32 func_02109d88(TPCalibrateParam *calibrate, u16 raw_x1, u16 raw_y1, u16 dx1, u16 dy1, u16 raw_x2, u16 raw_y2, u16 dx2,
                  u16 dy2) {
    s32 rx_width, dx_width, ry_width, dy_width;
    s32 tmp32;
    u32 enabled;

    if (raw_x1 >= 0x1000 || raw_y1 >= 0x1000 || raw_x2 >= 0x1000 || raw_y2 >= 0x1000) {
        return 1;
    }

    if (dx1 >= 256 || dx2 >= 256 || dy1 >= 192 || dy2 >= 192) {
        return 1;
    }

    if (dx1 == dx2 || dy1 == dy2 || raw_x1 == raw_x2 || raw_y1 == raw_y2) {
        return 1;
    }

    rx_width = raw_x1 - raw_x2;
    dx_width = dx1 - dx2;

    enabled = func_021054ac();

    CP_SetDiv32_32(((u32) rx_width) << 8, (u32) dx_width);

    ry_width = raw_y1 - raw_y2;
    dy_width = dy1 - dy2;

    tmp32 = CP_GetDivResult32();
    CP_SetDiv32_32(((u32) ry_width) << 8, (u32) dy_width);

    if (!((tmp32) < 0x8000 && (tmp32) >= -0x8000)) {
        func_021054c0(enabled);
        return 1;
    }
    calibrate->xDotSize = (s16) tmp32;
    tmp32               = (s16) ((((s32) (raw_x1 + raw_x2) << 8) - ((s32) (dx1 + dx2) * calibrate->xDotSize)) >> 7);
    if (!((tmp32) < 0x8000 && (tmp32) >= -0x8000)) {
        func_021054c0(enabled);
        return 1;
    }
    calibrate->x0 = (s16) tmp32;

    tmp32 = CP_GetDivResult32();
    func_021054c0(enabled);

    if (!((tmp32) < 0x8000 && (tmp32) >= -0x8000)) {
        return 1;
    }
    calibrate->yDotSize = (s16) tmp32;
    tmp32               = (s16) ((((s32) (raw_y1 + raw_y2) << 8) - ((s32) (dy1 + dy2) * calibrate->yDotSize)) >> 7);
    if (!((tmp32) < 0x8000 && (tmp32) >= -0x8000)) {
        return 1;
    }
    calibrate->y0 = (s16) tmp32;

    return 0;
}
