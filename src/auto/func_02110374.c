/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* __copy_mem from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/msl/__copy_mem.c (license: CC0-1.0),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned int u32;
extern void *func_02110374(void *dest, const void *src, u32 count);
void *func_02110374(void *dest, const void *src, u32 count) {
    u8 *d       = dest;
    const u8 *s = src;

    while (count != 0) {
        *d++ = *s++;
        count--;
    }
    return dest;
}
