/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020784dc from projets/nintendogs-dachshund/src/donor/func_020784dc.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef struct NNSG3dResDict {
    u8 revision;
    u8 numEntry;
    u16 sizeDictBlk;
    u16 unk_04;
    u16 ofsEntry;
} NNSG3dResDict;
typedef struct UnkResDictTreeNode {
    u8 refBit;
    u8 idx[2];
    u8 idxEntry;
} UnkResDictTreeNode;
typedef struct UnkResDictEntryHeader {
    u16 sizeUnit;
    u16 ofsName;
    u8 data[4];
} UnkResDictEntryHeader;
typedef struct NNSG3dResName {
    u32 val[4];
} NNSG3dResName;
static inline void *GetResDataByIdx(const NNSG3dResDict *dict, u32 idx) {
    UnkResDictEntryHeader *p = (UnkResDictEntryHeader *) ((u8 *) dict + dict->ofsEntry);
    return (void *) ((u8 *) &p->data[0] + p->sizeUnit * idx);
}
static inline const NNSG3dResName *GetResNameByIdx(const NNSG3dResDict *dict, u32 idx) {
    UnkResDictEntryHeader *p = (UnkResDictEntryHeader *) ((u8 *) dict + dict->ofsEntry);
    return (const NNSG3dResName *) ((u8 *) p + p->ofsName) + idx;
}
void *func_020f8908(const NNSG3dResDict *dict, const NNSG3dResName *name) {
    if (dict->numEntry < 16) {
        u32 i;
        u32 n0 = name->val[0];
        u32 n1 = name->val[1];
        u32 n2 = name->val[2];
        u32 n3 = name->val[3];
        for (i = 0; i < dict->numEntry; i++) {
            const NNSG3dResName *n = GetResNameByIdx(dict, i);
            if (n->val[0] == n0 && n->val[1] == n1 && n->val[2] == n2 && n->val[3] == n3) {
                return GetResDataByIdx(dict, i);
            }
        }
    } else {
        const UnkResDictTreeNode *tree = (const UnkResDictTreeNode *) ((u8 *) dict + 8);
        u32 idx                        = tree[0].idx[0];
        if (idx) {
            const UnkResDictTreeNode *prev = &tree[0];
            const UnkResDictTreeNode *p    = &tree[idx];
            while (prev->refBit > p->refBit) {
                prev = p;
                p    = &tree[p->idx[(name->val[p->refBit >> 5] >> (p->refBit & 0x1f)) & 1]];
            }
            {
                const NNSG3dResName *n = GetResNameByIdx(dict, p->idxEntry);
                if (n->val[0] == name->val[0] && n->val[1] == name->val[1] && n->val[2] == name->val[2] &&
                    n->val[3] == name->val[3]) {
                    return GetResDataByIdx(dict, p->idxEntry);
                }
            }
        }
    }
    return 0;
}
