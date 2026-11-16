/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_020f268c(void *);
void func_020e4038(void);

void func_020ed6dc(u8 *arg0) {
    void *obj;
    void **vt;

    func_020f268c(arg0 + 0x42024);
    obj = *(void **) (arg0 + 0x42028);
    vt  = *(void ***) obj;
    ((void (*)(void *)) vt[3])(obj);
    *(void **) (arg0 + 0x42028) = 0;
    func_020e4038();
}
