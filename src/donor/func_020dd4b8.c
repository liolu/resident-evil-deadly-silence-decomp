/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* ADXCRS_Init from https://github.com/Yotona/twewy libs/cri/src/adx_crs.c (license: CC0-1.0), reused by tools/donor_match.py
 */
extern volatile int data_0214f1b8;
extern volatile int data_0214f1bc;
void func_020dd4b8(void) {
    data_0214f1bc++;
    if (data_0214f1bc == 1) {
        data_0214f1b8 = 0;
    }
}
