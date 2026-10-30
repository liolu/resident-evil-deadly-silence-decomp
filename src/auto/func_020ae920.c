/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK *func_0207979c(M2C_UNK);                    /* extern */
extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;

M2C_UNK *func_020ae920(void) {
    M2C_UNK *var_r0;

    switch (M2C_FIELD(&data_0213ad98, u8 *, 1)) {   /* irregular */
        case 1:
            var_r0 = (M2C_UNK *) M2C_FIELD(&data_0213ad98, u8 *, 0);
            if (var_r0 == NULL) {
                var_r0 = (M2C_UNK *) (M2C_FIELD(&data_0213bdcc, s32 *, 0x48) & 0x20000);
                if (var_r0 != NULL) {
                    func_0207979c(0x15);
                    func_0207979c(0x21);
                    func_0207979c(0x22);
                    return func_0207979c(0x27);
                }
            }
            return var_r0;
        case 8:
            var_r0 = (M2C_UNK *) M2C_FIELD(&data_0213ad98, u8 *, 0);
            if (var_r0 == NULL) {
                func_0207979c(0x15);
                func_0207979c(0x21);
                func_0207979c(0x22);
                return func_0207979c(0x27);
            }
        /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_r0;
        case 12:
            func_0207979c(0x13);
            var_r0 = func_0207979c(0x1B);
        /* Duplicate return node #10. Try simplifying control flow for better match */
            return var_r0;
        default:
            return &data_0213ad98;
    }
}
