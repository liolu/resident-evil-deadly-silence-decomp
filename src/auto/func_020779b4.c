/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct G {
    u8 pad0[0xB4];
    u8 fB4;
    u8 pad1[3];
    s32 fB8;
} G;

typedef void (*Fn)(s32);

void func_02077794(s32);
extern Fn data_0211e700[];
extern G data_0213b2b4;

void func_020779b4(void) {
    data_0211e700[data_0213b2b4.fB4](data_0213b2b4.fB8);
    func_02077794(data_0213b2b4.fB8);
}
