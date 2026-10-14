/* compiler: 1.2/sp2p3  */
#include "m2c.h"
#include "engine.h"

void func_0200ed94(void);

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_02143cc0;

void func_02056f70(s32 arg0) {
    M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 1;
    M2C_FIELD(&data_0213ad98, s8 *, 2) = (s8) arg0;
    func_0200ed94();
    M2C_FIELD(&data_02143cc0, s8 *, 0xE) = 0;
}
