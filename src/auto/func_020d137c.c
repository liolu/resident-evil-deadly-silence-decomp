#include "m2c.h"
typedef struct {
    u8 pad[0x45];
    u8 flag;
} Sub;
typedef struct {
    u8 pad[0x4c];
    Sub *sub;
} Outer;
extern Outer data_0213b890;

void func_020d137c(void) {
    Sub *s = data_0213b890.sub;
    switch (s->flag) {
        case 0:
            s->flag = 1;
            break;
        case 1:
            break;
    }
}
