/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void *);

s32 func_01ffd2c4(M2C_UNK *, M2C_UNK);              /* extern */
extern Handler data_0211c59c[];
extern M2C_UNK data_02144c34;
extern s32 data_027e0010;
extern s32 data_027e0014;

void func_0202ae6c(void *arg0) {
    data_027e0010 = func_01ffd2c4(&data_02144c34, 0x100);
    data_027e0014 = func_01ffd2c4(&data_02144c34, 0x200);
    data_0211c59c[M2C_FIELD(arg0, u8 *, 0x92)](arg0);
}
