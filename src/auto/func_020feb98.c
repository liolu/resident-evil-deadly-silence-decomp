/* compiler: 1.2/sp2p3 */
#include "engine.h"
#include "m2c.h"

u64 func_020feb98(void) {
    while (*(volatile u16 *) 0x04000280 & 0x8000) {
    }
    return *(volatile u64 *) 0x040002A0;
}
