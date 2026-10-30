/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* scalbn from https://github.com/zeldaret/st libs/c/src/extras.c (license: CC0-1.0), reused by tools/donor_match.py */
extern double func_02114fa8(double x, int *eptr);
extern double func_02115068(double value, int exp);
extern double func_021101b8(double x, int n);
double func_021101b8(double x, int n) {
    double value;
    int exp;

    value = func_02114fa8(x, &exp);
    exp += n;

    return func_02115068(value, exp);
}
