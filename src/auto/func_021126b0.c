/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* strcat from https://github.com/Yokimitsuro/khrecoded-decomp libs/msl/c/calls/strcat.c (license: CC0-1.0), reused by
 * tools/donor_match.py */
char *func_021126b0(char *destination, const char *source) {
    unsigned char *output      = (unsigned char *) destination;
    const unsigned char *input = (const unsigned char *) source;

    while (*output++ != 0) {
    }
    output--;
    while ((*output++ = *input++) != 0) {
    }
    return destination;
}
