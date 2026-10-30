/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* FS_RegisterArchiveName from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/fs/fs_register_archive.c
 * (license: CC0-1.0), reused by tools/donor_match.py */
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
extern u32 func_021092e0(const char *name, int length);
extern FSArchive *data_0215a7a8;
extern FSDirPos data_0215a7ac;
extern int func_021054ac(void);
extern void func_021054c0(int state);
extern FSArchive *data_0215a7a8;
extern FSDirPos data_0215a7ac;
BOOL func_02108c90(FSArchive *arc, const char *name, int nameLength) {
    BOOL registered = 0;
    int irqState    = func_021054ac();

    if (func_02108d50(name, nameLength) == ((void *) 0)) {
        if (data_0215a7a8 == ((void *) 0)) {
            data_0215a7a8       = arc;
            data_0215a7ac.arc   = arc;
            data_0215a7ac.pos   = 0;
            data_0215a7ac.index = 0;
            data_0215a7ac.ownId = 0;
        } else {
            FSArchive *last = data_0215a7a8;

            while (last->next != ((void *) 0)) {
                last = last->next;
            }
            last->next = arc;
            arc->prev  = last;
        }
        arc->name = func_021092e0(name, nameLength);
        arc->flags |= 0x1;
        registered = 1;
    }
    func_021054c0(irqState);
    return registered;
}
