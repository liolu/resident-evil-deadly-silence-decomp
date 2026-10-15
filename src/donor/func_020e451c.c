/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* svm_reset_variable from https://github.com/Yotona/twewy libs/cri/src/svm.c (license: CC0-1.0), reused by
 * tools/donor_match.py */
typedef struct {
    void (*func)(void *);
    void *object;
} SVMLockCallback;
typedef struct {
    void (*unk0)();
    int unk4;
} SVM_UNK;
extern int data_021525b0[8];
extern int data_021525d0[8];
extern int (*data_02152578)(int *);
extern SVMLockCallback data_02152590;
extern SVMLockCallback data_021525a0;
extern SVM_UNK data_021525a8;
extern SVM_UNK data_02152598;
void func_020e451c(void) {
    __builtin__clear(data_021525d0, sizeof(data_021525d0));
    __builtin__clear(&data_021525a0, sizeof(data_021525a0));
    __builtin__clear(&data_02152590, sizeof(data_02152590));
    __builtin__clear(&data_02152598, sizeof(data_02152598));
    __builtin__clear(&data_021525a8, sizeof(data_021525a8));

    for (int i = 0; i < 6; i++) {
        data_021525b0[i] = 0;
    }

    data_02152578 = 0;
}
