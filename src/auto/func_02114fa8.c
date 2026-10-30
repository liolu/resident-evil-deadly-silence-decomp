/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_021400ec from https://github.com/RonyxDumb/mkds src/arm9/021400ec_func_021400ec.c (license: none), reused by
 * tools/donor_match.py */
extern double func_021164f0(double x, double y);
double func_02114fa8(double x, int *eptr) {
    int hi = ((int *) (&x))[1];
    int lo = ((int *) (&x))[0];
    int ix;
    *eptr = 0;
    ix    = hi & 0x7fffffff;
    if ((ix >= 0x7ff00000) || ((ix | lo) == 0)) {
        return x;
    }
    if (ix < 0x100000) {
        x     = func_021164f0(x, 0x1.0p54);
        hi    = ((int *) (&x))[1];
        *eptr = -54;
        ix    = hi & 0x7fffffff;
    }
    *eptr += (ix >> 20) - 0x3fe;
    hi                = (hi & 0x800fffff) | 0x3fe00000;
    ((int *) (&x))[1] = hi;
    return x;
}
