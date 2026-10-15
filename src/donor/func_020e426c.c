/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* ADXCRS_Finish from https://github.com/Yotona/twewy libs/cri/src/adx_crs.c (license: CC0-1.0), reused by tools/donor_match.py
 */
extern volatile int data_02151eac;
extern volatile int data_02151eb0;
void func_020e426c(void) {
    data_02151eb0--;
    if (data_02151eb0 == 0) {
        data_02151eac = 0;
    }
}
