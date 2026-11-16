/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void);
extern Handler data_0211ff54[];

typedef struct {
    u8 pad[0x20];
    u8 kind;
} Gst;
extern Gst data_0213b890;

void func_0208e86c(void) {
    s32 sp0;

    data_0211ff54[data_0213b890.kind]();
}
