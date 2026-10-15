/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206802c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/fnd/fnd_heapcommon.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct UnkFndLink {
    void *unk_00;
    void *unk_04;
} UnkFndLink;
typedef struct UnkFndList {
    void *unk_00;
    void *unk_04;
    u16 unk_08;
    u16 unk_0a;
} UnkFndList;
typedef struct UnkFndHeapHead {
    u32 unk_00;
    UnkFndLink unk_04;
    UnkFndList unk_0c;
    void *unk_18;
    void *unk_1c;
    u32 unk_20;
} UnkFndHeapHead;
extern UnkFndList data_02154368;
UnkFndHeapHead *func_020f29b8(UnkFndList *list, const void *memBlock);
UnkFndList *func_020f298c(void *heap) {
    UnkFndList *list            = &data_02154368;
    UnkFndHeapHead *containHeap = func_020f29b8(list, heap);

    if (containHeap != 0) {
        list = &containHeap->unk_0c;
    }
    return list;
}
