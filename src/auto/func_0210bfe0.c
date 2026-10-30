/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* RTC_Init from https://github.com/ntrtwl/NitroSDK libraries/rtc/src/external.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned short int u16;
typedef unsigned long u32;
typedef int BOOL;
extern void func_02107b0c(void);
typedef enum {
    PXI_PROC_ARM9 = 0,
    PXI_PROC_ARM7 = 1
} PXIProc;
typedef enum {
    PXI_FIFO_TAG_EX = 0,
    PXI_FIFO_TAG_USER_0,
    PXI_FIFO_TAG_USER_1,
    PXI_FIFO_TAG_SYSTEM,
    PXI_FIFO_TAG_NVRAM,
    PXI_FIFO_TAG_RTC,
    PXI_FIFO_TAG_TOUCHPANEL,
    PXI_FIFO_TAG_SOUND,
    PXI_FIFO_TAG_PM,
    PXI_FIFO_TAG_MIC,
    PXI_FIFO_TAG_WM,
    PXI_FIFO_TAG_FS,
    PXI_FIFO_TAG_OS,
    PXI_FIFO_TAG_CTRDG,
    PXI_FIFO_TAG_CARD,
    PXI_FIFO_TAG_WVR,
    PXI_FIFO_TAG_CTRDG_Ex,
    PXI_FIFO_TAG_CTRDG_PHI,
    PXI_MAX_FIFO_TAG = 32
} PXIFifoTag;
typedef void (*PXIFifoCallback)(PXIFifoTag tag, u32 data, BOOL err);
extern void func_02107d18(int fifotag, PXIFifoCallback callback);
extern BOOL func_02107cf0(int fifotag, PXIProc proc);
typedef enum RTCResult {
    RTC_RESULT_SUCCESS = 0,
    RTC_RESULT_BUSY,
    RTC_RESULT_ILLEGAL_PARAMETER,
    RTC_RESULT_SEND_ERROR,
    RTC_RESULT_INVALID_COMMAND,
    RTC_RESULT_ILLEGAL_STATUS,
    RTC_RESULT_FATAL_ERROR,
    RTC_RESULT_MAX
} RTCResult;
typedef void (*RTCCallback)(RTCResult result, void *arg);
typedef void (*RTCInterrupt)(void);
extern void func_0210bfe0(void);
typedef enum RTCLock {
    RTC_LOCK_OFF = 0,
    RTC_LOCK_ON,
    RTC_LOCK_MAX
} RTCLock;
typedef struct RTCWork {
    u32 lock;
    RTCCallback callback;
    void *buffer[2];
    void *callbackArg;
    u32 sequence;
    u32 index;
    RTCInterrupt interrupt;
    RTCResult commonResult;
} RTCWork;
extern u16 data_0215a8dc;
extern RTCWork data_0215a8e0;
extern void func_0210b97c(PXIFifoTag tag, u32 data, BOOL err);
void func_0210bfe0(void) {
    if (data_0215a8dc) {
        return;
    }

    data_0215a8dc = 1;

    data_0215a8e0.lock      = RTC_LOCK_OFF;
    data_0215a8e0.callback  = ((void *) 0);
    data_0215a8e0.interrupt = ((void *) 0);
    data_0215a8e0.buffer[0] = ((void *) 0);
    data_0215a8e0.buffer[1] = ((void *) 0);

    func_02107b0c();
    while (!func_02107cf0(PXI_FIFO_TAG_RTC, PXI_PROC_ARM7)) {
    }

    func_02107d18(PXI_FIFO_TAG_RTC, func_0210b97c);
}
void func_0210b97c(PXIFifoTag tag, u32 data, BOOL err);
