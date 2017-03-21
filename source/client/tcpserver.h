
#pragma once

#include "..\common\threadsgroup.h"

namespace TcpServer
{
 
  void init(void);

 
  void uninit(void);


  bool _create(ThreadsGroup::GROUP *group);
};
