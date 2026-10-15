/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

extern M2C_UNK data_0213ad98;
extern M2C_UNK data_0213bdcc;
extern M2C_UNK data_0214ccc0;

void func_0200ea9c(void) {
    switch ((s32) M2C_FIELD(&data_0213ad98, u16 *, 0)) { /* irregular */
        case 0x1805:
        case 0x1800:
            if (M2C_FIELD(&data_0213ad98, u8 *, 2) == 1) {
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) & 0x7E);
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF34), u8 *, 8) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF34), u8 *, 8) & 0x7E);
                return;
            }
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) | 1);
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF34), u8 *, 8) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF34), u8 *, 8) | 1);
            return;
        case 0x103:
            if (M2C_FIELD(&data_0213bdcc, s32 *, 0x44) & 0x800000) {
                return;
            }
            if (M2C_FIELD(&data_0213ad98, u8 *, 2) == 4) {
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0x3AC), s32 *, 0x30) = 0xB36;
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0x3AC), s32 *, 0x34) = 0xFFFFFA24;
                return;
            }
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0x3AC), s32 *, 0x30) = 0xBC2;
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0x3AC), s32 *, 0x34) = -0x460;
            return;
        case 0x603:
            if (M2C_FIELD(&data_0213ad98, u8 *, 2) == 4) {
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), u8 *, 8) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), u8 *, 8) & 0x7E);
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) & 0x7E);
                return;
            }
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), u8 *, 8) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), u8 *, 8) | 1);
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) | 1);
            return;
        case 0x204:
            if (M2C_FIELD(&data_0213ad98, u8 *, 2) == 0) {
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) & 0x7E);
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF34), u8 *, 8) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF34), u8 *, 8) & 0x7E);
                return;
            }
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF30), u8 *, 8) | 1);
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF34), u8 *, 8) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF34), u8 *, 8) | 1);
            return;
        case 0xA04:
            if ((M2C_FIELD(&data_0213ad98, u8 *, 2) == 0) || (M2C_FIELD(&data_0213ad98, u8 *, 2) == 4)) {
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), u8 *, 8) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), u8 *, 8) & 0x7E);
                return;
            }
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), u8 *, 8) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF2C), u8 *, 8) | 1);
            return;
        case 0x1304:
            if (M2C_FIELD(&data_0213ad98, u8 *, 2) == 5) {
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF38), u8 *, 8) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF38), u8 *, 8) & 0x7E);
                M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF48), u8 *, 8) =
                    (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF48), u8 *, 8) | 1);
                return;
            }
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF38), u8 *, 8) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF38), u8 *, 8) | 1);
            M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF48), u8 *, 8) =
                (u8) (M2C_FIELD(M2C_FIELD(&data_0214ccc0, void **, 0xF48), u8 *, 8) & 0x7E);
            return;
    }
}
