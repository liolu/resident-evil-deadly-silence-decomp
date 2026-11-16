/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);

M2C_UNK func_020984e0();                            /* extern */
extern Fn data_021205f0[];
extern u8 *data_02137ed8;
extern M2C_UNK data_0213b890;

s32 func_020976b8(void) {
    u8 *p;

    p             = (u8 *) M2C_FIELD(&data_0213b890, void **, 0x4C);
    data_02137ed8 = p;
    data_021205f0[*p]();
    func_020984e0();
    if ((u32) *data_02137ed8 > 2U) {
        return 1;
    }
    return 0;
}
