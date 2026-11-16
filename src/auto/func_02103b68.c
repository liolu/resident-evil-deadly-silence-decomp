/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_02103940(void);
void func_02103a8c(void *);
void func_02103be0(void);
void func_02103edc(void *);
void func_021044d0(s32);
s32 func_021054ac(void);
void func_021054c0(s32);
extern M2C_UNK data_02158894;
extern s32 data_021588a8[];

void func_02103b68(void *arg0) {
    s32 temp_r4;

    temp_r4 = func_021054ac();
    if (M2C_FIELD(&data_02158894, s32 *, 8) == (s32) arg0) {
        func_02103be0();
    }
    func_021044d0((s32) arg0);
    func_02103edc(arg0);
    data_021588a8[M2C_FIELD(arg0, s32 *, 0x6C)] = 0;
    M2C_FIELD(arg0, s32 *, 0x64)                = 2;
    func_02103a8c((u8 *) arg0 + 0x90);
    func_021054c0(temp_r4);
    func_02103940();
}
