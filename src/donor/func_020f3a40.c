/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020730c8 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/gfd/gfd_lnkpltt.c (license: none),
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
extern BOOL func_020f32ac(UnkLnkVramMan *pMgr, UnkLnkVramBlock **ppBlockPool, u32 baseAddr, u32 szByte);
typedef struct {
    UnkLnkVramMan mgr;
    UnkLnkVramBlock *pBlockPool;
    u32 szByte;
    void *pWork;
    u32 szWork;
} UnkLnkPlttVramManager;
extern UnkLnkPlttVramManager data_02154390;
extern int func_020f3a40(u32 plttKey);
int func_020f3a40(u32 plttKey) {
    u32 addr    = (plttKey & 0xffff) << 3;
    u32 szByte  = ((plttKey & 0xffff0000) >> 16) << 3;
    BOOL result = func_020f32ac(&data_02154390.mgr, &data_02154390.pBlockPool, addr, szByte);

    return result ? 0 : 1;
}
