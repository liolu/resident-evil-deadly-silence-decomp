/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern void (*data_02124e0c[])(void);
extern u8 data_0213b890[];
extern s16 data_027e01ac[];

void func_020c1258(void) {
    void (**tbl)(void) = (void (**)(void)) &data_02124e0c;
    u8 *st             = (u8 *) &data_0213b890;

    tbl[st[32]]();
    *(s16 *) ((u8 *) data_027e01ac + 18) = 6;
}
