/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02087404 from projets/nintendogs-dachshund/src/donor/func_02087404.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef signed int s32;
typedef int BOOL;
typedef struct OSThreadQueue {
    u16 head;
    u16 tail;
} OSThreadQueue;
typedef struct FSArchive FSArchive;
typedef struct FSFile FSFile;
typedef struct FSFileID {
    FSArchive *arc;
    u32 file_id;
} FSFileID;
typedef struct FSDirPos {
    FSArchive *arc;
    u16 ownId;
    u16 index;
    u32 pos;
} FSDirPos;
typedef struct DirListingEntry {
    union {
        FSFileID fileId;
        FSDirPos dirId;
    };
    u32 isDirectory;
    u32 nameLength;
    char name[127 + 1];
} DirListingEntry;
typedef struct FSGetPathInfo {
    u8 *buffer;
    u32 bufferSize;
    u16 totalLength;
    u16 dirId;
} FSGetPathInfo;
struct FSFile {
    FSFile *prev;
    FSFile *next;
    FSArchive *arc;
    u32 flags;
    u32 command;
    u32 error;
    OSThreadQueue queue;
    union {
        struct {
            u32 id;
            u32 top;
            u32 bottom;
            u32 pos;
        };
        struct {
            FSDirPos dirPos;
            u32 parent;
        };
    };
    union {
        struct {
            u32 top;
            u32 bottom;
            u32 id;
        } openFileDirect;
        struct {
            u32 unused;
            u32 id;
        } openFileFast;
        struct {
            void *dest;
            u32 requested;
            u32 length;
        } readFile;
        struct {
            FSDirPos pos;
        } seekDir;
        struct {
            DirListingEntry *entry;
            BOOL skipName;
        } readDir;
        struct {
            FSDirPos pos;
            const char *path;
            BOOL findDirectory;
            union {
                FSFileID *file;
                FSDirPos *dir;
            } result;
        } findPath;
        FSGetPathInfo getPath;
    } arg;
};
typedef int (*ArchiveByteReader)(FSArchive *arc, void *dest, u32 src, u32 len);
typedef int (*ArchiveByteWriter)(FSArchive *arc, const void *src, u32 dest, u32 len);
struct FSArchive {
    u32 name;
    FSArchive *next;
    FSArchive *prev;
    OSThreadQueue queue;
    u32 flags;
    u32 unk_14;
    FSFile *command;
    u32 base;
    u32 fat;
    u32 fatSize;
    u32 fnt;
    u32 fntSize;
    u32 fatOriginal;
    u32 fntOriginal;
    u32 unk_38;
    ArchiveByteReader read;
    ArchiveByteWriter write;
    ArchiveByteReader readTable;
    void *tableBuffer;
    u32 tableBufferSize;
};
extern void func_02109838(FSFile *file);
extern s32 func_021093b0(FSFile *file, void *dest, s32 size);
extern BOOL func_021094a0(FSFile *file);
extern BOOL func_021095b4(FSFile *file, FSArchive *arc, u32 top, u32 bottom, u32 index);
extern void func_021061d8(void *dest, int value, u32 size);
extern int func_02109268(FSArchive *arc, void *dest, u32 src, u32 length);
static inline u32 Archive_RoundUpTo32(u32 x) {
    return (x + 31) & ~31;
}
u32 func_02108aec(FSArchive *arc, void *mem, u32 size) {

    int needed = Archive_RoundUpTo32((int) (arc->fatSize + arc->fntSize + 32));

    if (needed <= size) {
        u8 *cache = (u8 *) Archive_RoundUpTo32((u32) mem);
        FSFile file;

        func_02109838(&file);
        if (func_021095b4(&file, arc, arc->fat, arc->fat + arc->fatSize, (u32) -1)) {
            if (func_021093b0(&file, cache, arc->fatSize) < 0) {
                func_021061d8(cache, 0, arc->fatSize);
            }
            func_021094a0(&file);
        }
        arc->fat = (u32) cache;
        cache += arc->fatSize;

        if (func_021095b4(&file, arc, arc->fnt, arc->fnt + arc->fntSize, (u32) -1)) {
            if (func_021093b0(&file, cache, arc->fntSize) < 0) {
                func_021061d8(cache, 0, arc->fntSize);
            }
            func_021094a0(&file);
        }
        arc->fnt = (u32) cache;

        arc->unk_38    = (u32) mem;
        arc->readTable = func_02109268;
        arc->flags |= 0x4;
    }
    return needed;
}
