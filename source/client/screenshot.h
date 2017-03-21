/*
  Создание скриншота.
*/
#pragma once

namespace Screenshoot
{

  void init(void);


  void uninit(void);


  IStream *_screenToIStream(LPWSTR mimeType, DWORD quality, WORD rect);


  bool _screenToSocket(SOCKET s, LPWSTR mimeType, DWORD quality, WORD rect);
};
