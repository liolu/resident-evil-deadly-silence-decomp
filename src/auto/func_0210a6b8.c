/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* MicStartAutoSampling from https://github.com/ntrtwl/NitroSDK libraries/spi/src/mic.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned long u32;
typedef int BOOL;
typedef enum {
    PXI_FIFO_TAG_EX = 0,
    PXI_FIFO_TAG_USER_0,
    PXI_FIFO_TAG_USER_1,
    PXI_FIFO_TAG_SYSTEM,
    PXI_FIFO_TAG_NVRAM,
    PXI_FIFO_TAG_RTC,
    PXI_FIFO_TAG_TOUCHPANEL,
    PXI_FIFO_TAG_SOUND,
    PXI_FIFO_TAG_PM,
    PXI_FIFO_TAG_MIC,
    PXI_FIFO_TAG_WM,
    PXI_FIFO_TAG_FS,
    PXI_FIFO_TAG_OS,
    PXI_FIFO_TAG_CTRDG,
    PXI_FIFO_TAG_CARD,
    PXI_FIFO_TAG_WVR,
    PXI_FIFO_TAG_CTRDG_Ex,
    PXI_FIFO_TAG_CTRDG_PHI,
    PXI_MAX_FIFO_TAG = 32
} PXIFifoTag;
extern int func_02107c3c(int fifotag, u32 data, BOOL err);
extern BOOL func_0210a6b8(void *buf, u32 size, u32 span, u8 flags);
BOOL func_0210a6b8(void *buf, u32 size, u32 span, u8 flags) {
    if (0 > func_02107c3c(PXI_FIFO_TAG_MIC, 0x02000000 | (0 << 16) | (0x0041 << 8) | (u32) flags, 0)) {
        return 0;
    }

    if (0 > func_02107c3c(PXI_FIFO_TAG_MIC, (1 << 16) | ((u32) buf >> 16), 0)) {
        return 0;
    }

    if (0 > func_02107c3c(PXI_FIFO_TAG_MIC, (2 << 16) | ((u32) buf & 0x0000ffff), 0)) {
        return 0;
    }

    if (0 > func_02107c3c(PXI_FIFO_TAG_MIC, (3 << 16) | (size >> 16), 0)) {
        return 0;
    }

    if (0 > func_02107c3c(PXI_FIFO_TAG_MIC, (4 << 16) | (size & 0x0000ffff), 0)) {
        return 0;
    }

    if (0 > func_02107c3c(PXI_FIFO_TAG_MIC, (5 << 16) | (span >> 16), 0)) {
        return 0;
    }

    if (0 > func_02107c3c(PXI_FIFO_TAG_MIC, 0x01000000 | (6 << 16) | (span & 0x0000ffff), 0)) {
        return 0;
    }

    return 1;
}
