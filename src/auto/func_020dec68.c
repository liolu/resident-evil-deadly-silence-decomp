/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_020d9fec(void);
void func_020dd470(void);
void func_020dd47c(void);
void func_020e044c(void);
void func_020e04d8(void);

extern s32 data_0214f2ec;

void func_020dec68(void) {
    func_020dd47c();
    if (data_0214f2ec != 0) {
        func_020dd470();
        return;
    }
    data_0214f2ec = 1;
    func_020dd470();
    data_0214f2ec = 3;
    func_020e044c();
    data_0214f2ec = 4;
    func_020e04d8();
    data_0214f2ec = 5;
    func_020d9fec();
    data_0214f2ec = 6;
    func_020e04d8();
    data_0214f2ec = 7;
    func_020e044c();
    data_0214f2ec = 0;
}
