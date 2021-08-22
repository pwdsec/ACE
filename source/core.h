//
// Created by pwd0kernel on 8/15/2021.
//

#ifndef ACE_CORE_H
#define ACE_CORE_H

#include <vadefs.h>

typedef int(__cdecl* execute_official)(const char* cfg_code);
auto AC_execute = execute_official(0x467020);

#endif //ACE_CORE_H
