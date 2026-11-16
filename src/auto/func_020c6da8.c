/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern u8 data_0213b890[];

void func_020c6da8(void) {
    data_0213b890[0x23]                                               = (u8) (data_0213b890[0x23] + 1);
    *(u8 *) (*(u8 **) (data_0213b890 + 0x4C) + 0x96)                  = 0x81;
    *(u8 *) (*(u8 **) (data_0213b890 + 0x4C) + 0xB2)                  = 0x81;
    *(u8 *) (*(u8 **) (data_0213b890 + 0x4C) + 0xE8)                  = 0;
    *(u8 *) (*(u8 **) (data_0213b890 + 0x4C) + 0x49)                  = 0x32;
    *(u8 *) (*(u8 **) (*(u8 **) (data_0213b890 + 0x4C) + 0x18) + 0xA) = 0x40;
    *(u8 *) (*(u8 **) (*(u8 **) (data_0213b890 + 0x4C) + 0x1C) + 0xA) = 0x40;
}
