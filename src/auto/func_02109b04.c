/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 data_0215a7c0;
extern void func_02109b50(void);
void func_0210ca88(s32, s32, s32, s32, void (*)(void), s32, s32);

s32 func_02109b04(s32 arg0, s32 arg1, s32 arg2, s32 arg3) {
    func_0210ca88(data_0215a7c0, arg2, arg1, arg3, func_02109b50, arg0, 1);
    return 6;
}
