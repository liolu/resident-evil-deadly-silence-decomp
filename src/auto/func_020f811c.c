/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* NNS_G3dSearchSbcCmd from https://github.com/ntrtwl/NitroSystem libraries/g3d/src/util.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
extern int func_020f817c(const u8 *c);
extern const u8 *func_020f811c(const u8 *c, u8 cmd);
int func_020f817c(const u8 *c);
const u8 *func_020f811c(const u8 *c, u8 cmd) {
    int x;
    ((void) 0);
    ((void) 0);

    cmd &= 0x1f;
    while ((x = (*c & 0x1f)) != 0x01) {
        if (cmd == x) {
            return c;
        } else {
            int cmdLen = func_020f817c(c);
            ((void) 0);
            c += cmdLen;
        }
    }
    return 0;
}
