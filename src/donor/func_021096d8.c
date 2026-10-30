/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020881bc from projets/nintendogs-dachshund/src/donor/func_020881bc.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
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
extern FSArchive *func_02108d50(const char *name, int length);
extern BOOL func_02108dc8(FSFile *file, u32 command);
extern BOOL func_021096d8(FSFile *scratch, const char *path, FSFileID *fileId, FSDirPos *dirPos);
extern FSDirPos data_0215a7ac;
static inline BOOL FSi_IsSlash(u32 c) {
    return c == '/' || c == '\\';
}
static inline BOOL Archive_RoutinesSet(FSArchive *arc) {
    return (arc->flags & 0x2) ? 1 : 0;
}
BOOL func_021096d8(FSFile *dir, const char *path, FSFileID *fileId, FSDirPos *dirPos) {
    FSDirPos start;

    if (FSi_IsSlash((u8) *path)) {
        start.arc   = data_0215a7ac.arc;
        start.ownId = 0;
        start.pos   = 0;
        start.index = 0;
        path++;
    } else {
        int i;

        start = data_0215a7ac;
        for (i = 0; i <= 3; i++) {
            u32 c = (u8) path[i];

            if (c == '\0' || FSi_IsSlash(c)) {
                break;
            } else if (c == ':') {
                FSArchive *arc = func_02108d50(path, i);

                if (arc == ((void *) 0)) {
                    return 0;
                }
                if (Archive_RoutinesSet(arc) == 0) {
                    return 0;
                }
                start.arc   = arc;
                start.pos   = 0;
                start.index = 0;
                start.ownId = 0;
                path += i + 1;
                if (FSi_IsSlash((u8) *path)) {
                    path++;
                }
                break;
            }
        }
    }
    dir->arc               = start.arc;
    dir->arg.findPath.path = path;
    dir->arg.findPath.pos  = start;
    if (dirPos != ((void *) 0)) {
        dir->arg.findPath.findDirectory = 1;
        dir->arg.findPath.result.dir    = dirPos;
    } else {
        dir->arg.findPath.findDirectory = 0;
        dir->arg.findPath.result.file   = fileId;
    }
    return func_02108dc8(dir, 4);
}
