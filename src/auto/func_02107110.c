/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef int s32;
extern u32 func_021054ac(void);
extern u32 func_021054c0(u32 state);
extern void func_0210551c(u32 count);
typedef struct UnkSndCommand {
    struct UnkSndCommand *next;
    s32 id;
    u32 arg[4];
} UnkSndCommand;
extern UnkSndCommand *func_02107110(u32 flags);
extern u32 func_021074bc(void);
extern u32 data_02158bfc;
extern UnkSndCommand *data_02158c08;
extern UnkSndCommand *data_02158bf8;
extern s32 data_02158c0c;
extern s32 data_02158c14;
extern UnkSndCommand *data_02158c1c[9];

/* func_0207a818 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/snd/snd_command.c (license: none), reused
 * by tools/donor_match.py */
UnkSndCommand *func_02107110(u32 flags) {
    u32 enabled = func_021054ac();
    UnkSndCommand *head;
    UnkSndCommand *tail;

    if (flags & 1) {
        while (data_02158bfc == func_021074bc()) {
            func_021054c0(enabled);
            func_0210551c(100);
            enabled = func_021054ac();
        }
    } else if (data_02158bfc == func_021074bc()) {
        func_021054c0(enabled);
        return 0;
    }

    head = data_02158c1c[data_02158c0c];
    data_02158c0c++;
    if (data_02158c0c > 8) {
        data_02158c0c = 0;
    }

    tail = head;
    while (tail->next != 0) {
        tail = tail->next;
    }

    if (data_02158c08 != 0) {
        data_02158c08->next = head;
    } else {
        data_02158bf8 = head;
    }
    data_02158c08 = tail;
    data_02158c14--;
    data_02158bfc++;

    func_021054c0(enabled);
    return head;
}
