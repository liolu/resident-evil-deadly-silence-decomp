/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void);
extern Handler data_0212683c[];

typedef struct {
    u8 pad[0x54];
    u8 kind;
} Gst;
extern Gst data_0213b890;

void func_020d6658(void) {
    s32 sp0;

    data_0212683c[data_0213b890.kind]();
}
