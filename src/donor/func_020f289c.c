/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_020ae1f0 from projets/dragon-ball-origins/src/donor/func_020ae1f0.c (same code in another game of this workspace),
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
void func_020f289c(UnkFndList *list, void *obj) {
    UnkFndLink *link = ((UnkFndLink *) ((u32) (obj) + (list)->unk_0a));

    link->unk_04 = 0;
    link->unk_00 = 0;
    list->unk_00 = obj;
    list->unk_04 = obj;
    list->unk_08++;
}
