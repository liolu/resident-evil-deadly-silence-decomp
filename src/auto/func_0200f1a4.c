/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_0200f078();                            /* extern */
M2C_UNK func_020765d4(M2C_UNK, M2C_UNK *, s32);     /* extern */
M2C_UNK func_02076724(M2C_UNK *);                   /* extern */
s32 func_02088648();                                /* extern */
M2C_UNK func_0208875c(M2C_UNK *, M2C_UNK *, M2C_UNK *); /* extern */
extern M2C_UNK data_0213ad28;
extern M2C_UNK data_0213ad29;
extern M2C_UNK data_0213ad2a;
extern M2C_UNK data_02143cc0;

void func_0200f1a4(void) {
    if (func_02088648() != 0) {
        func_0208875c(&data_0213ad28, &data_0213ad29, &data_0213ad2a);
    } else {
        func_02076724(&data_0213ad28);
    }
    func_020765d4(1, &data_0213ad28, M2C_FIELD(&data_02143cc0, s32 *, 0xF08));
    func_0200f078();
}
