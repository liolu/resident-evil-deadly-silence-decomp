/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* mfCiGetInterface from https://github.com/Yotona/twewy libs/cri/src/mfci.c (license: CC0-1.0), reused by tools/donor_match.py
 */
typedef struct {
    void (*ExecServer)();
    void (*EntryErrFunc)();
    int (*GetFileSize)();
    void (*unkC)();
    void *(*Open)(char *device_name, void *, int);
    void (*Close)(void *fd);
    int (*Seek)(void *fd, int offset, int whence);
    int (*Tell)(void *fd);
    int (*ReqRd)(void *fd, int len, void *buf);
    void (*unk24)();
    void (*StopTr)();
    int (*GetStat)(void *fd);
    int (*GetSctLen)();
    void (*SetSctLen)();
    int (*GetNumTr)();
    void (*unk3C)();
    void (*IsExistFile)();
    void (*unk44)();
    void (*unk48)();
    void (*unk4C)();
    void (*unk50)();
    void (*unk54)();
    void (*unk58)();
    void (*unk5C)();
    int (*OptFn1)();
    void (*unk64)();
} CVFSDevice;
extern char *volatile const data_021279b0;
extern CVFSDevice data_0213117c;
CVFSDevice *func_020e8764(void) {
    data_021279b0;
    return &data_0213117c;
}
