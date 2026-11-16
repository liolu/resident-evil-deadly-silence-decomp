/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void);
extern Handler data_021260e0[];

typedef struct {
    u8 pad[0x21];
    u8 kind;
} Gst;
extern Gst data_0213b890;

void func_020ceb68(void) {
    s32 sp0;

    data_021260e0[data_0213b890.kind]();
}
