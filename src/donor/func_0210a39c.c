/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02010e94 from projets/code-lyoko/src/donor/func_02010e94.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed long s32;
typedef volatile u16 vu16;
typedef int BOOL;
extern void func_02105528();
extern void func_02105528(void);
typedef struct CPContext {
    u64 div_numer;
    u64 div_denom;
    u64 sqrt;
    u16 div_mode;
    u16 sqrt_mode;
} CPContext;
typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pc_plus4;

    u32 sp_svc;

    CPContext cp_context;

} OSContext;
typedef struct _OSThread OSThread;
typedef struct _OSThreadQueue OSThreadQueue;
typedef struct _OSThreadLink OSThreadLink;
typedef struct _OSMutexQueue OSMutexQueue;
typedef struct _OSMutexLink OSMutexLink;
typedef struct OSMutex OSMutex;
typedef struct OSiAlarm OSAlarm;
struct _OSThreadQueue {
    OSThread *head;
    OSThread *tail;
};
struct _OSThreadLink {
    OSThread *prev;
    OSThread *next;
};
struct _OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
};
struct _OSMutexLink {
    OSMutex *next;
    OSMutex *prev;
};
typedef enum {
    OS_THREAD_STATE_WAITING    = 0,
    OS_THREAD_STATE_READY      = 1,
    OS_THREAD_STATE_TERMINATED = 2
} OSThreadState;
typedef void (*OSThreadDestructor)(void *);
struct _OSThread {
    OSContext context;
    OSThreadState state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;

    OSThreadQueue *queue;
    OSThreadLink link;

    OSMutex *mutex;
    OSMutexQueue mutexQueue;

    u32 stackTop;
    u32 stackBottom;
    u32 stackWarningOffset;

