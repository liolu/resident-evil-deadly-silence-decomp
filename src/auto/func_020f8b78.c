/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0206fe00 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_anm_jnt_rot.c (license: none),
 * reused by tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
typedef short s16;
typedef s32 BOOL;
typedef long fx32;
typedef s16 fx16;
typedef struct {
    fx32 m[3][3];
} UnkMtxFx33;
extern const u8 data_02127bd0[][4];
extern BOOL func_020f8b78(UnkMtxFx33 *rot, const fx16 *pivotData, const fx16 *rot5Data, u32 info);
BOOL func_020f8b78(UnkMtxFx33 *rot, const fx16 *pivotData, const fx16 *rot5Data, u32 info) {
    if (info & 0x8000) {
        fx32 *m = &rot->m[0][0];
        u32 idxPivot;
        const fx16 *data;
        fx32 A;
        fx32 B;

        rot->m[0][0] = rot->m[0][1] = rot->m[0][2] = rot->m[1][0] = rot->m[1][1] = rot->m[1][2] = rot->m[2][0] = rot->m[2][1] =
            rot->m[2][2]                                                                                       = 0;

        data     = pivotData + (info & 0x7fff) * 3;
        idxPivot = data[0] & 0xf;
        A        = data[1];
        B        = data[2];

        m[idxPivot]                   = (data[0] & 0x10) ? -0x1000 : 0x1000;
        m[data_02127bd0[idxPivot][0]] = A;
        m[data_02127bd0[idxPivot][1]] = B;
        m[data_02127bd0[idxPivot][2]] = (data[0] & 0x20) ? -B : B;
        m[data_02127bd0[idxPivot][3]] = (data[0] & 0x40) ? -A : A;
        return 0;
    } else {
        const fx16 *data = rot5Data + (info & 0x7fff) * 5;
        s32 v;
        s16 t;

        v            = data[4];
        rot->m[1][1] = v >> 3;
        t            = (s16) (v & 7);
        v            = data[0];
        rot->m[0][0] = v >> 3;
        t            = (s16) ((t << 3) | (v & 7));
        v            = data[1];
        rot->m[0][1] = v >> 3;
        t            = (s16) ((t << 3) | (v & 7));
        v            = data[2];
        rot->m[0][2] = v >> 3;
        t            = (s16) ((t << 3) | (v & 7));
        v            = data[3];
        rot->m[1][0] = v >> 3;
        t            = (s16) ((t << 3) | (v & 7));
        rot->m[1][2] = ((s32) t << 19) >> 19;
        return 1;
    }
}
