/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02067e30 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/fnd/fnd_list.c (license: none), reused
 * by tools/donor_match.py */
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
extern void func_020f2834(UnkFndList *list, void *obj);
void func_020f289c(UnkFndList *list, void *obj);
void func_020f2834(UnkFndList *list, void *obj) {
    if (list->unk_00 == 0) {
        func_020f289c(list, obj);
    } else {
        UnkFndLink *link = ((UnkFndLink *) ((u32) (obj) + (list)->unk_0a));

        link->unk_00                                                     = list->unk_04;
        link->unk_04                                                     = 0;
        ((UnkFndLink *) ((u32) (list->unk_04) + (list)->unk_0a))->unk_04 = obj;
        list->unk_04                                                     = obj;
        list->unk_08++;
    }
}
