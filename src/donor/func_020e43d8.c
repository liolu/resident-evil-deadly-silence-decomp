/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* SJ_SplitChunk from https://github.com/Yotona/twewy libs/cri/src/sj_utl.c (license: CC0-1.0), reused by tools/donor_match.py
 */
typedef struct SJCK {
    char *data;
    int length;
} SJCK;
extern void func_020e43d8(SJCK *ck, int nbyte, SJCK *ck1, SJCK *ck2);
void func_020e43d8(SJCK *ck, int nbyte, SJCK *ck1, SJCK *ck2) {
    *ck1 = *ck;

    ck2->length = ck1->length;
    if (ck1->length > nbyte) {
        ck1->length = nbyte;
    }

    ck2->length -= ck1->length;
    if (ck2->length == 0) {
        ck2->data = 0;
    } else {
        ck2->data = ck1->data + ck1->length;
    }
}
