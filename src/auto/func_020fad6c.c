/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_0207091c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_anm_vis.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef long fx32;
typedef struct {
    u8 sbcType;
    u8 scalingRule;
    u8 texMtxMode;
    u8 numNode;
    u8 numMat;
    u8 numShp;
    u8 firstUnusedMtxStackID;
    u8 dummy_;
} UnkResMdlInfo;
typedef struct {
    u32 size;
    u32 ofsSbc;
    u32 ofsMat;
    u32 ofsShp;
    u32 ofsEvpMtx;
    UnkResMdlInfo info;
} UnkResMdl;
typedef void (*UnkAnmFunc)(void *result, const struct UnkAnmObj *obj, u32 dataIdx);
typedef struct UnkAnmObj {
    fx32 frame;
    fx32 ratio;
    void *resAnm;
    UnkAnmFunc funcAnm;
    struct UnkAnmObj *next;
    const void *resTex;
    u8 priority;
    u8 numMapData;
    u16 mapData[1];
} UnkAnmObj;
typedef struct {
    u8 category0;
    u8 revision;
    u16 category1;
    u16 numFrame;
    u16 numNode;
    u16 flag;
    u16 dummy_;
    u32 visData[1];
} UnkResVisAnm;
extern UnkAnmFunc data_02136910;
void func_020fad6c(UnkAnmObj *obj, const UnkResVisAnm *anm, const UnkResMdl *mdl) {
    u32 i;

    obj->funcAnm    = data_02136910;
    obj->numMapData = mdl->info.numNode;
    obj->resAnm     = (void *) anm;

    for (i = 0; i < obj->numMapData; i++) {
        obj->mapData[i] = (u16) (i | 0x100);
    }
}
