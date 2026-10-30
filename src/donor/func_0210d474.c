/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_02063910 from projets/nintendogs-dachshund/src/donor/func_02063910.c (same code in another game of this workspace),
 * reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef int BOOL;
typedef struct OSThread OSThread;
typedef struct OSMutex OSMutex;
typedef struct OSThreadQueue {
    u16 head;
    u16 tail;
} OSThreadQueue;
typedef struct OSMutexQueue {
    OSMutex *head;
    OSMutex *tail;
} OSMutexQueue;
struct OSMutex {
    OSThreadQueue queue;
    OSThread *thread;
    s32 count;
    OSMutex *prev;
    OSMutex *next;
};
typedef u64 OSTick;
typedef struct OSAlarm OSAlarm;
typedef void (*OSAlarmHandler)(void *arg);
struct OSAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    OSTick fire;
    OSAlarm *prev;
    OSAlarm *next;
    OSTick period;
    OSTick start;
};
typedef struct WMCallback {
    u16 apiid;
    u16 errcode;
} WMCallback;
typedef struct WMGameInfo {
    u16 magicNumber;
    u8 ver;
    u8 platform;
    u32 ggid;
    u16 tgid;
    u8 userGameInfoLength;
    u8 attribute;
    u16 parentMaxSize;
    u16 childMaxSize;
    u8 userGameInfo[112];
} WMGameInfo;
typedef struct WMBssDesc {
    u16 length;
    u16 rssi;
    u8 bssid[6];
    u16 ssidLength;
    u8 ssid[32];
    u16 capaInfo;
    u16 rateSetBasic;
    u16 rateSetSupport;
    u16 beaconPeriod;
    u16 dtimPeriod;
    u16 channel;
    u16 cfpPeriod;
    u16 cfpMaxDuration;
    u16 gameInfoLength;
    u16 otherElementCount;
    WMGameInfo gameInfo;
} WMBssDesc;
typedef struct WMStartParentCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u8 macAddress[6];
    u16 aid;
    u16 reason;
    u8 ssid[24];
} WMStartParentCallback;
typedef struct WMStartMPCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u8 pad_06[2];
    void *recvBuf;
    u16 timeStamp;
    u16 rate_rssi;
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u16 seqNum;
    u16 tmptt;
    u16 pollbmp;
} WMStartMPCallback;
typedef struct WMPortRecvCallback {
    u16 apiid;
    u16 errcode;
    u16 state;
    u16 port;
    void *recvBuf;
    void *data;
    u16 length;
    u16 aid;
    u8 macAddress[6];
    u16 seqNo;
    void *arg;
    u16 myAid;
    u8 pad_22[2];
    u8 ssid[24];
} WMPortRecvCallback;
typedef struct WMPortSendCallback {
    u16 apiid;
    u16 errcode;
    u16 wlCmdID;
    u16 wlResult;
    u16 state;
    u16 port;
    u16 destBitmap;
    u16 restBitmap;
    u16 sentBitmap;
    u8 pad_12[2];
    const u16 *data;
    u16 size;
    u16 seqNo;
    void (*callback)(void *arg);
    void *arg;
} WMPortSendCallback;
typedef struct RadioChildFrameBuffer {
    u8 pad_00[6];
    u16 length;
    u16 unk_08;
    u16 ackTimeStamp;
    u16 timeStamp;
    u8 rate;
    u8 rssi;
    u8 pad_10[8];
    u8 destAdrs[6];
    u8 srcAdrs[6];
    u8 pad_24[0xa];
    u16 pollBitmap;
    u16 wmHeader;
    u16 data[1];
} RadioChildFrameBuffer;
typedef struct RadioOutboxEntry {
    u16 next;
    u16 port;
    u16 destBitmap;
    u16 restBitmap;
    u16 sentBitmap;
    u16 unk_0a;
    u8 pad_0c[2];
    u16 size;
    u16 seqNo;
    u16 retryCount;
    const u16 *data;
    void (*callback)(void *arg);
    void *arg;
} RadioOutboxEntry;
typedef struct RadioOutboxList {
    u16 head;
    u16 tail;
} RadioOutboxList;
typedef struct WMStatus {
    u16 state;
    u16 busyApiid;
    u32 apiBusy;
    u8 pad_08[4];
    u32 mpFlag;
    u32 unk_10;
    u32 unk_14;
    u32 dcfSendFlag;
    u32 unk_1c;
    u8 wlVersion[8];
    u16 macVersion;
    u16 rfVersion;
    u16 bbpVersion[2];
    u16 unk_30;
    u16 unk_32;
    u16 unk_34;
    u16 unk_36;
    u32 unk_38;
    u16 unk_3c;
    u16 unk_3e;
    u16 unk_40;
    u16 unk_42;
    u16 mpRecvBufSel;
    u16 mpRecvBufSize;
    RadioChildFrameBuffer *mpRecvBuf[2];
    const void *unk_50;
    u16 unk_54;
    u16 unk_56;
    OSAlarm mpAckAlarm;
    u16 mpWaitAckFlag;
    u16 mpReadyBitmap;
    u16 unk_88;
    u16 unk_8a;
    u16 unk_8c;
    u16 unk_8e;
    u16 unk_90;
    u16 unk_92;
    u16 unk_94;
    u16 unk_96;
    u16 unk_98;
    u16 unk_9a;
    u16 unk_9c;
    u8 dcfDestAdr[6];
    const u16 *dcfSendData;
    u16 dcfSendSize;
    u16 dcfRecvBufSel;
    void *dcfRecvBuf[2];
    u16 dcfRecvBufSize;
    u16 tgid;
    u16 linkLevel;
    u16 unk_ba;
    u16 unk_bc;
    u16 unk_be;
    u16 wepKeyId;
    u16 unk_c2;
    u8 pad_c4[6];
    u16 unk_ca;
    u32 unk_cc;
    u32 unk_d0;
    u32 unk_d4;
    u16 unk_d8;
    u16 unk_da;
    u8 macAddress[6];
    u16 unk_e2;
    u8 pparam[0x10];
    u16 unk_f4;
    u8 pad_f6[0x2e];
    u8 childMacAddress[15][6];
    u16 childBitmap;
    WMBssDesc *pInfoBuf;
    u16 aid;
    u8 parentMacAddress[6];
    u16 scanChannel;
    u16 unk_18e;
    u16 unk_190;
    u16 wepMode;
    u32 wepFlag;
    u8 wepKey[80];
    u16 unk_1e8;
    u16 unk_1ea;
    u8 pad_1ec[4];
    u16 enableChannel;
    u16 allowedChannel;
    u16 portSeqNo[16][8];
    RadioOutboxEntry sendQueueData[32];
    RadioOutboxList sendQueueFreeList;
    RadioOutboxList sendQueue[4];
    RadioOutboxList readyQueue[4];
    OSMutex sendQueueMutex;
    u32 sendQueueInUse;
    u64 mpLastRecvTick[16];
    u64 unk_7b0;
} WMStatus;
typedef void (*WMCallbackFunc)(void *arg);
typedef struct WMArm9Buf {
    void *arm7Buf;
    WMStatus *status;
    u8 pad_08[4];
    void *requestBuf;
    void *replyBuf;
    u16 dmaNo;
    u16 scanOnlyFlag;
    WMCallbackFunc callbackTable[41];
    WMCallbackFunc indCallback;
    WMCallbackFunc portCallback[16];
    void *portCallbackArg[16];
    u8 pad_140[0x1c];
    u32 unk_15c;
} WMArm9Buf;
extern int func_0210dab0(void);
extern u16 data_0215b1a8;
extern WMArm9Buf *data_0215b1ac;
typedef struct OSContext {
    u32 cpsr;
    u32 r[13];
    u32 sp;
    u32 lr;
    u32 pcPlus4;
    u32 spSvc;
    u8 cpContext[0x1c];
} OSContext;
struct OSThread {
    OSContext context;
    u32 state;
    OSThread *next;
    u32 id;
    u32 priority;
    void *profiler;
    OSMutex *mutex;
    OSMutexQueue mutexQueue;
    u32 stackTop;
    u32 stackBottom;
    u32 stackWarningOffset;
    OSThreadQueue joinQueue;
};
extern void func_0210469c(void *start, u32 size);
extern void func_021046b8(const void *start, u32 size);
extern void func_02105528(void);
extern void func_0210626c(const void *src, void *dest, u32 size);
extern void func_02106088(const void *src, void *dest, int size);
extern void func_02106070(u16 data, void *dest, int size);
extern void func_0210d458(void);
extern u16 data_0215b1a8;
extern WMArm9Buf *data_0215b1ac;
extern WMPortRecvCallback data_0215b1ec;
static inline void MI_CpuClear16(void *dest, u32 size) {
    volatile u16 zero = 0;

    func_02106070(zero, dest, size);
}
void func_0210d474(u32 tag, u32 data, BOOL err) {
    WMCallback *cb = (WMCallback *) data;
    WMCallbackFunc callback;

    if (err) {
        return;
    }

    func_0210469c(data_0215b1ac->replyBuf, 0x100);
    if (data_0215b1ac->scanOnlyFlag == 0) {
        func_0210469c(data_0215b1ac->status, 0x800);
    }
    if (cb != data_0215b1ac->replyBuf) {
        func_0210469c(cb, 0x100);
    }

    if (cb->apiid >= 41) {
        if (cb->apiid == 0x80) {
            if (cb->errcode == 19) {
                func_02105528();
            }
            if (data_0215b1ac->indCallback != ((void *) 0)) {
                data_0215b1ac->indCallback(cb);
            }
        } else if (cb->apiid == 0x82) {
            WMPortRecvCallback *recv = (WMPortRecvCallback *) cb;

            if (data_0215b1ac->portCallback[recv->port] != ((void *) 0)) {
                recv->arg = data_0215b1ac->portCallbackArg[recv->port];
                func_0210469c(recv->recvBuf, data_0215b1ac->status->mpRecvBufSize);
                data_0215b1ac->portCallback[recv->port](recv);
            }
        } else if (cb->apiid == 0x81) {
            WMPortSendCallback *send = (WMPortSendCallback *) cb;

            cb->apiid = 15;
            if (send->callback != ((void *) 0)) {
                send->callback(send);
            }
        }
    } else {
        if (cb->apiid == 14) {
            WMStartMPCallback *mp = (WMStartMPCallback *) cb;

            if ((mp->state == 11 || mp->state == 12) && mp->errcode == 0) {
                func_0210469c(mp->recvBuf, data_0215b1ac->status->mpRecvBufSize);
            }
        }

        if (cb->apiid == 2 && cb->errcode == 0) {
            callback = data_0215b1ac->callbackTable[cb->apiid];
            func_0210dab0();
            if (callback != ((void *) 0)) {
                callback(cb);
            }
            return;
        }

        callback = data_0215b1ac->callbackTable[cb->apiid];
        if (callback != ((void *) 0)) {
            callback(cb);
            if (data_0215b1a8 == 0) {
                return;
            }
        }

        if (cb->apiid == 8 || cb->apiid == 12) {

            WMStartParentCallback *conn = (WMStartParentCallback *) cb;
            u16 state;
            u16 aid;
            u16 myAid;
            u8 *macAddress;
            u8 *ssid;
            u16 port;

            if (cb->apiid == 8) {
                state      = conn->state;
                aid        = conn->aid;
                myAid      = 0;
                macAddress = conn->macAddress;
                ssid       = conn->ssid;
            } else if (cb->apiid == 12) {
                state      = conn->state;
                aid        = 0;
                myAid      = conn->aid;
                macAddress = conn->macAddress;
                ssid       = ((void *) 0);
            }

            if (state == 7 || state == 9) {
                data_0215b1ec.apiid   = 0x82;
                data_0215b1ec.errcode = 0;
                data_0215b1ec.state   = state;
                data_0215b1ec.recvBuf = ((void *) 0);
                data_0215b1ec.data    = ((void *) 0);
                data_0215b1ec.length  = 0;
                data_0215b1ec.aid     = aid;
                data_0215b1ec.myAid   = myAid;
                data_0215b1ec.seqNo   = 0xffff;
                func_0210626c(macAddress, data_0215b1ec.macAddress, 6);
                if (ssid != ((void *) 0)) {
                    func_02106088(ssid, data_0215b1ec.ssid, 24);
                } else {
                    MI_CpuClear16(data_0215b1ec.ssid, 24);
                }
                for (port = 0; port < 16; port++) {
                    data_0215b1ec.port = port;
                    if (data_0215b1ac->portCallback[port] != ((void *) 0)) {
                        data_0215b1ec.arg = data_0215b1ac->portCallbackArg[port];
                        data_0215b1ac->portCallback[port](&data_0215b1ec);
                    }
                }
            }
        }
    }

    func_0210469c(data_0215b1ac->replyBuf, 0x100);
    func_0210d458();
    if (cb != data_0215b1ac->replyBuf) {
        cb->apiid |= 0x8000;
        func_021046b8(cb, 0x100);
    }
}
