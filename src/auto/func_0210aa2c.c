/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* MIC_StartAutoSamplingAsync from https://github.com/ntrtwl/NitroSDK libraries/spi/src/mic.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;
typedef u32 OSIntrMode;
extern OSIntrMode func_021054ac(void);
extern OSIntrMode func_021054c0(OSIntrMode state);
typedef enum MICResult {
    MIC_RESULT_SUCCESS = 0,
    MIC_RESULT_BUSY,
    MIC_RESULT_ILLEGAL_PARAMETER,
    MIC_RESULT_SEND_ERROR,
    MIC_RESULT_INVALID_COMMAND,
    MIC_RESULT_ILLEGAL_STATUS,
    MIC_RESULT_FATAL_ERROR,
    MIC_RESULT_MAX
} MICResult;
typedef enum MICSamplingType {
    MIC_SAMPLING_TYPE_8BIT = 0,
    MIC_SAMPLING_TYPE_12BIT,
    MIC_SAMPLING_TYPE_SIGNED_8BIT,
    MIC_SAMPLING_TYPE_SIGNED_12BIT,
    MIC_SAMPLING_TYPE_12BIT_FILTER_OFF,
    MIC_SAMPLING_TYPE_SIGNED_12BIT_FILTER_OFF,
    MIC_SAMPLING_TYPE_MAX
} MICSamplingType;
typedef enum MICSamplingRate {
    MIC_SAMPLING_RATE_8K    = (33513982 / 8000),
    MIC_SAMPLING_RATE_11K   = (33513982 / 11025),
    MIC_SAMPLING_RATE_16K   = (33513982 / 16000),
    MIC_SAMPLING_RATE_22K   = (33513982 / 22050),
    MIC_SAMPLING_RATE_32K   = (33513982 / 32000),
    MIC_SAMPLING_RATE_LIMIT = 1024
} MICSamplingRate;
typedef void (*MICCallback)(MICResult result, void *arg);
typedef struct MICAutoParam {
    MICSamplingType type;
    void *buffer;
    u32 size;
    u32 rate;
    BOOL loop_enable;
    MICCallback full_callback;
    void *full_arg;
} MICAutoParam;
extern MICResult func_0210aa2c(const MICAutoParam *param, MICCallback callback, void *arg);
typedef enum MICLock {
    MIC_LOCK_OFF = 0,
    MIC_LOCK_ON,
    MIC_LOCK_MAX
} MICLock;
typedef struct MICWork {
    MICLock lock;
    MICCallback callback;
    void *callbackArg;
    MICResult commonResult;
    MICCallback full;
    void *fullArg;
    void *dst_buf;
} MICWork;
extern MICWork data_0215a864;
extern BOOL func_0210a6b8(void *buf, u32 size, u32 span, u8 flags);
MICResult func_0210aa2c(const MICAutoParam *param, MICCallback callback, void *arg) {
    OSIntrMode enabled;
    u8 flags;

    ((void) 0);
    ((void) 0);

    {

        if ((u32) (param->buffer) & 0x01f) {

            return MIC_RESULT_ILLEGAL_PARAMETER;
        }

        if (param->size & 0x01f) {

            return MIC_RESULT_ILLEGAL_PARAMETER;
        }

        if (param->size <= 0) {
            return MIC_RESULT_ILLEGAL_PARAMETER;
        }

        if (param->rate < MIC_SAMPLING_RATE_LIMIT) {
            return MIC_RESULT_ILLEGAL_PARAMETER;
        }

        switch (param->type) {
            case MIC_SAMPLING_TYPE_8BIT:
                flags = 0x0000;
                break;
            case MIC_SAMPLING_TYPE_12BIT:
                flags = 0x0001;
                break;
            case MIC_SAMPLING_TYPE_SIGNED_8BIT:
                flags = 0x0002;
                break;
            case MIC_SAMPLING_TYPE_SIGNED_12BIT:
                flags = 0x0003;
                break;
            case MIC_SAMPLING_TYPE_12BIT_FILTER_OFF:
                flags = (0x0001 | 0x0004);
                break;
            case MIC_SAMPLING_TYPE_SIGNED_12BIT_FILTER_OFF:
                flags = (0x0003 | 0x0004);
                break;
            default:
                return MIC_RESULT_ILLEGAL_PARAMETER;
        }

        if (param->loop_enable) {
            flags = (u8) (flags | 0x0010);
        } else {
            flags = (u8) (flags | 0x0000);
        }

        flags = (u8) (flags | 0x0000);
    }

    enabled = func_021054ac();
    if (data_0215a864.lock != MIC_LOCK_OFF) {
        (void) func_021054c0(enabled);
        return MIC_RESULT_BUSY;
    }
    data_0215a864.lock = MIC_LOCK_ON;
    (void) func_021054c0(enabled);

    data_0215a864.callback    = callback;
    data_0215a864.callbackArg = arg;
    data_0215a864.full        = param->full_callback;
    data_0215a864.fullArg     = param->full_arg;
    if (func_0210a6b8(param->buffer, param->size, param->rate, flags)) {
        return MIC_RESULT_SUCCESS;
    }
    return MIC_RESULT_SEND_ERROR;
}
BOOL func_0210a6b8(void *buf, u32 size, u32 span, u8 flags);
