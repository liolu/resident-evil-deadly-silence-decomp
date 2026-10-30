/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02071254 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSystem/src/g3d/g3d_si3d.c (license: none), reused
 * by tools/donor_match.py */
typedef unsigned int u32;
typedef long long s64;
typedef int s32;
typedef s32 BOOL;
typedef long fx32;
typedef struct {
    fx32 x;
    fx32 y;
    fx32 z;
} UnkVecFx32;
typedef struct {
    fx32 m[3][3];
} UnkMtxFx33;
typedef struct {
    u32 flag;
    UnkVecFx32 scale;
    UnkVecFx32 scaleEx0;
    UnkVecFx32 scaleEx1;
    UnkMtxFx33 rot;
    UnkVecFx32 trans;
} UnkJntAnmResult;
extern void func_020f7b18(u32 op, const void *args, u32 num);
void func_020fbac8(const UnkJntAnmResult *result) {
    BOOL trFlag = 0;
    u32 exFlag  = result->flag & 0x18;

    if (exFlag == 0) {
        func_020f7b18(0x1b, &result->scaleEx1, 3);
    }

    if (!(result->flag & 4)) {
        if (exFlag != 0) {
            trFlag = 1;
        } else {
            UnkVecFx32 tmp;
            tmp.x = ((fx32) (((s64) (result->trans.x) * (result->scaleEx0.x)) >> 12));
            tmp.y = ((fx32) (((s64) (result->trans.y) * (result->scaleEx0.y)) >> 12));
            tmp.z = ((fx32) (((s64) (result->trans.z) * (result->scaleEx0.z)) >> 12));
            func_020f7b18(0x1c, &tmp, 3);
        }
    }

    if (!(result->flag & 2)) {
        if (trFlag) {
            func_020f7b18(0x19, &result->rot, 12);
        } else {
            func_020f7b18(0x1a, &result->rot, 9);
        }
    } else {
        if (trFlag) {
            func_020f7b18(0x1c, &result->trans, 3);
        }
    }

    if (exFlag == 0) {
        func_020f7b18(0x1b, &result->scaleEx0, 3);
    }

    if (!(result->flag & 1)) {
        func_020f7b18(0x1b, &result->scale, 3);
    }
}
