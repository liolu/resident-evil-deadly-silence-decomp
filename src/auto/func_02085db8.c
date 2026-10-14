/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02088158(void);

extern M2C_UNK data_021374cc;

void func_02085db8(void) {
    if (func_02088158() == 0) {
        M2C_FIELD(&data_021374cc, s16 *, 0x20) = 0;
        M2C_FIELD(&data_021374cc, s16 *, 0x22) = 0;
    }
}
