/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* Archive_CmdNextDirEntry from https://github.com/sturmds/advance-wars-dual-strike-decomp
 * src/sdk/fs/archive_cmd_next_dir_entry.c (license: CC0-1.0), reused by tools/donor_match.py */
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
typedef struct ArchiveTableCursor {
    FSArchive *arc;
    u32 pos;
} ArchiveTableCursor;
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
extern void func_02108944(ArchiveTableCursor *cursor, void *dest, u32 length);
int func_021086f8(FSFile *file) {
    DirListingEntry *entry = file->arg.readDir.entry;
    u8 header;
    ArchiveTableCursor cursor;

    cursor.arc = file->arc;
    cursor.pos = file->dirPos.pos;
    func_02108944(&cursor, &header, 1);
    entry->nameLength  = header & 0x7f;
    entry->isDirectory = (header >> 7) & 1;
    if (entry->nameLength == 0) {
        return 1;
    }
    if (file->arg.readDir.skipName) {
        cursor.pos += entry->nameLength;
    } else {
        func_02108944(&cursor, entry->name, entry->nameLength);
        entry->name[entry->nameLength] = '\0';
    }
    if (entry->isDirectory) {
        u16 id;

        func_02108944(&cursor, &id, 2);
        entry->dirId.arc   = file->arc;
        entry->dirId.ownId = id & 0xfff;
        entry->dirId.index = 0;
        entry->dirId.pos   = 0;
    } else {
        entry->fileId.arc     = file->arc;
        entry->fileId.file_id = file->dirPos.index;
        file->dirPos.index++;
    }
    file->dirPos.pos = cursor.pos;
    return 0;
}
