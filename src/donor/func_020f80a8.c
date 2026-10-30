/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* NNS_G3dGetParentNodeID from https://github.com/ntrtwl/NitroSystem libraries/g3d/src/util.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned long u32;
extern int func_020f817c(const u8 *c);
extern const u8 *func_020f811c(const u8 *c, u8 cmd);
extern const u8 *func_020f80a8(int *parentID, const u8 *sbc, u32 nodeID);
int func_020f817c(const u8 *c);
const u8 *func_020f811c(const u8 *c, u8 cmd);
const u8 *func_020f80a8(int *parentID, const u8 *sbc, u32 nodeID) {
    const u8 *tmp = sbc;

    ((void) 0);
    ((void) 0);
    ((void) 0);

    while ((tmp = func_020f811c(tmp, 0x06)) != 0) {
        if (*(tmp + 1) == nodeID) {
            *parentID = *(tmp + 2);
            return tmp;
        }

        {
            int cmdLen = func_020f817c(tmp);
            ((void) 0);
            tmp += cmdLen;
        }
    }
    return 0;
}
