/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_021046b8(M2C_UNK, M2C_UNK);
void func_02106a34(void);
void func_02106a48(void);

void func_02107944(s32 arg0) {
    void *temp_r6;
    void *var_r0;

    func_02106a48();
    var_r0 = M2C_FIELD(arg0, void **, 0x18);
    if (var_r0 != NULL) {
        do {
            temp_r6 = M2C_FIELD(var_r0, void **, 4);
            M2C_FIELD(var_r0, s32 *, 0) = 0;
            M2C_FIELD(var_r0, void **, 4) = NULL;
            func_021046b8((s32) var_r0, 8);
            var_r0 = temp_r6;
        } while (temp_r6 != NULL);
    }
    func_02106a34();
}
