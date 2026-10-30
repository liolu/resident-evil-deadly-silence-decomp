/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

M2C_UNK func_0208756c(void *);                      /* extern */
s32 func_02088480();                                /* extern */
s32 func_02088638();                                /* extern */
M2C_UNK func_0208c0b8(void *);                      /* extern */
M2C_UNK func_0208c540(void *);                      /* extern */
M2C_UNK func_0208c840(void *);                      /* extern */
M2C_UNK func_0208c970(void *);                      /* extern */
M2C_UNK func_0208cb3c(void *);                      /* extern */
M2C_UNK func_0208cc24(void *);                      /* extern */
M2C_UNK func_0208cee4(void *);                      /* extern */
M2C_UNK func_0208cf68(void *);                      /* extern */
M2C_UNK func_0208d040(void *);                      /* extern */
M2C_UNK func_0208d0fc(void *);                      /* extern */
M2C_UNK func_0208d114(void *);                      /* extern */
M2C_UNK func_0208d128();                            /* extern */
s32 func_02090ab8();                                /* extern */

void func_0208d190(void *arg0) {
    u8 temp_r0;
    u8 temp_r0_2;

    func_0208d128();
    func_0208c540(arg0);
    func_0208cb3c(arg0);
    func_0208c0b8(arg0);
    temp_r0 = M2C_FIELD(arg0, u8 *, 0x91);
    switch (temp_r0) {                              /* switch 1; irregular */
        case 0:                                         /* switch 1 */
            func_0208d040(arg0);
            break;
        case 1:                                         /* switch 1 */
            func_0208cee4(arg0);
            break;
        case 2:                                         /* switch 1 */
            func_0208c970(arg0);
            break;
    }
    temp_r0_2 = M2C_FIELD(arg0, u8 *, 0x91);
    switch (temp_r0_2) {                            /* switch 2; irregular */
        default:                                        /* switch 2 */
        case 0:                                         /* switch 2 */
            func_0208cf68(arg0);
            break;
        case 1:                                         /* switch 2 */
            func_0208cc24(arg0);
            break;
        case 2:                                         /* switch 2 */
            func_0208c840(arg0);
            break;
    }
    func_0208d114(arg0);
    func_0208756c(arg0 + 0x320);
    M2C_FIELD(arg0, s8 *, 0x337) = 0;
    func_0208d0fc(arg0);
    if (func_02088480() == 0) {
        M2C_FIELD(arg0, s16 *, 0x4E) = 0;
    } else {
        M2C_FIELD(arg0, s16 *, 0x4E) = (s16) (func_02090ab8() * 0xC);
    }
    if (func_02088638() != 0) {
        M2C_FIELD(arg0, s8 *, 0x90) = 3;
        M2C_FIELD(arg0, u8 *, 0x91) = 0U;
        M2C_FIELD(arg0, s8 *, 0x92) = 0;
        M2C_FIELD(arg0, s8 *, 0x93) = 0;
    }
}
