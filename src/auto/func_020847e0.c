/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_02084810(u8, u8);                      /* extern */
M2C_UNK func_0208486c(u8);                          /* extern */
u8 func_020849ac(void *);                           /* extern */

void func_020847e0(void *arg0) {
    func_0208486c(M2C_FIELD(arg0, u8 *, 0x32));
    M2C_FIELD(arg0, u8 *, 0x32) = func_020849ac(arg0);
    func_02084810(M2C_FIELD(arg0, u8 *, 0x32), M2C_FIELD(arg0, u8 *, 4));
}
