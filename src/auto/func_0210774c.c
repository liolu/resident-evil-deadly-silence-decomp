/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_020219f0 from https://github.com/RonyxDumb/mkds src/arm9/020219f0_func_020219f0.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef signed char s8;
typedef int BOOL;
struct SNDBinaryFileHeader {
    s8 signature[4];
    u16 byteOrder;
    u16 version;
    u32 fileSize;
    u16 headerSize;
    u16 dataBlocks;
};
typedef struct SNDBinaryBlockHeader {
    u32 type;
    u32 size;
} SNDBinaryBlockHeader;
struct SNDInstParam {
    u16 wave[2];
    u8 rootKey;
    u8 envAttack;
    u8 envDecay;
    u8 envSustain;
    u8 envRelease;
    u8 pan;
};
struct SNDInstData {
    u8 type;
    u8 unk_1;
    struct SNDInstParam param;
};
struct SNDKeySplit {
    u8 key[8];
    struct SNDInstData instruments[];
};
struct SNDDrumSet {
    u8 minKey;
    u8 maxKey;
    struct SNDInstData instruments[];
};
struct SNDWaveArcLink {
    struct SNDWaveArc *waveArc;
    struct SNDWaveArcLink *waveArcLLnext;
};
struct SNDBankData {
    struct SNDBinaryFileHeader fileHeader;
    struct SNDBinaryBlockHeader blockHeader;
    struct SNDWaveArcLink waveArcLinks[4];
    u32 instCount;
    u32 instOffsets[];
};
struct SNDWaveArc {
    struct SNDBinaryFileHeader fileHeader;
    struct SNDBinaryBlockHeader blockHeader;
    struct SNDWaveArcLink *waveArcLLHead;
    u8 unk_1C[28];
    u32 waveCount;
    u32 waveOffsets[];
};
struct SNDInstPos {
    u32 program;
    u32 index;
};
extern BOOL func_0210774c(const struct SNDBankData *bankData, struct SNDInstData *instData, struct SNDInstPos *instPos);
#pragma thumb off
BOOL func_0210774c(const struct SNDBankData *bankData, struct SNDInstData *instData, struct SNDInstPos *instPos) {
    while (instPos->program < bankData->instCount) {
        struct SNDDrumSet *drums;
        struct SNDKeySplit *keySplit;

        u32 instOffset = bankData->instOffsets[instPos->program];
        instData->type = ((u8) instOffset);

        switch (instData->type) {
            case 1:
            case 2:
            case 3:
            case 4:
            case 5:
                instData->param = *((struct SNDInstParam *) ((u8 *) bankData + (u32) (instOffset >> 8)));
                instPos->program++;
                return 1;
            case 16:
                drums = ((struct SNDDrumSet *) ((u8 *) bankData + (u32) (instOffset >> 8)));

                for (; instPos->index < drums->maxKey - drums->minKey + 1;) {
                    *instData = drums->instruments[instPos->index];
                    instPos->index++;
                    return 1;
                }
                break;
            case 17:
                keySplit = ((struct SNDKeySplit *) ((u8 *) bankData + (u32) (instOffset >> 8)));
                for (; instPos->index < 8;) {
                    if (keySplit->key[instPos->index] == 0) {
                        break;
                    }
                    *instData = keySplit->instruments[instPos->index];
                    instPos->index++;
                    return 1;
                }
                break;
        }

        instPos->program++;
        instPos->index = 0;
    }
    return 0;
}