    OSThreadQueue joinQueue;
    void *specific[3];
    OSAlarm *alarmForSleep;
    OSThreadDestructor destructor;
    void *userParameter;
    int systemErrno;
};
typedef struct OSThreadInfo {
    u16 isNeedRescheduling;

    u16 irqDepth;

    OSThread *current;
    OSThread *list;
    void *switchCallback;

} OSThreadInfo;
typedef volatile struct OSLockWord {
    u32 lockFlag;
    u16 ownerID;
    u16 extension;
} OSLockWord;
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;

    OSMutexLink link;
};
typedef u64 OSTick;
typedef void (*OSAlarmHandler)(void *);
struct OSiAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    OSTick fire;
    OSAlarm *prev;
    OSAlarm *next;
    OSTick period;
    OSTick start;
};
typedef struct {
    u8 bootCheckInfo[0x20];
    u32 resetParameter;
    u8 padding5[0x8];
    u32 romBaseOffset;
    u8 cartridgeModuleInfo[12];
    u32 vblankCount;
    u8 wmBootBuf[0x40];
    u8 nvramUserInfo[0x100];
    u8 isd_reserved1[0x20];
    u8 arenaInfo[0x48];
    u8 real_time_clock[8];
    u32 dmaClearBuf[4];
    u8 rom_header[0x160];
    u8 isd_reserved2[32];
    u32 pxiSignalParam[2];
    u32 pxiHandleChecker[2];
    u32 mic_last_address;
    u16 mic_sampling_data;
    u16 wm_callback_control;
    u16 wm_rssi_pool;
    u8 ctrdg_SetModuleInfoFlag;
    u8 ctrdg_IsExisting;
    u32 component_param;
    OSThreadInfo *threadinfo_mainp;
    OSThreadInfo *threadinfo_subp;
    u16 button_XY;
    u8 touch_panel[4];
    u16 autoloadSync;
    u32 lockIDFlag_mainp[2];
    u32 lockIDFlag_subp[2];
    struct OSLockWord lock_VRAM_C;
    struct OSLockWord lock_VRAM_D;
    struct OSLockWord lock_WRAM_BLOCK0;
    struct OSLockWord lock_WRAM_BLOCK1;
    struct OSLockWord lock_CARD;
    struct OSLockWord lock_CARTRIDGE;
    struct OSLockWord lock_INIT;
    u16 mmem_checker_mainp;
    u16 mmem_checker_subp;
    u8 padding4[2];
    u16 command_area;
} OSSystemWork;
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
typedef union SPITpData {
    struct {
        u32 x : 12;
        u32 y : 12;
        u32 touch : 1;
        u32 validity : 2;
        u32 dummy : 5;

    } e;
    u32 raw;
    u8 bytes[4];
    u16 halfs[2];
} SPITpData;
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
typedef enum {
    TP_STATE_READY = 0,
    TP_STATE_SAMPLING,
    TP_STATE_AUTO_SAMPLING,
    TP_STATE_AUTO_WAIT_END
} TPState;
typedef struct {
    u16 x;
    u16 y;
    u16 touch;
    u16 validity;
} TPData;
typedef void (*TPRecvCallback)(TPRequestCommand command, TPRequestResult result, u16 index);
extern const u16(*ctrdgi_fl_maxtime);
extern void func_0210a39c(PXIFifoTag tag, u32 data, BOOL err);
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
static inline void TPi_CopyTpFromSystemWork(TPData *result) {
    SPITpData spi_tp;

    spi_tp.halfs[0] = *(u16 *) (&(((OSSystemWork *) (0x02000000 + 0x007ffc00))->touch_panel[0]));
    spi_tp.halfs[1] = *(u16 *) (&(((OSSystemWork *) (0x02000000 + 0x007ffc00))->touch_panel[2]));

    result->x        = (u16) spi_tp.e.x;
    result->y        = (u16) spi_tp.e.y;
    result->touch    = (u8) spi_tp.e.touch;
    result->validity = (u8) spi_tp.e.validity;
}
static inline void TPi_ErrorAtPxi(TPRequestCommand command) {
    data_0215a828.err_flg |= (1 << command);

    if (data_0215a828.callback) {
        (data_0215a828.callback)(command, TP_RESULT_PXI_BUSY, 0);
    }
}
void func_0210a39c(PXIFifoTag tag, u32 data, BOOL err) {

#pragma unused(tag)
#line 268
    u16 result;
    u16 command;

    result  = (u16) (data & 0x0000ffff);
    command = (u16) ((result & 0x7f00) >> 8);

    if (err) {
        TPi_ErrorAtPxi((TPRequestCommand) command);
        return;
    }

    if (command == 0x0010) {
        data_0215a828.index++;

        if (data_0215a828.index >= data_0215a828.bufSize) {
            data_0215a828.index = 0;
        }

        TPi_CopyTpFromSystemWork(&data_0215a828.samplingBufs[data_0215a828.index]);

        if (data_0215a828.callback) {
            (data_0215a828.callback)((TPRequestCommand) command, TP_RESULT_SUCCESS, (u8) data_0215a828.index);
        }

        return;
    }

    if (!(data & 0x01000000)) {
        return;
    }

    ((void) 0);

    switch ((u8) (result & 0x00ff)) {
        case 0x0000:
            switch (command) {
                case 0x0000:
                    TPi_CopyTpFromSystemWork(&data_0215a828.buf);
                    data_0215a828.state = TP_STATE_READY;
                    break;
                case 0x0001:
                    data_0215a828.state = TP_STATE_AUTO_SAMPLING;
                    break;
                case 0x0002:
                    data_0215a828.state = TP_STATE_READY;
                    break;
            }

            data_0215a828.command_flg &= ~(1 << command);

            if (data_0215a828.callback) {
                (data_0215a828.callback)((TPRequestCommand) command, TP_RESULT_SUCCESS, 0);
            }

            break;
        case 0x0004:
            result = TP_RESULT_EXCLUSIVE;
            goto common;
        case 0x0002:
            result = TP_RESULT_INVALID_PARAMETER;
            goto common;
        case 0x0003:
            result = TP_RESULT_ILLEGAL_STATUS;
        common:
            data_0215a828.err_flg |= (1 << command);
            data_0215a828.command_flg &= ~(1 << command);

            if (data_0215a828.callback) {
                (data_0215a828.callback)((TPRequestCommand) command, (TPRequestResult) (result & 0xff), 0);
            }
            break;

        case 0x0001:
        default:
            func_02105528();
            return;
    }
}
