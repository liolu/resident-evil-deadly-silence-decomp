/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02010c10 from projets/code-lyoko/src/donor/func_02010c10.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed short int s16;
typedef signed long s32;
typedef volatile u16 vu16;
typedef u32 REGType32;
typedef u64 REGType64;
typedef vu16 REGType16v;
typedef u32 OSIntrMode;
extern OSIntrMode func_021054ac(void);
extern OSIntrMode func_021054c0(OSIntrMode state);
static inline void CP_SetDivImm32_32_NS_(u32 numer, u32 denom) {
    *(REGType32 *) (0x04000000 + 0x290) = numer;
    *(REGType64 *) (0x04000000 + 0x298) = denom;
}
static inline void CP_SetDiv32_32(u32 numer, u32 denom) {
    (*(REGType16v *) (0x04000000 + 0x280)) = (0UL << 0);
    CP_SetDivImm32_32_NS_(numer, denom);
}
static inline s32 CP_IsDivBusy(void) {
    return ((*(REGType16v *) (0x04000000 + 0x280)) & 0x8000);
}
static inline void CP_WaitDiv(void) {
    while (CP_IsDivBusy()) {
    }
}
static inline s32 CP_GetDivResultImm32(void) {
    return (s32) (*(REGType32 *) (0x04000000 + 0x2a0));
}
static inline s32 CP_GetDivResult32(void) {
    CP_WaitDiv();
    return CP_GetDivResultImm32();
}
typedef enum {
    TP_REQUEST_COMMAND_SAMPLING      = 0x0,
    TP_REQUEST_COMMAND_AUTO_ON       = 0x1,
    TP_REQUEST_COMMAND_AUTO_OFF      = 0x2,
    TP_REQUEST_COMMAND_SET_STABILITY = 0x3,
    TP_REQUEST_COMMAND_AUTO_SAMPLING = 0x10
} TPRequestCommand;
typedef enum {
    TP_RESULT_SUCCESS = 0,
    TP_RESULT_INVALID_PARAMETER,
    TP_RESULT_ILLEGAL_STATUS,
    TP_RESULT_EXCLUSIVE,
    TP_RESULT_PXI_BUSY
} TPRequestResult;
typedef struct {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;
typedef struct NvTpData {
    s16 x0;
    s16 y0;
    s16 xDotSize;
    s16 yDotSize;
} TPCalibrateParam;
typedef void (*TPRecvCallback)(TPRequestCommand command, TPRequestResult result, u16 index);
extern void func_0210a118(const TPCalibrateParam *param);
extern const u16(*ctrdgi_fl_maxtime);
typedef struct {
    s32 x0;
    s32 xDotSize;
    s32 xDotSizeInv;
    s32 y0;
    s32 yDotSize;
    s32 yDotSizeInv;
} TPiCalibrateParam;
extern struct {
    TPRecvCallback callback;
    TPData buf;
    u16 index;
    u16 frequence;
    TPData *samplingBufs;
    u16 bufSize;
    TPiCalibrateParam calibrate;
    u16 calibrate_flg;
    vu16 state;
    vu16 err_flg;
    vu16 command_flg;
} data_0215a828;
void func_0210a118(const TPCalibrateParam *param) {
    OSIntrMode enabled;

    if (param == 0) {
        data_0215a828.calibrate_flg = 0;
        return;
    }

    enabled = func_021054ac();

    if (param->xDotSize != 0) {
        CP_SetDiv32_32(0x10000000, (u32) param->xDotSize);

        data_0215a828.calibrate.x0          = param->x0;
        data_0215a828.calibrate.xDotSize    = param->xDotSize;
        data_0215a828.calibrate.xDotSizeInv = (s32) CP_GetDivResult32();
    } else {
        data_0215a828.calibrate.x0          = 0;
        data_0215a828.calibrate.xDotSize    = 0;
        data_0215a828.calibrate.xDotSizeInv = 0;
    }

    if (param->yDotSize != 0) {
        CP_SetDiv32_32(0x10000000, (u32) param->yDotSize);

        data_0215a828.calibrate.y0          = param->y0;
        data_0215a828.calibrate.yDotSize    = param->yDotSize;
        data_0215a828.calibrate.yDotSizeInv = (s32) CP_GetDivResult32();
    } else {
        data_0215a828.calibrate.y0          = 0;
        data_0215a828.calibrate.yDotSize    = 0;
        data_0215a828.calibrate.yDotSizeInv = 0;
    }

    (void) func_021054c0(enabled);

    data_0215a828.calibrate_flg = 1;
}
