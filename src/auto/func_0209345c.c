/* compiler: 1.2/sp2p3 */
#include "m2c.h"

M2C_UNK func_021060a4(s32, M2C_UNK *, s32);         /* extern */
M2C_UNK func_021061d8(M2C_UNK *, M2C_UNK, M2C_UNK); /* extern */
M2C_UNK func_0210960c(M2C_UNK *, M2C_UNK *);        /* extern */
M2C_UNK func_02109838(M2C_UNK *);                   /* extern */
extern M2C_UNK data_02120330;
extern void *data_0212e800[];
extern M2C_UNK data_02137e8c;
extern M2C_UNK data_02137ed0;
extern M2C_UNK data_0213ad48;
extern M2C_UNK data_0213b3c0;
extern M2C_UNK data_0213e394;

void func_0209345c(void) {
    volatile s32 sp0;

    sp0 = 0;
    func_021060a4(sp0, &data_0213e394, 0xF54);
    func_021061d8(&data_0213b3c0, 0, 0x10C);
    func_0210960c(&data_0213b3c0, &data_02120330);
    func_0210960c(&data_02137ed0, data_0212e800[M2C_FIELD(&data_0213ad48, u8 *, 3)]);
    func_02109838(&data_02137e8c);
}
