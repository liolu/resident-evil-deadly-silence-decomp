/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02107b0c(void);
M2C_UNK func_02107cf0(M2C_UNK, M2C_UNK);
void func_02107d18(M2C_UNK, M2C_UNK);
void func_0210fca0(void);
void func_0210fd00(M2C_UNK, M2C_UNK);
void func_0210fd60(M2C_UNK, M2C_UNK);
void func_0210fd9c(void);

extern s32 data_0215bcc8;
extern s32 data_0215bccc;

void func_0210ff68(void) {
    if (data_0215bcc8 != 0) {
        return;
    }
    data_0215bcc8 = 1;
    func_0210fca0();
    func_02107b0c();
    do {

    } while (func_02107cf0(0xD, 1) == 0);
    func_02107d18(0xD, (s32) func_0210fd60);
    func_0210fd9c();
    func_02107d18(0xD, 0);
    func_02107d18(0xD, (s32) func_0210fd00);
    data_0215bccc = 0;
}
