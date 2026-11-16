/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_02122c64;
extern M2C_UNK data_0213ad98;

u16 func_020b5938(u8 arg0) {
    u8 *st     = (u8 *) &data_0213ad98;
    u32 *outer = (u32 *) &data_02122c64;
    u32 *inner = (u32 *) outer[st[0]];
    u16 *tab   = (u16 *) inner[st[1]];
    return tab[arg0 & 0x3f];
}
