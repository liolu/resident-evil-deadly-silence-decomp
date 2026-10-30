/* compiler: 2.0/sp1p5 */
#include "m2c.h"

extern u8 data_0213bde0[];
extern u8 data_0213be00[];
extern u8 data_0213be10[];
extern u8 data_0213be18[];
extern u8 data_0213be20[];
extern u8 data_0213be28[];
extern u8 data_0213be30[];
extern u8 data_0213be50[];
extern u8 data_0213be70[];
extern u8 data_0213be88[];
extern u8 data_0213bea8[];
extern u8 data_0213db04[];
extern u8 data_0213db0c[];
extern u8 data_0213db1c[];
extern u8 data_02150214[];
extern u8 func_020b1e9c[];
extern u8 func_020b1ea8[];
extern u8 func_020b1ebc[];
extern u8 func_020b1ed8[];
extern u8 func_020b1f10[];
extern u8 func_020b1f30[];
extern u8 func_020b1f50[];
extern u8 func_020b1f88[];
extern u8 func_020b1fa8[];
extern u8 func_020b2360[];
extern u8 func_020b23b0[];
extern u8 func_020b23fc[];
extern u8 func_020b2434[];
extern u8 func_020b24f4[];
extern u8 func_020b25a0[];
extern u8 func_020b25d0[];
extern u8 func_020b2600[];
extern u8 func_020b2648[];
extern u8 func_020b2664[];
extern u8 func_020b26ac[];
extern u8 func_020b2704[];
extern u8 func_020b2720[];
extern u8 func_020b2784[];
extern u8 func_020b27a0[];
extern u8 func_020b27e8[];
extern u8 func_020b2a2c[];
extern u8 func_020b2a80[];
extern u8 func_020b2c04[];
extern u8 func_020b2c6c[];
extern u8 func_020b2cac[];
extern u8 func_020b2cf0[];
extern u8 func_020b2d20[];
extern u8 func_020b2e60[];
extern u8 func_020b2e94[];
extern u8 func_020b2ec8[];
extern u8 func_020b2f00[];
extern u8 func_020b2f4c[];
extern u8 func_020b2fb0[];
extern u8 func_020b2fe4[];
extern u8 func_020b3018[];
extern u8 func_020b3084[];
extern u8 func_020b30bc[];
extern u8 func_020b3140[];
extern u8 func_020b31ac[];
extern u8 func_020b3200[];
extern u8 func_020b325c[];
extern u8 func_020b329c[];
extern u8 func_020b3368[];
extern u8 func_020b34d8[];
extern u8 func_020b364c[];
extern u8 func_020b36bc[];
extern u8 func_020b36f0[];
extern u8 func_020b3728[];
extern u8 func_020b3778[];
extern u8 func_020b3ac4[];
extern u8 func_020b3ae0[];
extern u8 func_020b3ba8[];
extern u8 func_020b3c84[];
extern u8 func_020b3d84[];
extern u8 func_020b3dc8[];
extern u8 func_020b3e18[];
extern u8 func_020b3e8c[];
extern u8 func_020b3ed4[];
extern u8 func_020b3f7c[];
extern u8 func_020b3fd4[];
extern u8 func_020b4038[];
extern u8 func_020b407c[];
extern u8 func_020b40cc[];
extern u8 func_020b41c4[];
extern u8 func_020b421c[];
extern u8 func_020b42d0[];
extern u8 func_020b42ec[];
extern u8 func_020b4394[];
extern u8 func_020b43cc[];
extern u8 func_020b4424[];
extern u8 func_020b44a8[];
extern u8 func_020b4550[];
extern u8 func_020b45a4[];
extern u8 func_020b45e8[];
extern u8 func_020b464c[];
extern u8 func_020b472c[];
extern u8 func_020b4824[];
extern u8 func_020b4aa0[];
extern u8 func_020b4c1c[];
extern u8 func_020b4c68[];
extern u8 func_020b4cb0[];
extern u8 func_020b4e88[];
extern u8 func_020b4f10[];
extern u8 func_020b4f98[];

const u32 data_021225dc[12] = {0x02020101, 0x04040303, 0x06060505, 0x08080707, 0x0A0A0909, 0x0C0C0B0B,
                               0x13130D0D, 0x16161515, 0x19191717, 0x1B1B1A1A, 0x1D1D1C1C, 0x000000FF};
const u32 data_0212260c[15] = {(u32) &data_0213be00, (u32) &data_0213bde0, (u32) &data_0213be28, (u32) &data_0213be30,
                               (u32) &data_0213be18, (u32) &data_0213be10, (u32) &data_0213db1c, (u32) &data_0213be88,
                               (u32) &data_0213be70, (u32) &data_0213db0c, 0x00000000,           (u32) &data_0213db04,
                               (u32) &data_0213be20, (u32) &data_0213be50, (u32) &data_0213bea8};
const u32 data_02122648[28] = {0x00010E20, (u32) &func_020b1fa8, 0x00010021, (u32) &func_020b1f88,
                               0x0001042B, (u32) &func_020b1fa8, 0x00010028, (u32) &func_020b1f50,
                               0x00010033, (u32) &func_020b1f30, 0x00020034, (u32) &func_020b1f10,
                               0x00020035, (u32) &func_020b1ed8, 0x00020047, (u32) &func_020b1ebc,
                               0x0001004D, (u32) &func_020b1ea8, 0x0002044E, (u32) &func_020b1e9c,
                               0x00020425, (u32) &func_020b1e9c, 0x00020215, (u32) &func_020b1e9c,
                               0x00022C46, (u32) &func_020b1e9c, 0x0000005A, 0x00000000};
