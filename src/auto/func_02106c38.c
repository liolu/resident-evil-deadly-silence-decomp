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
extern s32 func_02106c38(void);
extern UnkSndCommand *data_02158c00;

/* func_0207ac8c from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/snd/snd_command.c (license: none), reused
 * by tools/donor_match.py */
s32 func_02106c38(void) {
    u32 enabled = func_021054ac();
    s32 count   = 0;
    UnkSndCommand *cmd;

    for (cmd = data_02158c00; cmd != 0; cmd = cmd->next) {
        count++;
    }
    func_021054c0(enabled);
    return count;
}
