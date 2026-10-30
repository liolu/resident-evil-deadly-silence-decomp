/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* DataShare_StoreStationBlock from https://github.com/sturmds/advance-wars-dual-strike-decomp
 * src/sdk/wm/data_share_store_station_block.c (license: CC0-1.0), reused by tools/donor_match.py */
typedef unsigned short u16;
typedef unsigned int u32;
extern int func_021054ac(void);
extern void func_021054c0(int state);
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
extern u16 *func_0210eb20(WMDataSharingInfo *dsInfo, u16 aidBitmap, u16 *receiveBuf, u32 aid);
extern void func_0210ed54(WMDataSharingInfo *dsInfo, u16 aid, u16 *data);
extern void func_02106070(u16 data, void *dest, u32 size);
extern void func_02106088(const void *src, void *dest, u32 size);
void func_0210ed54(WMDataSharingInfo *dsInfo, u16 aid, u16 *data) {
    u16 aidBit = 1 << aid;

    if (dsInfo->aidBitmap & aidBit) {
        u16 *address;
        u16 writeIndex = dsInfo->writeIndex;
        int enabled;

        if ((dsInfo->ds[writeIndex].aidBitmap & aidBit) == 0) {
            if (dsInfo->doubleMode != 1) {
                return;
            }
            writeIndex = (writeIndex + 1) & (4 - 1);
            if ((dsInfo->ds[writeIndex].aidBitmap & aidBit) == 0) {
                return;
            }
        }
        address = func_0210eb20(dsInfo, dsInfo->aidBitmap, dsInfo->ds[writeIndex].data, aid);
        if (data != ((void *) 0)) {
            func_02106088(data, address, dsInfo->dataLength);
        } else {
            volatile u16 zero = 0;
            func_02106070(zero, address, dsInfo->dataLength);
        }
        enabled = func_021054ac();
        dsInfo->ds[writeIndex].aidBitmap &= ~aidBit;
        dsInfo->ds[writeIndex].receivedBitmap |= aidBit;
        func_021054c0(enabled);
    }
}
