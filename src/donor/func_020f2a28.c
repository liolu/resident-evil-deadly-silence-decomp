/* compiler: 2.0/sp1p5  */
/* func_02027ae8 from projets/blue-dragon-awakened-shadow/src/auto/func_02027ae8.c (same code in another game of this
 * workspace), reused by tools/donor_match.py */
typedef signed char s8;
typedef long s32;
s32 func_020f2a28(s32 arg0) {
    s32 temp_r1;
    s32 var_r0;
    void *var_r2;

    var_r2 = (*(void **) ((s8 *) (arg0) + (0x24)));
    var_r0 = 0;
    if (var_r2 == ((void *) 0)) {
        return 0;
    }
    do {
        temp_r1 = (*(s32 *) ((s8 *) (var_r2) + (4)));
        var_r2  = (*(void **) ((s8 *) (var_r2) + (0xC)));
        var_r0 += temp_r1;
    } while (var_r2 != ((void *) 0));
    return var_r0;
}
