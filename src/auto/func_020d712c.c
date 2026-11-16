/* compiler: 1.2/sp2p3 */
#include "m2c.h"

extern s32 func_020d70b0(void);
extern u8 data_0213caa0[];
extern u8 data_02141cc0[];
extern u8 data_02142cc0[];

s32 func_020d712c(void) {
    *(s32 *) (data_02142cc0 + 0x4A4) = 0;
    *(s32 *) (data_02142cc0 + 0x4A0) = 0;
    *(s32 *) (data_02141cc0 + 0x48)  = 0;
    data_0213caa0[0x706]             = 0;
    *(s16 *) (data_02141cc0 + 0x50)  = 1;
    *(s32 *) (data_02141cc0 + 0x54)  = 0;
    *(s32 *) (data_02141cc0 + 0x0)   = 0;
    *(s16 *) (data_02141cc0 + 0x4)   = 0;
    *(s32 *) (data_02141cc0 + 0x4C)  = 0;
    if (func_020d70b0() != 0) {
        return 1;
    }
    return 0;
}
