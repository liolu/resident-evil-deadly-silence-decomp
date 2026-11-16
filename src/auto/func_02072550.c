/* compiler: 1.2/sp2p3 */
#include "m2c.h"

typedef void (*Handler)(void);
extern Handler data_0211d8c8[];
extern u8 data_0213b2b4[];

void func_020b6798(void);
void func_020b6314(void);
void func_02095a64(void);
void func_02095990(void);
void func_020c440c(void);
void func_02092b2c(void);

void func_02072550(void) {
    func_020b6798();
    func_020b6314();
    func_02095a64();
    data_0211d8c8[M2C_FIELD(data_0213b2b4, u8 *, 0xB4)]();
    func_02095990();
    func_020c440c();
    func_02092b2c();
}
