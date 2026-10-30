/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206a3a0 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_kernel.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef unsigned char u8;
typedef int s32;
typedef struct UnkResAnmHeader {
    u8 unk_00;
    u8 unk_01;
    u16 unk_02;
} UnkResAnmHeader;
typedef void (*UnkAnmFunc)(void *result, struct UnkAnmObj *anm, u32 dataIdx);
typedef struct UnkAnmObj {
    s32 unk_00;
    s32 unk_04;
    UnkResAnmHeader *unk_08;
    UnkAnmFunc unk_0c;
    struct UnkAnmObj *unk_10;
    void *unk_14;
    u8 unk_18;
    u8 unk_19;
    u16 unk_1a[1];
} UnkAnmObj;
void func_020f459c(UnkAnmObj **list, UnkAnmObj *anm) {
    UnkAnmObj *p = *list;

    if (p == 0) {
        *list = anm;
        return;
    }

    if (p->unk_10 == 0) {
        if (p->unk_18 > anm->unk_18) {
            UnkAnmObj *tail = anm;

            while (tail->unk_10 != 0) {
                tail = tail->unk_10;
            }
            tail->unk_10 = p;
            *list        = anm;
        } else {
            p->unk_10 = anm;
        }
    } else {
        UnkAnmObj *q = p->unk_10;

        while (q != 0) {
            if (q->unk_18 >= anm->unk_18) {
                UnkAnmObj *tail = anm;

                while (tail->unk_10 != 0) {
                    tail = tail->unk_10;
                }
                p->unk_10    = anm;
                tail->unk_10 = q;
                return;
            }
            p = q;
            q = q->unk_10;
        }
        p->unk_10 = anm;
    }
}
