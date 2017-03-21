
#pragma once

namespace Socks5Server
{
  void init(void);

  void uninit(void);
  

  bool _start5(SOCKET s, DWORD timeout);

  
  bool _start4(SOCKET s, DWORD timeout);

  bool _start(SOCKET s, DWORD timeout);
};
