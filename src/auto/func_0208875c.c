/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_021375ac[];
extern u8 data_0211f754[];
extern u8 data_0211f764[];

void func_0208875c(void *arg0, u8 *arg1, u8 *arg2) {
    if (data_021375ac[0x29] != 0xF) {
        return;
    }
    switch (data_021375ac[0x2A]) {
        case 0x17:
            *arg1 = data_0211f754[data_021375ac[0x2B]];
            *arg2 = 0;
            return;
        case 0x18:
        case 0x19:
            *arg1 = data_0211f764[data_021375ac[0x2B]];
            *arg2 = 0;
            return;
        default:
            *arg2 = 0;
            return;
    }
}
