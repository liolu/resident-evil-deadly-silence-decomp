/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);
typedef struct {
    Fn f[3];
} T12;

extern M2C_UNK data_0212f634;
extern M2C_UNK data_0213b890;

void func_020c3258(void) {
    T12 loc = *(T12 *) &data_0212f634;
    u8 *st  = (u8 *) &data_0213b890;
    loc.f[st[0x54]]();
}
