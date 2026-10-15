/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_02017ed8(void);
void func_02018148(void);
void func_020c0110(M2C_UNK);
void func_020c3764(M2C_UNK);
void func_020d0bcc(void);
void func_020d0bf8(void);
void func_020d0de0(void);

extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213bae8;

void func_020d1040(void) {
    func_020c3764((s32) &data_0213bae8);
    func_020c3764(M2C_FIELD(&data_0213b890, s32 *, 0x4C));
    func_020c3764(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0x20);
    func_02018148();
    func_02017ed8();
    func_020d0bcc();
    func_020d0de0();
    if (M2C_FIELD(&data_0213b890, u8 *, 0x1E) != 0) {
        func_020d0bf8();
    }
    func_020c0110(M2C_FIELD(&data_0213b890, s32 *, 0x4C) + 0xFC);
}
