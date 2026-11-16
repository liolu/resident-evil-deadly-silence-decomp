/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
typedef struct {
    u8 pad[0x1d];
    u8 flag;
    u8 pad2[2];
    u8 kind;
} Obj;

extern Obj data_0213b890;
extern Handler data_021224a0[];

void func_020b195c(void) {
    data_0213b890.flag = 1;
    data_021224a0[data_0213b890.kind]();
}
