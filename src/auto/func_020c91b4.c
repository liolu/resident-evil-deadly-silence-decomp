/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
typedef struct {
    u8 pad[2];
    u8 kind;
} Sub;
typedef struct {
    u8 pad[0x2f8];
    Sub *sub;
} Mid;
typedef struct {
    u8 pad[0x4c];
    Mid *mid;
} Top;

extern Top data_0213b890;
extern Handler data_02125b10[];

void func_020c91b4(void) {
    data_02125b10[data_0213b890.mid->sub->kind]();
}
