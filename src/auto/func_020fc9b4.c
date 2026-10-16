/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */

typedef unsigned int u32;
typedef signed char s8;
typedef struct CallbackNode {
    void (*func)(void);
    void *arg;
    struct CallbackNode *next;
} CallbackNode;
extern s8 data_02157318;
extern u32 data_02157320;
extern u32 data_0215731c;
extern CallbackNode data_02157330;
extern CallbackNode data_02157324;
extern void func_020fc944(void);
extern void func_020fc938(void);
extern void func_02106a5c(void);
extern void func_0210ac70(CallbackNode *node);
extern void func_0210ac58(CallbackNode *node);
extern void *func_020fca5c(void);
extern void func_020fd80c(void);
extern void func_020fcdd4(void);

/* SoundSystem_Init from https://github.com/sturmds/advance-wars-dual-strike-decomp src/game/main/sound/sound_system_init.c
 * (license: CC0-1.0), reused by tools/donor_match.py */
void func_020fc9b4(void) {
    if (data_02157320 != 0) {
        return;
    }
    data_02157320 = 1;
    func_02106a5c();
    data_02157324.func = func_020fc944;
    data_02157324.arg  = ((void *) 0);
    data_02157330.func = func_020fc938;
    data_02157330.arg  = ((void *) 0);
    func_0210ac70(&data_02157324);
    func_0210ac58(&data_02157330);
    func_020fca5c();
    func_020fd80c();
    func_020fcdd4();
    data_02157318 = -1;
    data_0215731c = 1;
}
