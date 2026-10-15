/* compiler: 1.2/sp2p3 -O4,p -lang c99 -inline on,noauto */
/* gt2FilteredReceive from https://github.com/LagoLunatic/ooe libs/GameSpy/gt2/gt2Main.c (license: CC0-1.0), reused by
 * tools/donor_match.py */
typedef unsigned int gsi_time;
typedef int SOCKET;
extern int socket(int pf, int type, int protocol);
typedef int GT2Bool;
typedef unsigned char GT2Byte;
typedef struct GTI2Socket *GT2Socket;
typedef struct GTI2Connection *GT2Connection;
typedef enum {
    GT2Success,

    GT2OutOfMemory,
    GT2Rejected,
    GT2NetworkError,
    GT2AddressError,
    GT2DuplicateAddress,
    GT2TimedOut,
    GT2NegotiationError,
    GT2InvalidConnection,
    GT2InvalidMessage,
    GT2SendFailed
} GT2Result;
typedef enum {
    GT2LocalClose,
    GT2RemoteClose,

    GT2CommunicationError,
    GT2SocketError,
    GT2NotEnoughMemory
} GT2CloseReason;
typedef void (*gt2SocketErrorCallback)(GT2Socket socket);
typedef void (*gt2ConnectedCallback)(GT2Connection connection, GT2Result result, GT2Byte *message, int len);
typedef void (*gt2ReceivedCallback)(GT2Connection connection, GT2Byte *message, int len, GT2Bool reliable);
typedef void (*gt2ClosedCallback)(GT2Connection connection, GT2CloseReason reason);
typedef void (*gt2PingCallback)(GT2Connection connection, int latency);
typedef struct {
    gt2ConnectedCallback connected;
    gt2ReceivedCallback received;
    gt2ClosedCallback closed;
    gt2PingCallback ping;
} GT2ConnectionCallbacks;
typedef void (*gt2ConnectAttemptCallback)(GT2Socket socket, GT2Connection connection, unsigned int ip, unsigned short port,
                                          int latency, GT2Byte *message, int len);
extern void func_0200d4f4(GT2Connection connection, int filterID, GT2Byte *message, int len, GT2Bool reliable);
typedef GT2Bool (*gt2UnrecognizedMessageCallback)(GT2Socket socket, unsigned int ip, unsigned short port, GT2Byte *message,
                                                  int len);
typedef void (*gt2DumpCallback)(GT2Socket socket, GT2Connection connection, unsigned int ip, unsigned short port,
                                GT2Bool reset, const GT2Byte *message, int len);
typedef struct DArrayImplementation *DArray;
typedef struct HashImplementation *HashTable;
typedef enum {
    GTI2UdpProtocol,
    GTI2VdpProtocol   = 2,
    GTI2AdHocProtocol = 3
} GTI2ProtocolType;
typedef enum {

    GTI2AwaitingServerChallenge,
    GTI2AwaitingAcceptance,

    GTI2AwaitingClientChallenge,
    GTI2AwaitingClientResponse,
    GTI2AwaitingAcceptReject,

    GTI2Connected,
    GTI2Closing,
    GTI2Closed
} GTI2ConnectionState;
typedef struct GTI2Buffer {
    GT2Byte *buffer;
    int size;
    int len;
} GTI2Buffer;
typedef struct GTI2Socket {
    SOCKET socket;

    unsigned int ip;
    unsigned short port;

    HashTable connections;
    DArray closedConnections;

    GT2Bool close;
    GT2Bool error;

    int callbackLevel;
    gt2ConnectAttemptCallback connectAttemptCallback;
    gt2SocketErrorCallback socketErrorCallback;
    gt2DumpCallback sendDumpCallback;
    gt2DumpCallback receiveDumpCallback;
    gt2UnrecognizedMessageCallback unrecognizedMessageCallback;

    void *data;

    int outgoingBufferSize;
    int incomingBufferSize;

    GTI2ProtocolType protocolType;

    int protocolOffset;
    GT2Bool broadcastEnabled;
} GTI2Socket;
typedef struct GTI2Connection {

    unsigned int ip;
    unsigned short port;

    GTI2Socket *socket;

    GTI2ConnectionState state;

    GT2Bool initiated;

    GT2Bool freeAtAcceptReject;

    GT2Result connectionResult;

    gsi_time startTime;
    gsi_time timeout;

    int callbackLevel;
    GT2ConnectionCallbacks callbacks;

    char *initialMessage;
    int initialMessageLen;

    void *data;

    GTI2Buffer incomingBuffer;
    GTI2Buffer outgoingBuffer;
    DArray incomingBufferMessages;
    DArray outgoingBufferMessages;

    unsigned short serialNumber;
    unsigned short expectedSerialNumber;

    char response[32];

    gsi_time lastSend;
    gsi_time challengeTime;

    GT2Bool pendingAck;

    gsi_time pendingAckTime;

    DArray sendFilters;
    DArray receiveFilters;

} GTI2Connection;
extern GT2Bool func_020086f0(GT2Connection connection, int filterID, GT2Byte *message, int len, GT2Bool reliable);
void func_0200d4f4(GT2Connection connection, int filterID, GT2Byte *message, int len, GT2Bool reliable) {
    func_020086f0(connection, filterID, message, len, reliable);
}
