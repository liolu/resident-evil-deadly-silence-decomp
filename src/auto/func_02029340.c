/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

extern u8 data_027e0054;
extern u8 data_027e0090;

typedef struct {
    u32 w0;
    u32 w1;
    u32 w2;
    u32 w3;
} Blk48;

void func_01ff8020(u16 a, void *b);
void func_02018204(s32 a, s32 b, s32 c, void *d, void *e, s32 f);

void func_02029340(u8 *arg0, u32 arg1) {
    Blk48 tmp;

    if (arg1 != 0) {
        func_01ff8020(*(u16 *) (arg0 + 0x44), arg0 + 0x1C);
        tmp                       = *(Blk48 *) &data_027e0090;
        *(Blk48 *) &data_027e0054 = tmp;
        func_02018204(0x1C, 0, *(s16 *) (arg0 + 0x44), arg0 + 0x1C, &data_027e0054, 0);
        if (arg1 > 1) {
            func_02018204(0x1C, 0, *(s16 *) (arg0 + 0x44) + 0x400, arg0 + 0x1C, &data_027e0054, 0);
        }
    }
}
