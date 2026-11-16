/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02004e00(void *p);
s32 func_02102a50(void);
void func_02105528(void);
void func_021060a4(s32 a, void *b, u32 c);
void func_0210ca04(void);
void func_021100c4(void *p, s32 v);
extern u8 data_0211b080[];
extern u8 data_02136eb0[];
extern u8 data_02136fb0[];
extern u8 data_0213705c[];

void func_02004fb4(void) {
    volatile s32 sp0;
    s32 result;

    sp0 = 0;
    func_021060a4(sp0, data_02136eb0, 0x3B4);
    func_02004e00(data_0211b080);
    func_021100c4(data_0213705c, 0xA001);
    func_0210ca04();
    result = func_02102a50();
    if (result == -3) {
        func_02105528();
    }
    *(s16 *) (data_02136fb0 + 0xA6) = (s16) result;
}