const u32 data_021226b8[38] = {0x006D0066, 0x007F006F,           0x00960084, 0x00A600A0, 0x00BA00A7, 0x00CD00CA, 0x00DF00DD,
                               0x00E800E6, 0x00EC00EB,           0x00F900F7, 0x00FB00FA, 0x00E80105, 0x01260111, 0x00EB0134,
                               0x0150014A, 0x01680160,           0x0174016E, 0x01780175, 0x017B017A, 0x0183017C, 0x018A0185,
                               0x019F0197, 0x01B601A9,           0x01C201B7, 0x01D301CE, 0x01D901D6, 0x01F101DE, 0x020401FC,
                               0x02090206, (u32) &data_02150214, 0x0241021E, 0x025C0250, 0x026E0262, 0x02790277, 0x0281027C,
                               0x02830282, 0x029D0284,           0x00000298};
const u32 data_02122750[57] = {
    0x03030202, 0x0D0D0A0A, 0x0F0F0E0E, 0x11111010, 0x16161515, 0x1A1A1818, 0x1B1B1A1A, 0x1D1D1C1C, 0x1F1F1D1D, 0x21212020,
    0x24242323, 0x26262525, 0x28282727, 0x2A2A2929, 0x2C2C2B2B, 0x2F2F2D2D, 0x31313030, 0x33333232, 0x37373535, 0x3B3B3838,
    0x40403D3D, 0x44444141, 0x46464545, 0x49494747, 0x4B4B4A4A, 0x4D4D4C4C, 0x51514F4F, 0x53535252, 0x55555454, 0x59595656,
    0x5B5B5A5A, 0x5D605C5F, 0x5F625E61, 0x61646063, 0x63666265, 0x65686467, 0x686B6669, 0x6F736B6F, 0x72767175, 0x75797377,
    0x777B767A, 0x797D787C, 0x7B7F7A7E, 0x8C90888C, 0x8F938E92, 0x95999498, 0x979B969A, 0x999D989C, 0x9BA09A9E, 0x9DA29CA1,
    0xA1A6A0A5, 0xA6ABA3A8, 0xA8ADA7AC, 0xAAAFA9AE, 0xC9CEC3C8, 0xCED3CDD2, 0x00FFCFD4};
const u32 data_02122834[90] = {
    (u32) &func_020b3778, (u32) &func_020b3728, (u32) &func_020b36f0, (u32) &func_020b36bc, (u32) &func_020b364c,
    (u32) &func_020b34d8, (u32) &func_020b3368, (u32) &func_020b329c, (u32) &func_020b325c, (u32) &func_020b3200,
    (u32) &func_020b31ac, (u32) &func_020b3084, (u32) &func_020b3140, (u32) &func_020b30bc, 0x00000000,
    (u32) &func_020b3018, (u32) &func_020b2fe4, (u32) &func_020b2fb0, (u32) &func_020b2f4c, (u32) &func_020b2f00,
    (u32) &func_020b2ec8, (u32) &func_020b2e94, (u32) &func_020b2e60, (u32) &func_020b2d20, (u32) &func_020b2cf0,
    (u32) &func_020b2cac, (u32) &func_020b2c6c, (u32) &func_020b2c04, (u32) &func_020b2a80, 0x00000000,
    (u32) &func_020b2a2c, (u32) &func_020b27e8, (u32) &func_020b4f98, (u32) &func_020b4f10, (u32) &func_020b4cb0,
    (u32) &func_020b4c68, (u32) &func_020b4c1c, (u32) &func_020b27a0, 0x00000000,           (u32) &func_020b2784,
    (u32) &func_020b4aa0, (u32) &func_020b2720, (u32) &func_020b472c, (u32) &func_020b4424, (u32) &func_020b43cc,
    (u32) &func_020b4394, 0x00000000,           (u32) &func_020b2704, (u32) &func_020b42ec, (u32) &func_020b26ac,
    (u32) &func_020b42d0, (u32) &func_020b4824, (u32) &func_020b421c, (u32) &func_020b41c4, (u32) &func_020b40cc,
    (u32) &func_020b2664, (u32) &func_020b407c, (u32) &func_020b4038, (u32) &func_020b3fd4, (u32) &func_020b3f7c,
    (u32) &func_020b3ed4, (u32) &func_020b464c, (u32) &func_020b45e8, (u32) &func_020b3e8c, (u32) &func_020b3e18,
    (u32) &func_020b3dc8, (u32) &func_020b45a4, (u32) &func_020b2648, (u32) &func_020b2600, (u32) &func_020b3d84,
    (u32) &func_020b3c84, (u32) &func_020b4e88, (u32) &func_020b4550, (u32) &func_020b3ba8, (u32) &func_020b25d0,
    (u32) &func_020b25a0, (u32) &func_020b3ae0, (u32) &func_020b3ac4, (u32) &func_020b44a8, 0x00000000,
    0x00000000,           0x00000000,           0x00000000,           (u32) &func_020b24f4, (u32) &func_020b2434,
    (u32) &func_020b2c04, (u32) &func_020b2cf0, (u32) &func_020b23fc, (u32) &func_020b23b0, (u32) &func_020b2360};
