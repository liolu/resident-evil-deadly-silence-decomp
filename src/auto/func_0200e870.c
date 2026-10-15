/* compiler: 1.2/sp2p3  */
#include "engine.h"
#include "m2c.h"

s32 func_0200e870(s32 arg0, s32 arg1, s32 arg2, s32 arg3, u16 arg4, s32 arg5, s32 arg6, s32 arg7) {
    s32 var_ip;
    s32 var_lr;
    s32 var_r0;
    s32 var_r3;

    var_r0 = arg0;
    var_ip = var_r0;
    var_lr = arg5;
    var_r3 = arg6;
    if (arg1 & arg3) {
        var_ip = var_r0 + arg2;
        if (var_ip > var_r3) {
            if (arg7 & 1) {
                if (!(arg7 & 2)) {
                    var_lr = (var_ip - var_r3) - 1;
                }
                var_ip = var_lr;
            } else {
                if (!(arg7 & 2)) {
                    var_r0 = var_r3;
                }
                var_ip = var_r0;
            }
        }
    } else if (arg1 & arg4) {
        var_ip = var_r0 - arg2;
        if (var_ip < var_lr) {
            if (arg7 & 1) {
                if (!(arg7 & 2)) {
                    var_r3 = var_r3 + var_ip + 1;
                }
                var_ip = var_r3;
            } else {
                if (!(arg7 & 2)) {
                    var_r0 = var_lr;
                }
                var_ip = var_r0;
            }
        }
    } else if (var_r0 < var_lr) {
        if (arg7 & 1) {
            if (!(arg7 & 2)) {
                var_r3 = var_r3 + var_r0 + 1;
            }
            var_ip = var_r3;
        } else {
            if (!(arg7 & 2)) {
                var_r0 = var_lr;
            }
            var_ip = var_r0;
        }
    } else if (var_r0 > var_r3) {
        if (arg7 & 1) {
            if (!(arg7 & 2)) {
                var_lr = (var_r0 - var_r3) - 1;
            }
            var_ip = var_lr;
        } else {
            if (!(arg7 & 2)) {
                var_r0 = var_r3;
            }
            var_ip = var_r0;
        }
    }
    return var_ip;
}
