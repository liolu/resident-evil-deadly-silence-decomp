/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);
typedef struct {
    Fn *p;
    u32 pad[3];
} Ent;
extern Ent data_02152e10[];

void func_020e56ac(void) {
    s32 i;
    Fn *p;
    Fn f;

    i = 0;
    do {
        p = data_02152e10[i].p;
        if (p != NULL) {
            f = *p;
            if (f != NULL) {
                f();
            }
        }
        i += 1;
    } while (i < 0x20);
}
