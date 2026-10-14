/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

M2C_UNK func_02088580(void);

s32 func_02083e20(void) {
    void *temp_r0;

    temp_r0 = (void *) func_02088580();
    return (s32) (u8) (M2C_FIELD(temp_r0, u8 *, 0xE8) - M2C_FIELD(temp_r0, u8 *, 0xE9));
}
