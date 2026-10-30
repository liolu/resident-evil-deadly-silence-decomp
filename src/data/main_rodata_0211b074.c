/* compiler: 2.0/sp1p5 */
#include "m2c.h"

extern u8 data_0212c584[];
extern u8 data_0212c588[];
extern u8 data_0212c598[];
extern u8 data_0212c5a8[];
extern u8 data_0212c5b8[];
extern u8 data_0212c5bc[];
extern u8 data_0212c5c0[];
extern u8 data_0212c5c4[];
extern u8 data_0212c5c8[];
extern u8 data_0212c5cc[];
extern u8 data_0212c5d0[];
extern u8 data_0212c5d4[];
extern u8 data_0212c5d8[];
extern u8 data_0212c5dc[];
extern u8 data_0212c5e0[];
extern u8 data_0212c5e4[];
extern u8 data_0212c5e8[];
extern u8 data_0212c5ec[];
extern u8 data_0212c5f0[];
extern u8 data_0212c5f4[];
extern u8 data_0212c5fc[];
extern u8 data_0212c604[];
extern u8 data_0212c60c[];
extern u8 data_0212c614[];
extern u8 data_0212c61c[];
extern u8 data_0212c624[];
extern u8 data_0212c62c[];
extern u8 data_0212c634[];
extern u8 data_0212c63c[];
extern u8 data_0212c644[];
extern u8 data_0212c64c[];
extern u8 data_0212c654[];
extern u8 data_0212c65c[];
extern u8 data_0212c668[];
extern u8 data_0212c674[];
extern u8 data_0212c680[];
extern u8 data_0212c68c[];
extern u8 data_0212c698[];
extern u8 data_0212c6a4[];
extern u8 data_0212c6b0[];
extern u8 data_0212c6c0[];
extern u8 data_0212c6d4[];
extern u8 data_0212c6ec[];
extern u8 data_0212c704[];
extern u8 data_0212c72c[];
extern u8 data_0212c754[];
extern u8 data_0212c77c[];
extern u8 data_0212c7a4[];
extern u8 func_0200509c[];
extern u8 func_020050a0[];
extern u8 func_020050c0[];

const u32 data_0211b074[3]  = {0x00000000, 0x00000000, 0x00001000};
const u32 data_0211b080[16] = {
    0x00000000, 0x00001CC0, 0x020002C0, (u32) &data_0212c5a8, 0x00001CC0, 0x00000300, 0x02000040, (u32) &data_0212c598,
    0x00001FC0, 0x00000040, 0x01000020, (u32) &data_0212c588, 0xFFFFFFFF, 0x00000000, 0x00000000, (u32) &data_0212c584};
const u32 data_0211b0c0[108] = {0x00000000,           0x00000000,           0x00000000, 0x00000000,
                                (u32) &data_0212c5e4, (u32) &data_0212c61c, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5e4, (u32) &data_0212c61c, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5c0, (u32) &data_0212c604, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5d0, (u32) &data_0212c624, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5f0, (u32) &data_0212c62c, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5dc, (u32) &data_0212c634, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5bc, (u32) &data_0212c63c, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5d4, (u32) &data_0212c644, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5d4, (u32) &data_0212c644, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5e0, (u32) &data_0212c5f4, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c5cc, (u32) &data_0212c5fc, 0x0F7800A0, (u32) &func_020050a0,
                                (u32) &data_0212c5c8, (u32) &data_0212c60c, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c72c, (u32) &data_0212c5d8, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c754, (u32) &data_0212c674, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c77c, (u32) &data_0212c680, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c6d4, (u32) &data_0212c5ec, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c6ec, (u32) &data_0212c68c, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c7a4, (u32) &data_0212c65c, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c704, (u32) &data_0212c668, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c64c, (u32) &data_0212c5c4, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c6a4, (u32) &data_0212c5e8, 0x0FC00100, (u32) &func_020050c0,
                                (u32) &data_0212c5b8, (u32) &data_0212c5b8, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c6c0, (u32) &data_0212c6b0, 0x0F9000C0, (u32) &func_020050a0,
                                (u32) &data_0212c698, (u32) &data_0212c654, 0x0F9000C0, (u32) &func_020050a0,
                                0x00000000,           (u32) &data_0212c614, 0x0F7800A0, (u32) &func_0200509c,
                                0x00000000,           0x00000000,           0x00000000, 0x00000000};
