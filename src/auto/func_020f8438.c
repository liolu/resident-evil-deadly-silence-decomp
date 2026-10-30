/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* ModelBlock_SetSomethingToAllMaterials_MaybeTraslucent from https://github.com/RonyxDumb/mkds
 * src/arm9/02012ffc_ModelBlock_SetSomethingToAllMaterials_MaybeTraslucent.c (license: none), reused by tools/donor_match.py */
extern unsigned int func_020f8630(unsigned int, unsigned int, unsigned int);
unsigned int func_020f8438(unsigned int r0, unsigned int r1, unsigned int r2, unsigned int r3) {
    unsigned int cmp_a, cmp_b, r4, r5, r6;
L_2013000:
    r6 = r0;
L_2013004:
    r0 = (unsigned int) (*(unsigned char *) ((unsigned char *) r6 + 24));
L_2013008:
    r5 = r1;
L_201300c:
    r4 = 0x0u;
L_2013010:
    cmp_a = r0;
    cmp_b = 0x0u;
L_2013018:
    if ((cmp_a <= cmp_b)) {
        return r0;
    }
L_201301c:
    r0 = r6;
L_2013020:
    r1 = r4;
L_2013024:
    r2 = r5;
L_2013028:
    r0 = func_020f8630(r0, r1, r2);
L_201302c:
    r0 = (unsigned int) (*(unsigned char *) ((unsigned char *) r6 + 24));
L_2013030:
    r4 = (r4 + 0x1u);
L_2013034:
    cmp_a = r4;
    cmp_b = r0;
L_2013038:
    if ((cmp_a < cmp_b)) {
        goto L_201301c;
    }
L_2013040:
    return r0;
}
