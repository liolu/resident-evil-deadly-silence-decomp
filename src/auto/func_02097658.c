/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
void func_020984e0(void); /* extern */
extern void *data_02137894;
extern u8 *data_02137ed8;
extern Handler data_021205fc[];

s32 func_02097658(void) {
    u8 *temp_r2;

    temp_r2       = *(u8 **) ((u8 *) data_02137894 + 0x30);
    data_02137ed8 = temp_r2;
    data_021205fc[*temp_r2]();
    func_020984e0();
    if ((u32) *data_02137ed8 > 2U) {
        return 1;
    }
    return 0;
}
