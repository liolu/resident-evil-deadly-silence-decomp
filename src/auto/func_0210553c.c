/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_01ffdb90(void);
void func_02102794(M2C_UNK);
M2C_UNK func_02102848(M2C_UNK);
M2C_UNK func_02102a50(void);
void func_02105528(void);
void func_021055bc(M2C_UNK);
void func_02105928(M2C_UNK);
void func_0210c0fc(M2C_UNK);

void func_0210553c(s32 arg0) {
    if (*(u16 *)0x027FFC40 == 2) {
        func_02105528();
    }
    func_0210c0fc((s32) (u16) func_02102a50());
    func_02105928(0);
    func_02105928(1);
    func_02105928(2);
    func_02105928(3);
    func_02102848(0x40000);
    func_02102794(-1);
    *(s32 *)0x027FFC20 = arg0;
    func_021055bc(0x10);
    func_01ffdb90();
}
