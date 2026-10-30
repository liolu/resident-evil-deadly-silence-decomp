/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* SND_ReadTrackInfo from https://github.com/ntrtwl/NitroSDK libraries/snd/src/snd_work.c (license: none), reused by
 * tools/donor_match.py */
typedef unsigned char u8;
typedef unsigned short int u16;
typedef unsigned long u32;
typedef unsigned long long int u64;
typedef signed char s8;
typedef signed short int s16;
typedef signed long s32;
typedef int BOOL;
typedef enum {
    SND_DUTY_1_8,
    SND_DUTY_2_8,
    SND_DUTY_3_8,
    SND_DUTY_4_8,
    SND_DUTY_5_8,
    SND_DUTY_6_8,
    SND_DUTY_7_8
} SNDDuty;
typedef enum SNDExChannelCallbackStatus {
    SND_EX_CHANNEL_CALLBACK_DROP,
    SND_EX_CHANNEL_CALLBACK_FINISH
} SNDExChannelCallbackStatus;
typedef void (*SNDExChannelCallback)(struct SNDExChannel *ch_p, SNDExChannelCallbackStatus status, void *userData);
typedef struct SNDWaveParam {
    u8 format;
    u8 loopflag;
    u16 rate;
    u16 timer;
    u16 loopstart;
    u32 looplen;
} SNDWaveParam;
typedef struct SNDLfoParam {
    u8 target;
    u8 speed;
    u8 depth;
    u8 range;
    u16 delay;
} SNDLfoParam;
typedef struct SNDLfo {
    struct SNDLfoParam param;
    u16 delay_counter;
    u16 counter;
} SNDLfo;
typedef struct SNDExChannel {
    u8 myNo;
    u8 type;
    u8 env_status;
    u8 active_flag : 1;
    u8 start_flag : 1;
    u8 auto_sweep : 1;
    u8 sync_flag : 5;
    u8 pan_range;
    u8 original_key;
    s16 user_decay2;
    u8 key;
    u8 velocity;
    s8 init_pan;
    s8 user_pan;
    s16 user_decay;
    s16 user_pitch;
    s32 env_decay;
    s32 sweep_counter;
    s32 sweep_length;
    u8 attack;
    u8 sustain;
    u16 decay;
    u16 release;
    u8 prio;
    u8 pan;
    u16 volume;
    u16 timer;
    struct SNDLfo lfo;
    s16 sweep_pitch;
    s32 length;

    struct SNDWaveParam wave;
    union {
        const void *data;
        SNDDuty duty;
    };

    SNDExChannelCallback callback;
    void *callback_data;
    struct SNDExChannel *nextLink;
} SNDExChannel;
typedef struct SNDPlayer {
    u8 active_flag : 1;
    u8 prepared_flag : 1;
    u8 pause_flag : 1;
    u8 pad_ : 5;
    u8 myNo;
    u8 pad2_;
    u8 pad3_;
    u8 prio;
    u8 volume;
    s16 extFader;
    u8 tracks[16];
    u16 tempo;
    u16 tempo_ratio;
    u16 tempo_counter;
    u16 pad__;
    struct SNDBankData *bank;
} SNDPlayer;
typedef struct SNDTrack {
    u8 active_flag : 1;
    u8 note_wait : 1;
    u8 mute_flag : 1;
    u8 tie_flag : 1;
    u8 note_finish_wait : 1;
    u8 porta_flag : 1;
    u8 cmp_flag : 1;
    u8 channel_mask_flag : 1;
    u8 pan_range;
    u16 prgNo;
    u8 volume;
    u8 volume2;
    s8 pitch_bend;
    u8 bend_range;
    s8 pan;
    s8 ext_pan;
    s16 extFader;
    s16 ext_pitch;
    u8 attack;
    u8 decay;
    u8 sustain;
    u8 release;
    u8 prio;
    s8 transpose;
    u8 porta_key;
    u8 porta_time;
    s16 sweep_pitch;
    struct SNDLfoParam mod;
    u16 channel_mask;
    s32 wait;
    const u8 *base;
    const u8 *cur;
    const u8 *call_stack[3];
    u8 loop_count[3];
    u8 call_stack_depth;
    struct SNDExChannel *channel_list;
} SNDTrack;
typedef struct OSiAlarm OSAlarm;
typedef u64 OSTick;
typedef void (*OSAlarmHandler)(void *);
struct OSiAlarm {
    OSAlarmHandler handler;
    void *arg;
    u32 tag;
    OSTick fire;
    OSAlarm *prev;
    OSAlarm *next;
    OSTick period;
    OSTick start;
};
typedef struct SNDAlarm {
    u8 enable;
    u8 id;
    u16 padding;
    struct {
        OSTick tick;
        OSTick period;
    } setting;
    OSAlarm alarm;
} SNDAlarm;
typedef struct SNDWork {
    SNDExChannel channel[16];
    SNDPlayer player[16];
    SNDTrack track[32];

    SNDAlarm alarm[8];

} SNDWork;
typedef struct SNDDriverInfo {
    SNDWork work;
    u32 chCtrl[16];
    SNDWork *workAddress;
    u32 lockedChannels;
    u32 padding[6];
} SNDDriverInfo;
typedef struct SNDTrackInfo {
    u16 prgNo;
    u8 volume;
    u8 volume2;
    s8 pitchBend;
    u8 bendRange;
    u8 pan;
    s8 transpose;
    u8 pad_;
    u8 chCount;
    u8 channel[16];
} SNDTrackInfo;
extern BOOL func_021074f0(const SNDDriverInfo *driverInfo, int playerNo, int trackNo, SNDTrackInfo *trackInfo);
extern const void *ConvAddr(const void *p, const void *baseFrom, const void *baseTo);
static inline

    const void *
    ConvAddr(const void *p, const void *baseFrom, const void *baseTo) {
    if (p == ((void *) 0)) {
        return ((void *) 0);
    }
    return (const char *) baseTo + ((const char *) p - (const char *) baseFrom);
}
BOOL func_021074f0(const SNDDriverInfo *driverInfo, int playerNo, int trackNo, SNDTrackInfo *trackInfo) {
    const SNDPlayer *player;
    const SNDTrack *track;
    u8 trackID;

    ((void) 0);
    ((void) 0);

    if (playerNo < 0 || 15 < playerNo) {
        return 0;
    }

    if (trackNo < 0 || 16 - 1 < trackNo) {
        return 0;
    }

    player = &driverInfo->work.player[playerNo];
    ((void) 0);

    trackID = player->tracks[trackNo];
    if (trackID == 0xff) {
        return 0;
    }

    track = &driverInfo->work.track[trackID];
    ((void) 0);

    trackInfo->prgNo     = track->prgNo;
    trackInfo->volume    = track->volume;
    trackInfo->volume2   = track->volume2;
    trackInfo->pitchBend = track->pitch_bend;
    trackInfo->bendRange = track->bend_range;
    trackInfo->pan       = (u8) (track->pan + 64);
    trackInfo->transpose = track->transpose;

    {
        const SNDExChannel *chp =
            (const SNDExChannel *) ConvAddr(track->channel_list, driverInfo->workAddress, &driverInfo->work);

        trackInfo->chCount = 0;
        while (chp != ((void *) 0)) {
            trackInfo->channel[trackInfo->chCount] = chp->myNo;
            trackInfo->chCount++;

            chp = (const SNDExChannel *) ConvAddr(chp->nextLink, driverInfo->workAddress, &driverInfo->work);
        }
    }

    return 1;
}
