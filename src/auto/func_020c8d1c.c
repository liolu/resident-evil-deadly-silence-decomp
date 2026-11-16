/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 data_027e000c;
extern u8 data_0213b890;
extern void (*data_02125878[])(void);
void func_0205206c(void);
void func_02053178(void);
void func_020c8b4c(void);

void func_020c8d1c(void) {
    if (*(u8 **) ((u8 *) &data_0213b890 + 0x4C) != NULL && *(s32 *) (*(u8 **) ((u8 *) &data_0213b890 + 0x4C) + 0x18) != 0) {
        data_027e000c = *(s32 *) (*(u8 **) ((u8 *) &data_0213b890 + 0x4C) + 0x1C);
        func_0205206c();
        data_027e000c = *(s32 *) (*(u8 **) ((u8 *) &data_0213b890 + 0x4C) + 0x18);
        func_02053178();
    }
    if (*((u8 *) &data_0213b890 + 0x1F) == 1) {
        func_020c8b4c();
    }
    data_02125878[*((u8 *) &data_0213b890 + 0x20)]();
}
