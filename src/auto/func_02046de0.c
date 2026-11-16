/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02074ad4(s16 a, s16 b, void *c, void *d);
s32 func_020d9650(void);
typedef void (*Fn)(void);
extern Fn data_0211cc3c[];
extern u8 data_02143cc0[];
extern void *data_027e000c;
extern s32 data_027e0024;

void func_02046de0(void) {
    data_027e0024 = func_020d9650();
    func_02074ad4((s16) * (s32 *) (data_02143cc0 + 0xF74), (s16) * (s32 *) (data_02143cc0 + 0xF7C),
                  (u8 *) data_027e000c + 0x176, (u8 *) data_027e000c + 0x178);
    data_0211cc3c[((u8 *) data_027e000c)[0x92]]();
}
