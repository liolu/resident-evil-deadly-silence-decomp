/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_02091f68(void);
void func_02092060(void);

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213daa8;
extern M2C_UNK data_0213e394;
extern M2C_UNK data_02144cc0;

void func_02092ab0(void) {
    if (!(M2C_FIELD(&data_0213daa8, u16 *, 0x74) & 1)) {
        M2C_FIELD(&data_0213ad98, u16 *, 0x20) = (u16) (M2C_FIELD(&data_0213ad98, u16 *, 0x20) & 3);
        M2C_FIELD(&data_02144cc0, u16 *, 0xE0) = (u16) (M2C_FIELD(&data_02144cc0, u16 *, 0xE0) & 3);
    }
    M2C_FIELD(&data_0213daa8, u16 *, 0x74) = (u16) M2C_FIELD(&data_0213e394, u16 *, 0x10);
    M2C_FIELD(&data_0213ad98, u8 *, 5) = (u8) (M2C_FIELD(&data_0213ad98, u8 *, 5) & 1);
    func_02091f68();
    func_02092060();
}
