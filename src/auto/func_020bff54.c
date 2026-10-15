/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

void func_020038b8(M2C_UNK);
void func_02003b00(M2C_UNK);
M2C_UNK func_02005fcc(M2C_UNK);
void func_0200f768(M2C_UNK);
void func_02013638(M2C_UNK, M2C_UNK, M2C_UNK);
void func_020b7270(void);
void func_020be868(void);
void func_020beb20(void);
void func_020bf6e0(void);
void func_020c01c0(void);
void func_020c3c0c(M2C_UNK, M2C_UNK, M2C_UNK, M2C_UNK);
void func_020c4798(M2C_UNK);
void func_020ff204(M2C_UNK, M2C_UNK, M2C_UNK);

extern M2C_UNK data_02124b20;
extern M2C_UNK data_02124b30;
extern M2C_UNK data_02124c68;
extern M2C_UNK data_02124c90;
extern M2C_UNK data_0213b890;
extern M2C_UNK data_0213b8ac;
extern M2C_UNK data_027e01ac;

void func_020bff54(void) {
    func_020ff204(1, 0, 0);
    func_0200f768(0xA);
    func_02005fcc((s32) &data_02124c68);
    func_020c3c0c((s32) &data_0213b8ac, (s32) func_020be868, 0, 0x838);
    M2C_FIELD(&data_027e01ac, s16 *, 0x20)                          = 0xE4;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x16) = 1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x15) = -1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x17) = -1;
    M2C_FIELD(M2C_FIELD(&data_0213b890, void **, 0x4C), s8 *, 0x18) = 0;
    func_02013638(0, 0, (s32) &data_02124c90);
    func_02013638(1, 0, (s32) &data_02124b30);
    func_020c01c0();
    func_020038b8((s32) &data_02124b20);
    func_020b7270();
    func_020c4798(1);
    func_02003b00(2);
    func_020beb20();
    func_020bf6e0();
}
