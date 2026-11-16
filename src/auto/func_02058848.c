/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);
typedef struct {
    Fn f[3];
} T12;

extern M2C_UNK data_0212d004;
extern u8 data_0213746c;

void func_02058848(void) {
    T12 loc = *(T12 *) &data_0212d004;
    loc.f[data_0213746c]();
}
