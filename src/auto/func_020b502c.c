/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 *data_0214d068[];
extern u8 data_021489a0[];
void func_02017c64(void *);

void func_020b502c(u8 *arg0) {
    u8 *temp_r4;
    u16 temp_r2;

    temp_r4    = data_0214d068[*(u8 *) (*(u8 **) (arg0 + 8) + 0xA)];
    arg0[0]    = 0;
    temp_r4[8] = 0;
    temp_r2    = *(u16 *) (temp_r4 + 0x92);
    if (temp_r2 != 0) {
        func_02017c64(data_021489a0 + temp_r2 * 0xBC);
        *(u16 *) (temp_r4 + 0x92) = 0;
    }
}
