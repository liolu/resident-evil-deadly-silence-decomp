/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* NNS_GfdAllocLnkPlttVram from https://github.com/RonyxDumb/mkds src/arm9/02017138_func_02017138.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long u32;
typedef int BOOL;
typedef u32 NNSGfdPlttKey;
inline u32 NNSi_GfdGetPlttKeyRoundupSize(u32 size) {
    if (size == 0) {
        return (0x1 << 3);
    } else {
        return (((u32) (size) + ((0x1 << 3) - 1)) & ~((0x1 << 3) - 1));
    }
}
inline NNSGfdPlttKey NNS_GfdMakePlttKey(u32 addr, u32 size) {
    ((void) 0);
    ((void) 0);

    ((void) 0);
    ((void) 0);

    return ((size >> 3) << 16) | (0xFFFF & (addr >> 3));
}
extern NNSGfdPlttKey func_020f3a98(u32 szByte, BOOL b4Pltt, u32 opt);
typedef struct NNSiGfdLnkVramBlock NNSiGfdLnkVramBlock;
struct NNSiGfdLnkVramBlock {
    u32 addr;
    u32 szByte;
    NNSiGfdLnkVramBlock *pBlkPrev;
    NNSiGfdLnkVramBlock *pBlkNext;
};
typedef struct NNSiGfdLnkVramMan {
    NNSiGfdLnkVramBlock *pFreeList;
} NNSiGfdLnkVramMan;
extern BOOL func_020f3408(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 *pRetAddr, u32 szByte,
                          u32 alignment);
extern BOOL func_020f32ac(NNSiGfdLnkVramMan *pMan, NNSiGfdLnkVramBlock **ppBlockPoolList, u32 addr, u32 szByte);
typedef struct NNS_GfdLnkPlttVramManager {
    NNSiGfdLnkVramMan mgr;
    NNSiGfdLnkVramBlock *pBlockPoolList;
    u32 szByte;
    NNSiGfdLnkVramBlock *pWorkHead;
    u32 szByteManagementWork;
} NNS_GfdLnkPlttVramManager;
extern NNS_GfdLnkPlttVramManager data_02154390;
NNSGfdPlttKey func_020f3a98(u32 szByte, BOOL b4Pltt, u32 opt) {

#pragma unused(opt)
#line 69
    u32 addr;
    BOOL result;

    {
        szByte = NNSi_GfdGetPlttKeyRoundupSize(szByte);

        if (szByte >= (0xFFFF << 3)) {
            ((void) 0);
            return (u32) 0x0;
        }

        ((void) 0);
    }

    if (b4Pltt) {
        result = func_020f3408(&data_02154390.mgr, &data_02154390.pBlockPoolList, &addr, szByte, 0x08);

        if (addr + szByte > 0x10000) {
            if (!func_020f32ac(&data_02154390.mgr, &data_02154390.pBlockPoolList, addr, szByte)) {
            }

            return (u32) 0x0;
        }
    } else {
        result = func_020f3408(&data_02154390.mgr, &data_02154390.pBlockPoolList, &addr, szByte, 0x10);
    }

    if (result) {
        return NNS_GfdMakePlttKey(addr, szByte);
    } else {
        ((void) 0);
        return (u32) 0x0;
    }
}
