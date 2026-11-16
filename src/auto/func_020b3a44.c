/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

typedef s32 (*Handler)(void);

typedef struct {
    u8 kind;
    u8 pad[7];
} Entry;

s32 func_020b1fbc(s32, Entry *);
extern Entry data_02122648[];
extern Handler data_02122834[];
extern s32 data_0213daa8;

s32 func_020b3a44(s32 arg0) {
    u8 var_r3;

    var_r3 = 0;
    while (data_02122648[var_r3].kind != 0x5A) {
        if (arg0 == data_02122648[var_r3].kind) {
            data_0213daa8 += func_020b1fbc(data_0213daa8, &data_02122648[var_r3]);
            return 1;
        }
        var_r3 += 1;
    }
    return data_02122834[arg0]();
}
