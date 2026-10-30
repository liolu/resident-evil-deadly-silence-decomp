/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207b160 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/snd/snd_bank.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned char u8;
typedef int s32;
extern void func_021046b8(void *ptr, u32 size);
extern void func_02106a48(void);
extern void func_02106a34(void);
typedef struct UnkSndWaveArc UnkSndWaveArc;
typedef struct UnkSndWaveArcLink {
    UnkSndWaveArc *waveArc;
    struct UnkSndWaveArcLink *next;
} UnkSndWaveArcLink;
struct UnkSndWaveArc {
    u8 unk_00[8];
    u32 fileSize;
    u8 unk_0c[4];
    u8 blockHeader[8];
    UnkSndWaveArcLink *topLink;
    u32 reserved[7];
    u32 waveCount;
    u32 waveOffset[0];
};
typedef struct UnkSndBankData {
    u8 fileHeader[0x10];
    u8 blockHeader[8];
    UnkSndWaveArcLink waveArcLink[4];
    u32 instCount;
    u32 instOffset[1];
} UnkSndBankData;
void func_02107990(UnkSndBankData *bank) {
    s32 i;

    func_02106a48();
    for (i = 0; i < 4; i++) {
        UnkSndWaveArc *waveArc = bank->waveArcLink[i].waveArc;
        if (waveArc == 0) {
            continue;
        }
        if (&bank->waveArcLink[i] == waveArc->topLink) {
            waveArc->topLink = bank->waveArcLink[i].next;
            func_021046b8(waveArc, 0x3c);
        } else {
            UnkSndWaveArcLink *link;
            for (link = waveArc->topLink; link != 0; link = link->next) {
                if (&bank->waveArcLink[i] == link->next) {
                    break;
                }
            }
            link->next = bank->waveArcLink[i].next;
            func_021046b8(link, sizeof(UnkSndWaveArcLink));
        }
    }
    func_02106a34();
}
