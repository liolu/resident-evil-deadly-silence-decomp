/* compiler: 1.2/b56 */
#include "m2c.h"

typedef struct {
    u8 pad0[4];
    u8 f4;
    u8 pad5[0x13];
    s16 f18;
    u8 pad1a[0x16];
    s16 f30;
} Obj;
extern s32 data_02137504;
extern Obj *data_02137508[];
s32 func_0208756c(Obj *arg0) {
    s32 temp_ip;

    arg0->f4 = 0;
    temp_ip  = data_02137504;
    if ((temp_ip < 8) && ((arg0->f18 != 0) || (arg0->f30 != 0))) {
        data_02137504++;
        data_02137508[temp_ip] = arg0;
        return 1;
    }
    return 0;
}
