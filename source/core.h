//
// Created by pwd0kernel on 8/15/2021.
//

#ifndef ACE_CORE_H
#define ACE_CORE_H

#include <vadefs.h>


struct Address {
    static const uintptr_t exec = 0x467020;
};

typedef int(__cdecl* execute_official)(const char* cfg_code);
auto AC_execute = reinterpret_cast<execute_official>(Address::exec);

#endif //ACE_CORE_H
