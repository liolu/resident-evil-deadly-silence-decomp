/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);
typedef struct {
    Fn f[4];
} T16;

extern M2C_UNK data_0212f66c;
extern M2C_UNK data_0213b890;

void func_020ca234(void) {
    T16 loc = *(T16 *) &data_0212f66c;
    u8 *st  = (u8 *) &data_0213b890;
    loc.f[st[0x21]]();
}
