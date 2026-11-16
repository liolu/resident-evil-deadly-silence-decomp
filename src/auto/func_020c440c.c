/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Fn)(void);
extern void func_020c3978(void);
extern Fn data_02125578[];
extern u8 data_0213b890[];

u8 func_020c440c(void) {
    Fn f;

    data_02125578[data_0213b890[1]]();
    f = *(Fn *) (data_0213b890 + 0x44);
    if (f != NULL) {
        func_020c3978();
        f();
    }
    f = *(Fn *) (data_0213b890 + 0x74);
    if (f != NULL) {
        f();
    }
    f = *(Fn *) (data_0213b890 + 0x78);
    if (f != NULL) {
        f();
    }
    return data_0213b890[1];
}
