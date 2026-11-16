/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern M2C_UNK data_0211f754;
extern M2C_UNK data_0211f764;
extern M2C_UNK data_021375ac;

u8 func_02088708(void) {
    switch (M2C_FIELD(&data_021375ac, u8 *, 0x2A)) {
        default:
            return M2C_FIELD(&data_021375ac, u8 *, 0x2A);
        case 23:
            return *((u8 *) &data_0211f754 + M2C_FIELD(&data_021375ac, u8 *, 0x2B));
        case 24:
        case 25:
            return *((u8 *) &data_0211f764 + M2C_FIELD(&data_021375ac, u8 *, 0x2B));
    }
}
