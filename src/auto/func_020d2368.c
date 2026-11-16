/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef struct {
    u8 pad[0x1c];
    u8 a;
    u8 b;
} St;
extern St data_0213b890;

void func_020d2368(void) {
    data_0213b890.a = (u32) data_0213b890.b >> 1;
    if (data_0213b890.a > 4) {
        data_0213b890.a = 4;
    }
}
