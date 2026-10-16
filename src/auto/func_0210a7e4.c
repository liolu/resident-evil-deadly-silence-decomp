/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* MicCommonCallback from https://github.com/ntrtwl/NitroSDK libraries/spi/src/mic.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed long s32;
typedef int BOOL;
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
typedef void (*MICCallback)(MICResult result, void *arg);
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
extern void func_0210a7e4(PXIFifoTag tag, u32 data, BOOL err);
void func_0210a7e4(PXIFifoTag tag, u32 data, BOOL err) {

#pragma unused(tag)
    u16 command;
    u16 pxiresult;
    MICResult result;
    MICCallback cb;

    if (err) {
        if (data_0215a864.lock != MIC_LOCK_OFF) {
            data_0215a864.lock = MIC_LOCK_OFF;
        }
        if (data_0215a864.callback) {
            cb                     = data_0215a864.callback;
            data_0215a864.callback = ((void *) 0);
            cb(MIC_RESULT_FATAL_ERROR, data_0215a864.callbackArg);
        }
    }

    command   = (u16) ((data & 0x00007f00) >> 8);
    pxiresult = (u16) ((data & 0x000000ff) >> 0);

    switch (pxiresult) {
        case 0x0000:
            result = MIC_RESULT_SUCCESS;
            break;
        case 0x0001:
            result = MIC_RESULT_INVALID_COMMAND;
            break;
        case 0x0002:
            result = MIC_RESULT_ILLEGAL_PARAMETER;
            break;
        case 0x0003:
            result = MIC_RESULT_ILLEGAL_STATUS;
            break;
        case 0x0004:
            result = MIC_RESULT_BUSY;
            break;
        default:
            result = MIC_RESULT_FATAL_ERROR;
    }

    if (command == 0x0051) {
        if (data_0215a864.full) {
            data_0215a864.full(result, data_0215a864.fullArg);
        }
    } else {
        if (command == 0x0040) {
            if (data_0215a864.dst_buf) {
                *(u16 *) (data_0215a864.dst_buf) = ((OSSystemWork *) (0x02000000 + 0x007ffc00))->mic_sampling_data;
            }
        }

        if (data_0215a864.lock != MIC_LOCK_OFF) {
            data_0215a864.lock = MIC_LOCK_OFF;
        }

        if (data_0215a864.callback) {
            cb                     = data_0215a864.callback;
            data_0215a864.callback = ((void *) 0);
            cb(result, data_0215a864.callbackArg);
        }
    }
}
