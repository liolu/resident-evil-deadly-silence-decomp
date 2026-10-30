/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* func_0207e590 from https://github.com/GoldieLeGenie/DQIV-DECOMP libs/NitroSDK/src/wm/wm_ds.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned int u32;
typedef unsigned short u16;
typedef struct UnkWmDataSet {
    u16 aidBitmap;
    u16 receivedBitmap;
    u16 data[14];
    u16 childData[240];
} UnkWmDataSet;
typedef struct UnkWmDataSharingInfo {
    UnkWmDataSet ds[4];
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
    u16 reserved;
} UnkWmDataSharingInfo;
extern u16 *func_0210eb20(UnkWmDataSharingInfo *dsInfo, u32 aidBitmap, u16 *data, u32 aid);
u16 *func_0210eb5c(UnkWmDataSharingInfo *dsInfo, UnkWmDataSet *receiveData, u16 aid) {
    u16 aidBitmap      = receiveData->aidBitmap;
    u16 receivedBitmap = receiveData->receivedBitmap;
    u32 aidBit         = 1U << aid;

    if (dsInfo == 0) {
        return 0;
    }
    if (receiveData == 0) {
        return 0;
    }
    if (!(aidBitmap & aidBit)) {
        return 0;
    }
    if (!(receivedBitmap & aidBit)) {
        return 0;
    }
    return func_0210eb20(dsInfo, aidBitmap, receiveData->data, aid);
}
u16 *func_0210eb20(UnkWmDataSharingInfo *dsInfo, u32 aidBitmap, u16 *data, u32 aid);
