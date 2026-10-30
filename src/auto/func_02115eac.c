/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* __cnt_trail_zeros from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/msl/__cnt_trail_zeros.c (license:
 * CC0-1.0), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned int u32;
extern int func_02115eac(u32 value);
int func_02115eac(u32 value) {
    u8 *byte;
    int zeros;

    if (value != 0) {
        byte  = (u8 *) &value;
        zeros = 0;
        while (*byte == 0) {
            byte++;
            zeros += 8;
        }
        *byte = ~*byte;
        while (*byte & 1) {
            zeros++;
            *byte >>= 1;
        }
        return zeros;
    }
    return 32;
}
