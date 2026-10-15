/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02072cb4 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/gfd/gfd_lnktex.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef int s32;
typedef s32 BOOL;
typedef struct UnkLnkVramBlock {
    u32 addr;
    u32 szByte;
    struct UnkLnkVramBlock *pPrev;
    struct UnkLnkVramBlock *pNext;
} UnkLnkVramBlock;
typedef struct {
    UnkLnkVramBlock *pFreeList;
} UnkLnkVramMan;
extern BOOL func_020f354c(UnkLnkVramMan *pMgr, UnkLnkVramBlock **ppBlockPool, u32 *pRetAddr, u32 szByte);
typedef struct {
    UnkLnkVramMan mgr;
    UnkLnkVramMan mgrFor4x4;
    UnkLnkVramBlock *pBlockPool;
    u32 szByte;
    u32 szByteFor4x4;
    void *pWork;
    u32 szWork;
} UnkLnkTexVramManager;
extern UnkLnkTexVramManager data_02154374;
extern u32 func_020f38c4(u32 szByte, BOOL is4x4comp, u32 opt);
u32 func_020f38c4(u32 szByte, BOOL is4x4comp, u32 opt) {
    u32 addr;
    BOOL result;
    u32 sz = (szByte == 0) ? 16 : ((szByte + 15) & ~15);

    if (sz >= 0x7fff0) {
        return 0;
    }

    if (is4x4comp) {
        result = func_020f354c(&data_02154374.mgrFor4x4, &data_02154374.pBlockPool, &addr, sz);
    } else {
        result = func_020f354c(&data_02154374.mgr, &data_02154374.pBlockPool, &addr, sz);
    }
    if (!result) {
        return 0;
    }
    return ((sz >> 4) << 16) | ((addr >> 3) & 0xffff) | (is4x4comp << 31);
}
