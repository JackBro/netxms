/****************************************************************************
 Messages for NetXMS Client Proxy
****************************************************************************/

#ifndef _messages_h_
#define _messages_h_

//
// MessageId: MSG_PROXY_STARTED
//
// MessageText:
//
// NetXMS Client Proxy started
//
#define MSG_PROXY_STARTED              ((DWORD)0x00000001)

//
// MessageId: MSG_PROXY_STOPPED
//
// MessageText:
//
// NetXMS Client Proxy stopped
//
#define MSG_PROXY_STOPPED              ((DWORD)0x00000002)

//
// MessageId: MSG_SOCKET_ERROR
//
// MessageText:
//
// Unable to open socket: %1
//
#define MSG_SOCKET_ERROR               ((DWORD)0x00000003)

//
// MessageId: MSG_BIND_ERROR
//
// MessageText:
//
// Unable to bind socket: %1
//
#define MSG_BIND_ERROR                 ((DWORD)0x00000004)

//
// MessageId: MSG_ACCEPT_ERROR
//
// MessageText:
//
// Unable to accept incoming connection: %1
//
#define MSG_ACCEPT_ERROR               ((DWORD)0x00000005)

//
// MessageId: MSG_TOO_MANY_ERRORS
//
// MessageText:
//
// Too many consecutive errors on accept() call
//
#define MSG_TOO_MANY_ERRORS            ((DWORD)0x00000006)

//
// MessageId: MSG_WSASTARTUP_FAILED
//
// MessageText:
//
// WSAStartup failed: %1
//
#define MSG_WSASTARTUP_FAILED          ((DWORD)0x00000007)

//
// MessageId: MSG_DEBUG
//
// MessageText:
//
// %1
//
#define MSG_DEBUG                      ((DWORD)0x00000008)

//
// MessageId: MSG_SIGNAL_RECEIVED
//
// MessageText:
//
// Signal %1 received
//
#define MSG_SIGNAL_RECEIVED            ((DWORD)0x00000009)

//
// MessageId: MSG_INIT_CRYPTO_FAILED
//
// MessageText:
//
// Failed to initialize cryptografy module
//
#define MSG_INIT_CRYPTO_FAILED         ((DWORD)0x0000000a)

//
// MessageId: MSG_LISTENING
//
// MessageText:
//
// Listening on socket %1:%2
//
#define MSG_LISTENING                  ((DWORD)0x0000000b)

//
// MessageId: MSG_EXCEPTION
//
// MessageText:
//
// EXCEPTION %1 (%2) at %3 (crash dump was generated); please send files %4 and %5 to dump@netxms.org
//
#define MSG_EXCEPTION                  ((DWORD)0x0000000c)

//
// MessageId: MSG_DEBUG_LEVEL
//
// MessageText:
//
// Debug level set to %1
//
#define MSG_DEBUG_LEVEL                ((DWORD)0x0000000d)

//
// MessageId: MSG_SELECT_ERROR
//
// MessageText:
//
// Call to select() failed: %1
//
#define MSG_SELECT_ERROR               ((DWORD)0x0000000e)

#endif
