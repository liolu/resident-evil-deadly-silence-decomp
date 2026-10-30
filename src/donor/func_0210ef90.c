/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* DataShare_OnParentPortRecv from https://github.com/sturmds/advance-wars-dual-strike-decomp
 * src/sdk/wm/data_share_on_parent_port_recv.c (license: CC0-1.0), reused by tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;
typedef int BOOL;
extern int func_021054ac(void);
extern void func_021054c0(int state);
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
extern void func_0210ebc8(WMDataSharingInfo *dsInfo, BOOL delayed);
extern void func_0210ed54(WMDataSharingInfo *dsInfo, u16 aid, u16 *data);
void func_0210ef90(void *arg) {
    WMPortRecvCallback *cb    = arg;
    WMDataSharingInfo *dsInfo = cb->arg;

    if (dsInfo == ((void *) 0)) {
        return;
    }
    if (cb->errcode == 0) {
        switch (cb->state) {
            case 21:
                func_0210ed54(dsInfo, cb->aid, cb->data);
                func_0210ebc8(dsInfo, 0);
                break;
            case 7:
                func_0210ebc8(dsInfo, 0);
                break;
            case 9: {
                u32 aidBit     = 1 << cb->aid;
                int enabled    = func_021054ac();
                u16 writeIndex = dsInfo->writeIndex;

                dsInfo->ds[writeIndex].aidBitmap &= ~aidBit;
                if (dsInfo->doubleMode == 1) {

                    dsInfo->ds[(u16) ((writeIndex + 1) & (4 - 1))].aidBitmap &= ~aidBit;
                }
                func_021054c0(enabled);
                func_0210ebc8(dsInfo, 0);
                if (dsInfo->doubleMode == 1) {
                    func_0210ebc8(dsInfo, 0);
                }
                break;
            }
        }
    } else {
        dsInfo->state = 5;
    }
}
