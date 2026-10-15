/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* adxt_trap_entry from https://github.com/Yotona/twewy libs/cri/src/adx_tsvr.c (license: CC0-1.0), reused by
 * tools/donor_match.py */
typedef struct {
    int nch;
    int ibuf;
    int nblk;
    int obuf_l;
    int obuf_r;
} ADXPDPRM;
typedef struct {
    int used;
    int xno;
    int mode;
    int stat;
    int ndecblk;
    ADXPDPRM xprm;
    short dly[2][2];
    short k[2];

    short key;
    short key_mul;
    short key_add;
    short pad3A;
} ADXPD_OBJ;
typedef ADXPD_OBJ *ADXPD;
typedef struct {
    char pad0[0x10];
} ADX_UNK;
typedef struct {
    int ibuf;
    int niblk;
    int nch;
    int blksize;
    int blknsmpl;
    void *pcmbuf;
    int pcmbsize;
    int pcmbdist;
    int wpos;
    int nroom;
    int lp_nsmpl;
} ADXB_DECPARA;
typedef struct ADXB_OBJ {
    short used;
    short hdcdflag;
    int stat;
    ADXPD adxpd;
    char code;
    char bps;
    char nch;
    char blklen;
    int blknsmpl;
    int sfreq;
    int total_nsmpl;
    short cof;
    char pad1E[2];
    int lp_ins_nsmpl;
    short nloop;
    short lp_type;
    int lp_spos;
    int lp_sofst;
    int lp_epos;
    int lp_eofst;
    int maxnch;
    void *pcmbuf;
    int pcmbsize;
    int pcmbdist;
    ADXB_DECPARA dp;
    int ndecsmpl;
    void *(*getwrfunc)(void *, int *, int *, int *);
    void *getwrobj;
    void (*addwrfunc)(void *, int, int);
    int addwrobj;
    int total_ndecsmpl;
    int curwpos;
    int total_decsmpl;
    int total_decdtlen;
    short format;
    short unk9A;
    short unk9C;
    short unk9E;
    short unkA0;
    short unkA2;
    short unkA4;
    short unkA6;
    short unkA8;
    short unkAA;
    int unkAC;
    int unkB0;
    int unkB4;
    int unkB8;
    int unkBC;
    int ainf_len;
    ADX_UNK unkC4;
    short def_out_vol;
    short def_pan[2];
    char padDA[2];
    int unkDC;
    int unkE0;
    void (*unkE4)(void *obj, int nbyte, int pcm_nbyte);
    void *unkE8;
} ADXB_OBJ;
typedef ADXB_OBJ *ADXB;
typedef struct UUID {
    unsigned int data1;
    unsigned short data2;
    unsigned short data3;
    unsigned char data4[8];
} UUID;
typedef struct SJCK {
    char *data;
    int length;
} SJCK;
typedef struct SJ {
    struct _sj_vtable *vtable;
} SJ_OBJ;
typedef SJ_OBJ *SJ;
typedef struct _sj_vtable {
    void (*QueryInterface)();
    void (*AddRef)();
    void (*Release)();
    void (*Destroy)(SJ sj);
    UUID *(*GetUuid)(SJ sj);
    void (*Reset)(SJ sj);
    void (*GetChunk)(SJ sj, int id, int nbyte, SJCK *ck);
    void (*UngetChunk)(SJ sj, int id, SJCK *ck);
    void (*PutChunk)(SJ sj, int id, SJCK *ck);
    int (*GetNumData)(SJ sj, int id);
    int (*IsGetChunk)(SJ sj, int id, int nbyte, int *rbyte);
    void (*EntryErrFunc)(SJ sj, void (*func)(void *obj, int ecode), void *obj);
} _sj_vtable;
typedef struct {
    char used;
    char state;
    char maxnch;
    char empty_end;
    ADXB adxb;
    SJ sji;
    SJ sjo[2];
    SJCK cki;
    SJCK cko[2];
    int total_decsmpl;
    int total_decdtlen;
    int decpos;
    int maxdecsmpl;
    int dtrpsmpl;
    int dtrpcnt;
    int dtrpdtlen;
    void (*dtrpfunc)();
    void *dtrpobj;
    void (*dfltfunc)();
    void *dfltobj;
    void (*unk_58)();
    void *unk_5C;
    char spsdinfo[0x40];
    int hdrlen;
    int lnkflg;
    int unk_A8;
    int unk_AC;
    int unk_B0;
} ADXSJD;
typedef struct {
    void (*ExecServer)();
    void (*EntryErrFunc)();
    int (*GetFileSize)();
    void (*unkC)();
    void *(*Open)(char *device_name, void *, int);
    void (*Close)(void *fd);
    int (*Seek)(void *fd, int offset, int whence);
    int (*Tell)(void *fd);
    int (*ReqRd)(void *fd, int len, void *buf);
    void (*unk24)();
    void (*StopTr)();
    int (*GetStat)(void *fd);
    int (*GetSctLen)();
    void (*SetSctLen)();
    int (*GetNumTr)();
    void (*unk3C)();
    void (*IsExistFile)();
    void (*unk44)();
    void (*unk48)();
    void (*unk4C)();
    void (*unk50)();
    void (*unk54)();
    void (*unk58)();
    void (*unk5C)();
    int (*OptFn1)();
    void (*unk64)();
} CVFSDevice;
typedef struct {
    CVFSDevice *device;
    void *fd;
} CVFSHandle;
typedef struct {
    char used;
    char stat;
    char rdflg;
    char unk_03;
    SJ sj;
    CVFSHandle *fp;
    int fofst;
    long long fsize;
    int fnsct;
    int maxsize;
    int minsize;
    int reqsct;
    SJCK reqck;
    int rdsct;
    int esct;
    unsigned int tbyte;
    void (*eosfunc)(void *);
    void *eosobj;
    int unk_44;
    char pause;
    char unk_49;
    char unk_4A;
    char unk_4B;
    char unk_4C;
    char unk_4D;
    char unk_4E[0x2];
    int errcnt;
    char *filename;
    void *dir;
    int stpos;
    unsigned int unk_60;
} ADXSTM;
typedef void *ADXRNA;
typedef struct _adx_talk {
    char used;
    char stat;
    char pmode;
    char maxnch;
    ADXSJD *sjd;
    ADXSTM *stm;
    ADXRNA rna;
    SJ sjf;
    SJ sji;
    SJ sjo[2];
    char *ibuf;
    int ibuflen;
    int ibufxlen;
    short *obuf;
    int obufsize;
    int obufdist;
    int svrfreq;
    short maxsct;
    short minsct;
    short outvol;
    short outpan[2];
    short outbalance;
    int maxdecsmpl;
    int lpcnt;
    int lp_skiplen;
    int trp;
    int wpos;
    int mofst;
    short ercode;
    int edecpos;
    short edeccnt;
    short eshrtcnt;
    char lpflg;
    char autorcvr;
    char filterMode;
    char execFlag;
    char waitFlag;
    char readyFlag;
    char pause_flag;
    void *amp;
    SJ ampsji[2];
    SJ ampsjo[2];
    int time_ofst;
    int lesct;
    int trpnsmpl;
    void *lsc;
    char lnkflg;
    char pad0;
    short pad1;
    unsigned int tvofst;
    unsigned int svcnt;
    unsigned int decofst;
    char streamStartFlag;
    char extraInfoFlag;
    short pad2;
    char *workFilename;
    char *filename;
    void *directory;
    unsigned int offset;
    unsigned int range;
    unsigned int loopDecodeLength;
} ADX_TALK;
typedef ADX_TALK *ADXT;
extern void func_020deb88(const char *);
extern void func_020df3b4(ADXSJD *sjd, int pos);
extern void func_020df398(ADXSJD *sjd, int samples);
extern void func_020df390(ADXSJD *sjd, int cnt);
extern void func_020df388(ADXSJD *sjd, int dt_len);
extern int func_020df308(ADXSJD *sjd);
extern int func_020df2d8(ADXSJD *sjd);
extern int func_020df2c8(ADXSJD *sjd);
extern int func_020df1dc(ADXSJD *sjd);
extern void func_020e2d1c(ADXT adxt);
extern char data_021301b0[];
void func_020e2d1c(ADXT adxt) {
    ADXSJD *sjd = adxt->sjd;
    SJ sji      = adxt->sji;
    int lp_spos;
    int lp_sofst;
    int lp_epos;
    int trp;
    SJCK ck;

    lp_spos  = func_020df308(sjd);
    lp_sofst = func_020df2d8(sjd);
    lp_epos  = func_020df2c8(sjd);

    if ((unsigned char) (char) (adxt->pmode - 2) <= 1 && adxt->lpflg == 0) {
        func_020df398(adxt->sjd, -1);
        return;
    }

    (*(sji)->vtable->GetChunk)(sji, 1, adxt->lp_skiplen, &ck);

    if (ck.length < adxt->lp_skiplen) {
        func_020deb88(data_021301b0);
    }

    (*(sji)->vtable->PutChunk)(sji, 0, &ck);

    func_020df390(sjd, 0);

    trp            = lp_epos - lp_spos;
    adxt->trpnsmpl = trp;

    func_020df398(sjd, trp);
    func_020df388(sjd, lp_sofst);
    func_020df3b4(sjd, lp_spos);

    if (adxt->pmode == 2) {
        (*(sji)->vtable->Reset)(sji);
        (*(sji)->vtable->GetChunk)(sji, 1, lp_sofst, &ck);
        (*(sji)->vtable->PutChunk)(sji, 0, &ck);
    }

    func_020df1dc(sjd);
    adxt->lpcnt++;
}
