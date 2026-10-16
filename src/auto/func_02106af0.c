/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef int s32;
extern u32 func_021054ac(void);
extern u32 func_021054c0(u32 state);
typedef struct UnkSndCommand {
    struct UnkSndCommand *next;
    s32 id;
    u32 arg[4];
} UnkSndCommand;
extern UnkSndCommand *func_02106af0(void);
extern UnkSndCommand *data_02158c08;
extern UnkSndCommand *data_02158bf8;

/* func_0207adcc from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/snd/snd_command.c (license: none), reused
 * by tools/donor_match.py */
UnkSndCommand *func_02106af0(void) {
    UnkSndCommand *cmd;
    u32 enabled = func_021054ac();

    cmd = data_02158bf8;
    if (cmd == 0) {
        func_021054c0(enabled);
        return 0;
    }
    data_02158bf8 = cmd->next;
    if (data_02158bf8 == 0) {
        data_02158c08 = 0;
    }
    func_021054c0(enabled);
    return cmd;
}
