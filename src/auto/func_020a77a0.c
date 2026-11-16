/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void *);

void func_020ad960(void);
extern Handler data_0213aee4[];
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0213daa8;

void func_020a77a0(void *arg0) {
    if (M2C_FIELD(arg0, u8 *, 0x93) == 0) {
        if ((M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x40) || (M2C_FIELD(arg0, u8 *, 0xC0) & 0x80)) {
            M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) (M2C_FIELD(&data_0213daa8, u16 *, 0x74) | 0x40);
        }
        M2C_FIELD(arg0, u8 *, 0xC0) = (u8) (M2C_FIELD(arg0, u8 *, 0xC0) & ~0x80);
        func_020ad960();
    }
    data_0213aee4[M2C_FIELD(arg0, u8 *, 0x91)](arg0);
}
