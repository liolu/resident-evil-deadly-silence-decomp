/* compiler: 1.2/sp2p3  */
#include "m2c.h"

void func_0210ad1c(void **arg0, void *arg1) {
    void *var_r0;
    void *var_r2;

    if (arg0 == NULL) {
        return;
    }
    var_r2 = *arg0;
    if (var_r2 == NULL) {
        M2C_FIELD(arg1, void **, 8) = NULL;
        *arg0 = arg1;
        return;
    }
    var_r0 = M2C_FIELD(var_r2, void **, 8);
    if (var_r0 != NULL) {
        do {
            var_r2 = var_r0;
            var_r0 = M2C_FIELD(var_r0, void **, 8);
        } while (var_r0 != NULL);
    }
    M2C_FIELD(arg1, void **, 8) = var_r0;
    M2C_FIELD(var_r2, void **, 8) = arg1;
}
