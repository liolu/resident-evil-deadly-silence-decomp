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
extern Handler data_02122424[];

void func_020b1994(void) {
    data_0213b890.flag = 0;
    data_02122424[data_0213b890.kind]();
}
