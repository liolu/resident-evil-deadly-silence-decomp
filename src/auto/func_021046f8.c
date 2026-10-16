#include "m2c.h"

void func_021046f8(void) {
    __asm__ volatile("mov r0, #0\n"
                     "mcr p15, 0, r0, c7, c10, 4\n"
                     :
                     :
                     : "r0", "memory");
}
