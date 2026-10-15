/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* SVM_TestAndSet from https://github.com/Yotona/twewy libs/cri/src/svm.c (license: CC0-1.0), reused by tools/donor_match.py */
extern int (*data_02152578)(int *);
void func_020e4aac(void);
void func_020e4a9c(void);
int func_020e4430(int *mem) {
    int result;

    if (data_02152578 != 0) {
        result = data_02152578(mem);
    } else {
        func_020e4aac();
        result = *mem != 1;
        *mem   = 1;
        func_020e4a9c();
    }

    return result;
}
