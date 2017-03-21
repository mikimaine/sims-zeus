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
    ����� ������������ �������� ������� (RunFileDlg).

    IN owner      - ��������, ����� ���� NULL.
    IN workingDir - ������� ����������, ����� ���� NULL.
    IN title      - ��������� �������, ����� ���� NULL ��� �������� �� ���������.
    IN promt      - ����� �������, ����� ���� NULL ��� �������� �� ���������.
    IN flags      - ����� RFD_*.
  */
  void _showShellRunDialog(HWND owner, const LPWSTR workingDir, const LPWSTR title, const LPWSTR promt, DWORD flags);

  /*
    �������� ����� ����� ������.

    IN fileForRemoving - ������ ��� ����� ��� ��������.

    Return             - true - � ������ ������,
                         false - � ������ ������.
  */
  bool _runBatchForRemoveFile(const LPWSTR fileForRemoving);

  /*    Run the bat-file with proizvolnym content and its posleduschego removal.

    IN context - the contents of the file encoded in OEM, will add an extra perfiksy and
                 postfix.
    
    Return - true - if successful,
                 false - if an error occurs.
  */
  bool _runTempBatch(const LPSTR context);
};
