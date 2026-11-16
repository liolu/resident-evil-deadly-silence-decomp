/* compiler: 1.2/sp2p3 */
#include "m2c.h"

void func_021025f4(s32, s32);
void func_020ff608(void);
void func_020ff5f4(void);
void func_020ff5e0(void);
void func_020ff678(void);
void func_020ff664(void);
void func_020ff640(void);
void func_020ff61c(void);
void func_020ff5b8(void);
void func_020ff5a4(void);
void func_020ff57c(void);
void func_020ff554(void);
void func_020ffae4(u8);
void func_020ff9f0(u8);
void func_020fff68(u8);
void func_020ffce8(u8);
void func_020ffdfc(u8);
void func_020ff924(u16);
void func_020ff8a8(u16);
extern u8 data_0211b9d0[];

void func_0200f7f0(s32 arg0) {
    u8 *r4;

    func_021025f4(1, 1);
    func_020ff608();
    func_020ff5f4();
    func_020ff5e0();
    func_020ff678();
    func_020ff664();
    func_020ff640();
    func_020ff61c();
    func_020ff5b8();
    func_020ff5a4();
    func_020ff57c();
    func_020ff554();
    r4 = data_0211b9d0 + (arg0 * 10);
    func_020ffae4(data_0211b9d0[arg0 * 10]);
    func_020ff9f0(r4[1]);
    func_020fff68(r4[2]);
    func_020ffce8(r4[3]);
    func_020ffdfc(r4[4]);
    func_020ff924(*(u16 *) (r4 + 6));
    func_020ff8a8(*(u16 *) (r4 + 8));
}
