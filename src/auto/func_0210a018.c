/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* TP_GetCalibratedResult from https://github.com/RonyxDumb/mkds src/arm9/0214e6e4_func_0214e6e4.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed long s32;
typedef volatile u16 vu16;
typedef enum {
    TP_REQUEST_COMMAND_SAMPLING      = 0x0,
    TP_REQUEST_COMMAND_AUTO_ON       = 0x1,
    TP_REQUEST_COMMAND_AUTO_OFF      = 0x2,
    TP_REQUEST_COMMAND_SET_STABILITY = 0x3,
    TP_REQUEST_COMMAND_AUTO_SAMPLING = 0x10
} TPRequestCommand;
typedef enum {
    TP_REQUEST_COMMAND_FLAG_SAMPLING      = 1 << TP_REQUEST_COMMAND_SAMPLING,
    TP_REQUEST_COMMAND_FLAG_AUTO_ON       = 1 << TP_REQUEST_COMMAND_AUTO_ON,
    TP_REQUEST_COMMAND_FLAG_AUTO_OFF      = 1 << TP_REQUEST_COMMAND_AUTO_OFF,
    TP_REQUEST_COMMAND_FLAG_SET_STABILITY = 1 << TP_REQUEST_COMMAND_SET_STABILITY
} TPRequestCommandFlag;
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
typedef void (*TPRecvCallback)(TPRequestCommand command, TPRequestResult result, u16 index);
extern u32 func_0210a018(TPData *result);
extern void func_02109c58(TPData *disp, const TPData *raw);
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
u32 func_0210a018(TPData *result) {
    ((void) 0);

    if (data_0215a828.err_flg & TP_REQUEST_COMMAND_FLAG_SAMPLING) {
        return 1;
    }

    *result = data_0215a828.buf;
    func_02109c58(result, result);
    return 0;
}
void func_02109c58(TPData *disp, const TPData *raw);
