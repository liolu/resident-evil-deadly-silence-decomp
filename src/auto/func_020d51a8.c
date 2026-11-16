/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void);
extern Handler data_02126788[];

typedef struct {
    u8 pad[0x21];
    u8 kind;
} Gst;
extern Gst data_0213b890;

void func_020d51a8(void) {
    s32 sp0;

    data_02126788[data_0213b890.kind]();
}
