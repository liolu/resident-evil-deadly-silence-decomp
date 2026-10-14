/* compiler: 1.2/sp2p3  */
#include "m2c.h"

M2C_UNK func_021126b0(void *, void *);              /* extern */
M2C_UNK func_02112754(void *, M2C_UNK *);           /* extern */
extern M2C_UNK data_02152ab0;

void func_020e531c(void *arg0, void *arg1) {
    s8 temp_r1;

    if (arg1 == NULL) {
        func_02112754(arg0, &data_02152ab0);
    } else {
        temp_r1 = M2C_FIELD(arg1, s8 *, 0);
        if (temp_r1 == 0) {
            func_02112754(arg0, &data_02152ab0);
        } else if (temp_r1 == 0x5C) {
            M2C_FIELD(arg0, s8 *, 0) = (s8) M2C_FIELD(&data_02152ab0, s8 *, 0);
            M2C_FIELD(arg0, s8 *, 1) = (s8) M2C_FIELD(&data_02152ab0, s8 *, 1);
            M2C_FIELD(arg0, s8 *, 2) = 0;
        } else if (M2C_FIELD(arg1, s8 *, 1) == 0x3A) {
            M2C_FIELD(arg0, s8 *, 0) = 0;
        } else {
            func_02112754(arg0, &data_02152ab0);
        }
    }
    if (arg1 == NULL) {
        return;
    }
    func_021126b0(arg0, arg1);
}
