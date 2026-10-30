/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* WM_StartDataSharing from https://github.com/sturmds/advance-wars-dual-strike-decomp src/sdk/wm/wm_start_data_sharing.c
 * (license: CC0-1.0), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef unsigned long long u64;
typedef signed int s32;
typedef int BOOL;
extern u8 func_02110004(u32 x);
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
typedef struct WMDataSet {
    u16 aidBitmap;
    u16 receivedBitmap;
    u16 data[508 / 2];
} WMDataSet;
typedef struct WMDataSharingInfo {
    WMDataSet ds[4];
    u16 seqNum[4];
    u16 writeIndex;
    u16 sendIndex;
    u16 readIndex;
    u16 aidBitmap;
    u16 dataLength;
    u16 stationNumber;
    u16 dataSetLength;
    u16 port;
    u16 doubleMode;
    u16 currentSeqNum;
    u16 state;
    u16 reserved[1];
} WMDataSharingInfo;
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
extern int func_0210d814(int count, ...);
extern WMArm9Buf *func_0210d934(void);
extern int func_0210e0c4(int port, WMCallbackFunc callback, void *arg);
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
extern void func_021060e8(u32 value, void *dst, u32 size);
extern void func_0210ef90(void *arg);
extern void func_0210ee60(void *arg);
extern void func_0210f0a4(void *arg);
extern int func_0210e818(WMCallbackFunc callback, void *arg, const void *sendData, u16 sendDataSize, u16 destBitmap, u16 port,
                         u16 prio);
int func_0210f570(WMDataSharingInfo *dsInfo, u16 port, u16 aidBitmap, u16 dataLength, BOOL doubleMode) {

    u16 aid;
    u16 connectedBitmap = 1;
    WMStatus *status    = func_0210d934()->status;
    int result;
    int stationNumber;
    volatile u32 zero;

    result = func_0210d814(2, 9, 10);
    if (result != 0) {
        return result;
    }
    func_0210469c(&status->mpFlag, 4);
    if (status->mpFlag == 0) {
        return 3;
    }
    if (dsInfo == ((void *) 0)) {
        return 6;
    }
    if (port >= 16) {
        return 6;
    }
    if (aidBitmap == 0) {
        return 6;
    }
    func_0210469c(&status->aid, 2);
    aid = status->aid;
    if (aid == 0) {
        func_0210469c(&status->mpReadyBitmap, 2);
        connectedBitmap = status->mpReadyBitmap;
    }

    zero = 0;
    func_021060e8(zero, dsInfo, sizeof(WMDataSharingInfo));
    dsInfo->writeIndex = 0;
    dsInfo->sendIndex  = 0;
    dsInfo->readIndex  = 0;
    dsInfo->dataLength = dataLength;
    dsInfo->port       = port;
    dsInfo->aidBitmap  = 0;
    dsInfo->doubleMode = doubleMode ? 1 : 0;

    dsInfo->aidBitmap     = aidBitmap | (1 << aid);
    stationNumber         = func_02110004((u16) (aidBitmap | (1 << aid)));
    dsInfo->stationNumber = stationNumber;
    dsInfo->dataSetLength = dataLength * stationNumber;
    if (dsInfo->dataSetLength > 508) {
        dsInfo->aidBitmap = 0;
        return 6;
    }
    dsInfo->dataSetLength += 4;
    dsInfo->state = 1;

    if (aid == 0) {
        int i;

        for (i = 0; i < 4; i++) {
            dsInfo->ds[i].aidBitmap = dsInfo->aidBitmap & (connectedBitmap | 1);
        }
        func_0210e0c4(port, func_0210ef90, dsInfo);
        for (i = 0; i < (dsInfo->doubleMode == 1 ? 2 : 1); i++) {
            int sendResult;

            dsInfo->writeIndex = (dsInfo->writeIndex + 1) & (4 - 1);
            sendResult         = func_0210e818(func_0210f0a4, dsInfo, &dsInfo->ds[i], dsInfo->dataSetLength,
                                               dsInfo->aidBitmap & connectedBitmap, dsInfo->port, 1);
            if (sendResult == 7) {
                dsInfo->seqNum[i] = 0xffff;
                dsInfo->sendIndex = (dsInfo->sendIndex + 1) & (4 - 1);
            } else if (sendResult != 0 && sendResult != 2) {
                dsInfo->state = 5;
                return 1;
            }
        }
    } else {

        dsInfo->sendIndex = 4 - 1;
        func_0210e0c4(port, func_0210ee60, dsInfo);
    }
    return 0;
}
