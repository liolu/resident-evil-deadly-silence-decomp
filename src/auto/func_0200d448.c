/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef struct {
    s32 a;
    s32 b;
    s32 c;
} T12;

extern T12 data_021372ac;
void func_0200df40(void *arg0);

void func_0200d448(s32 arg0, s32 arg1) {
    data_021372ac.b = arg0;
    data_021372ac.a = 0xA;
    data_021372ac.c = arg1;
    func_0200df40(&data_021372ac);
}
