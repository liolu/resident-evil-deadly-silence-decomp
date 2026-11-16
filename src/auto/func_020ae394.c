/* compiler: 1.2/sp2p3 */
#include "m2c.h"
typedef void (*Handler)(void);
extern Handler data_02122370[];
extern u8 data_0213b2b4[];
void func_020c440c(void);

void func_020ae394(void) {
    data_02122370[data_0213b2b4[0xb4]]();
    func_020c440c();
}
