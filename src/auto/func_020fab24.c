/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02070858 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_anm_texpat.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef short s16;
typedef long fx32;
typedef s16 fx16;
typedef struct {
    u32 flag;
    u32 prmMatColor0;
    u32 prmMatColor1;
    u32 prmPolygonAttr;
    u32 prmTexImage;
    u32 prmTexPltt;
    fx32 scaleS;
    fx32 scaleT;
    fx16 sinR;
    fx16 cosR;
    fx32 transS;
    fx32 transT;
    u16 origW;
    u16 origH;
    fx32 magW;
    fx32 magH;
} UnkMatAnmResult;
typedef struct {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 dummy_;
    u16 ofsEntry;
} UnkResDict;
typedef struct {
    char name[16];
} UnkResName;
extern void *func_020f8908(const UnkResDict *dict, const UnkResName *name);
typedef struct {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;
    u16 dummy_;
    u32 ofsTex;
} UnkResTexInfo;
typedef struct {
    u32 vramKey;
    u16 sizeTex;
    u16 ofsDict;
    u16 flag;
    u16 dummy_;
    u32 ofsTex;
    u32 ofsTexPlttIdx;
} UnkResTex4x4Info;
typedef struct {
    u32 vramKey;
    u16 sizePltt;
    u16 flag;
    u16 ofsDict;
    u16 dummy_;
    u32 ofsPlttData;
} UnkResPlttInfo;
typedef struct {
    u32 kind;
    u32 size;
    UnkResTexInfo texInfo;
    UnkResTex4x4Info tex4x4Info;
    UnkResPlttInfo plttInfo;
    UnkResDict dict;
} UnkResTex;
typedef struct {
    u16 offset;
    u16 flag;
} UnkResDictPlttData;
void func_020fab24(const UnkResTex *tex, const UnkResName *name, UnkMatAnmResult *result) {
    const UnkResDictPlttData *data = func_020f8908((const UnkResDict *) ((const u8 *) tex + tex->plttInfo.ofsDict), name);
    u16 base                       = (u16) tex->plttInfo.vramKey;
    u16 offset                     = data->offset;

    if (!(data->flag & 1)) {
        offset = (u16) (offset >> 1);
        base   = (u16) (base >> 1);
    }
    result->prmTexPltt = offset + base;
}
