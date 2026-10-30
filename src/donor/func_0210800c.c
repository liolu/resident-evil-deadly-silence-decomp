/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0200d98c from projets/code-lyoko/src/donor/func_0200d98c.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed long s32;
typedef int BOOL;
typedef enum {
    OS_INTRMODE_DISABLE_IRQ = 0x80,
    OS_INTRMODE_DISABLE_FIQ = 0x40,
    OS_INTRMODE_ENABLE      = 0
} OSIntrMode;
extern OSIntrMode func_021054ac(void);
extern OSIntrMode func_021054c0(OSIntrMode state);
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
typedef u64 OSTick;
typedef struct OSiAlarm OSAlarm;
typedef struct _OSThread OSThread;
typedef struct _OSThreadQueue OSThreadQueue;
typedef struct _OSThreadLink OSThreadLink;
typedef struct _OSMutexQueue OSMutexQueue;
typedef struct _OSMutexLink OSMutexLink;
typedef struct OSMutex OSMutex;
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

    u32 systemErrno;
};
extern void func_02103a8c(OSThreadQueue *queue);
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
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutexLink link;
};
typedef enum {
    FS_COMMAND_ASYNC_BEGIN = 0,
    FS_COMMAND_READFILE    = FS_COMMAND_ASYNC_BEGIN,
    FS_COMMAND_WRITEFILE,
    FS_COMMAND_ASYNC_END,

    FS_COMMAND_SYNC_BEGIN = FS_COMMAND_ASYNC_END,
    FS_COMMAND_SEEKDIR    = FS_COMMAND_SYNC_BEGIN,
    FS_COMMAND_READDIR,
    FS_COMMAND_FINDPATH,
    FS_COMMAND_GETPATH,
    FS_COMMAND_OPENFILEFAST,
    FS_COMMAND_OPENFILEDIRECT,
    FS_COMMAND_CLOSEFILE,
    FS_COMMAND_SYNC_END,

    FS_COMMAND_STATUS_BEGIN = FS_COMMAND_SYNC_END,
    FS_COMMAND_ACTIVATE     = FS_COMMAND_STATUS_BEGIN,
    FS_COMMAND_IDLE,
    FS_COMMAND_SUSPEND,
    FS_COMMAND_RESUME,
    FS_COMMAND_STATUS_END,

    FS_COMMAND_INVALID
} FSCommandType;
typedef enum {
    FS_RESULT_SUCCESS = 0,
    FS_RESULT_FAILURE,
    FS_RESULT_BUSY,
    FS_RESULT_CANCELED,
    FS_RESULT_CANCELLED = FS_RESULT_CANCELED,
    FS_RESULT_UNSUPPORTED,
    FS_RESULT_ERROR,
    FS_RESULT_PROC_ASYNC,
    FS_RESULT_PROC_DEFAULT,
    FS_RESULT_PROC_UNKNOWN
} FSResult;
typedef FSResult (*FS_ARCHIVE_READ_FUNC)(struct FSArchive *p, void *dst, u32 pos, u32 size);
typedef FSResult (*FS_ARCHIVE_WRITE_FUNC)(struct FSArchive *p, const void *src, u32 pos, u32 size);
typedef FSResult (*FS_ARCHIVE_PROC_FUNC)(struct FSFile *, FSCommandType);
typedef struct {
    struct FSFile *prev;
    struct FSFile *next;
} FSFileLink;
typedef struct FSArchive {
    union {
        char ptr[4];
        u32 pack;
    } name;
    struct FSArchive *next;
    struct FSArchive *prev;
    OSThreadQueue sync_q;
    OSThreadQueue stat_q;
    u32 flag;
    FSFileLink list;
    u32 base;
    u32 fat;
    u32 fat_size;
    u32 fnt;
    u32 fnt_size;
    u32 fat_bak;
    u32 fnt_bak;
    void *load_mem;
    FS_ARCHIVE_READ_FUNC read_func;
    FS_ARCHIVE_WRITE_FUNC write_func;
    FS_ARCHIVE_READ_FUNC table_func;
    FS_ARCHIVE_PROC_FUNC proc;
    u32 proc_flag;
} FSArchive;
typedef struct FSDirPos {
    struct FSArchive *arc;
    u16 own_id;
    u16 index;
    u32 pos;
} FSDirPos;
typedef struct FSFileID {
    struct FSArchive *arc;
    u32 file_id;
} FSFileID;
typedef struct {
    union {
        FSFileID file_id;
        FSDirPos dir_id;
    };
    u32 is_directory;
    u32 name_len;
    char name[128];
} FSDirEntry;
typedef struct {
    FSDirPos pos;
} FSSeekDirInfo;
typedef struct {
    FSDirEntry *p_entry;
    BOOL skip_string;
} FSReadDirInfo;
typedef struct {
    FSDirPos pos;
    const char *path;
    BOOL find_directory;
    union {
        FSFileID *file;
        FSDirPos *dir;
    } result;
} FSFindPathInfo;
typedef struct {
    u8 *buf;
    u32 buf_len;
    u16 total_len;
    u16 dir_id;
} FSGetPathInfo;
typedef struct {
    FSFileID id;
} FSOpenFileFastInfo;
typedef struct {
    u32 top;
    u32 bottom;
    u32 index;
} FSOpenFileDirectInfo;
typedef struct {
    u32 reserved;
} FSCloseFileInfo;
typedef struct {
    void *dst;
    u32 len_org;
    u32 len;
} FSReadFileInfo;
typedef struct {
    const void *src;
    u32 len_org;
    u32 len;
} FSWriteFileInfo;
typedef struct FSFile {
    FSFileLink link;
    struct FSArchive *arc;
    u32 stat;
    FSCommandType command;
    FSResult error;
    OSThreadQueue queue[1];
    union {
        struct {
            u32 own_id;
            u32 top;
            u32 bottom;
            u32 pos;
        } file;
        struct {
            FSDirPos pos;
            u32 parent;
        } dir;
    } prop;

    union {
        FSReadFileInfo readfile;
        FSWriteFileInfo writefile;

        FSSeekDirInfo seekdir;
        FSReadDirInfo readdir;
        FSFindPathInfo findpath;
        FSGetPathInfo getpath;
        FSOpenFileFastInfo openfilefast;
        FSOpenFileDirectInfo openfiledirect;
        FSCloseFileInfo closefile;
    } arg;
} FSFile;
static inline void FSi_CutFromListCore(FSFileLink *trg) {
    FSFile *const pr = trg->prev;
    FSFile *const nx = trg->next;
    if (pr) {
        pr->link.next = nx;
    }
    if (nx) {
        nx->link.prev = pr;
    }
}
static inline void FSi_CutFromList(FSFile *elem) {
    FSFileLink *const trg = &elem->link;
    FSi_CutFromListCore(trg);
    trg->next = trg->prev = ((void *) 0);
}
extern FSResult (*const fsi_default_command[])(FSFile *);
extern void func_0210800c(FSFile *file, FSResult signal);
#pragma thumb off
#pragma thumb off
void func_0210800c(FSFile *p_file, FSResult ret) {
    OSIntrMode bak_psr = func_021054ac();
    FSi_CutFromList(p_file);
    p_file->stat &= ~(0x00000002 | 0x00000001 | 0x00000004 | 0x00000008 | 0x00000040);
    p_file->error = ret;
    func_02103a8c(p_file->queue);
    (void) func_021054c0(bak_psr);
}
