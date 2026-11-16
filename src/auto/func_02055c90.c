/* compiler: 1.2/sp2p3 -O4,s */
#include "m2c.h"

void *func_02053d1c(void);
void *func_02053c74(void *p);
void func_02053bec(void);
void func_020bc954(void);
typedef struct Handler {
    void (*fn)(void);
    u32 extra;
} Handler;
extern Handler data_0211d024[];
extern void *data_027e000c;

void func_02055c90(void) {
    u8 *cur;
    u8 *first;
    u32 kind;

    first = (u8 *) func_02053d1c();
    if (first != NULL) {
        cur = first;
        do {
            if (cur[8] & 1) {
                data_027e000c = cur;
                kind          = cur[9];
                if (kind < 0x20) {
                    data_0211d024[kind].fn();
                } else {
                    func_020bc954();
                }
            }
            cur = (u8 *) func_02053c74(cur);
        } while (first != cur);
        func_02053bec();
    }
}
