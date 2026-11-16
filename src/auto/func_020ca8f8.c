/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    u8 b0;
    u8 b1;
} Mid;

typedef struct {
    u8 pad[0x4C];
    Mid *mid;
} Top;

void func_020b82fc(s32);
s32 func_020ca464(s32, s32);
extern Top data_0213b890;

void func_020ca8f8(s32 arg0) {
    s32 b;

    func_020b82fc(0xB1);
    b = data_0213b890.mid->b1;
    func_020ca464(arg0 == 9 ? -1 : 1, b);
}
