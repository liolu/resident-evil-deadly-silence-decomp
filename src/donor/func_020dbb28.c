/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_020b7f98 from projets/simpsons-game/src/donor/func_020b7f98.c (same code in another game of this workspace), reused by
 * tools/donor_match.py */
#pragma cplusplus off
#pragma ipa file
void func_020dbb28(void *dest, const void *src, int count) {
    short *_dest      = dest;
    const short *_src = src;

    while (count > 0) {
        *_dest++ = *_src++;
        count -= 1;
    }
}
