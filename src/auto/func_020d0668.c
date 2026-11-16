/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void func_020b5540(s32);
extern u8 data_0213b890[];

void func_020d0668(void) {
    u8 i;
    u8 *ent;

    if (data_0213b890[0x1D] == 2) {
        data_0213b890[0x21] = 2;
        return;
    }
    i = 0;
    do {
        ent = (u8 *) (*(s32 *) (data_0213b890 + 0x4C) + 4) + i * 0x1C;
        if (ent[0xC] != 0xFF) {
            ent[1] = 8;
        }
        i = (u8) (i + 1);
    } while (i < 3);
    func_020b5540(1);
    *(s16 *) (data_0213b890 + 0x26) = 0x2D;
    data_0213b890[0x21]             = 1;
}
