/* compiler: 2.0/sp1p5 -O4,p -lang c99 -ipa file -inline on,noauto */
/* func_02114c14 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/MSL/src/math/s_copysign.c (license: none), reused by
 * tools/donor_match.py */
extern double func_02114c14(double x, double y);
double func_02114c14(double x, double y)

{
    (((int *) &x)[1]) = ((((int *) &x)[1]) & 0x7FFFFFFF) | ((((int *) &y)[1]) & 0x80000000);
    return x;
}
