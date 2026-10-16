/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* Sound_FlushCommand from https://github.com/RonyxDumb/mkds src/arm9/020211e4_Sound_FlushCommand.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned long u32;
typedef signed long s32;
typedef int BOOL;
struct SNDCommand {
    struct SNDCommand *llNext;
    s32 id;
    u32 arg[4];
};
extern const struct SNDCommand *func_02107110(u32 flags);
extern BOOL func_02106e6c(u32 flags);
typedef enum {
    OS_INTRMODE_DISABLE_IRQ = 0x80,
    OS_INTRMODE_DISABLE_FIQ = 0x40,
    OS_INTRMODE_ENABLE      = 0
} OSIntrMode;
extern OSIntrMode func_021054ac(void);
extern OSIntrMode func_021054c0(OSIntrMode state);
extern void func_0210551c(u32 cycles);
extern void func_021046d4(register const void *startAddr, register u32 nBytes);
extern s32 func_02107c3c(s32 fifotag, u32 data, BOOL err);
extern struct SNDCommand data_02158ec0[256];
extern struct SNDCommand *data_02158c1c[8 + 1];
extern struct SNDCommand *data_02158c00;
extern struct SNDCommand *data_02158c04;
extern s32 data_02158c10;
extern s32 data_02158c14;
extern u32 data_02158c18;
extern void func_02106b48(void);
const struct SNDCommand *func_02107110(u32 flags);
BOOL func_02106e6c(u32 flags) {
    OSIntrMode oldirq = func_021054ac();

    if (data_02158c00 == ((void *) 0)) {
        (void) func_021054c0(oldirq);
        return 1;
    }

    if (data_02158c14 >= 8) {
        if ((flags & 0x1) == 0) {
            (void) func_021054c0(oldirq);
            return 0;
        }

        do {
            (void) func_02107110(0x1);
        } while (data_02158c14 >= 8);
    }

    func_021046d4(data_02158ec0, sizeof(data_02158ec0));

    s32 result = func_02107c3c(7, (u32) data_02158c00, 0);
    if (result < 0) {
        if ((flags & 0x1) == 0) {
            (void) func_021054c0(oldirq);
            return 0;
        }

        result = func_02107c3c(7, (u32) data_02158c00, 0);
        while (result < 0) {
            (void) func_021054c0(oldirq);
            func_0210551c(100);
            oldirq = func_021054ac();
            result = func_02107c3c(7, (u32) data_02158c00, 0);
        }
    }

    if ((flags & 0x2) != 0) {
        func_02106b48();
    }

    data_02158c1c[data_02158c10] = data_02158c00;

    if (++data_02158c10 > 8) {
        data_02158c10 = 0;
    }

    data_02158c00 = ((void *) 0);
    data_02158c04 = ((void *) 0);
    data_02158c14++;
    data_02158c18++;

    (void) func_021054c0(oldirq);
    return 1;
}
void func_02106b48(void);
