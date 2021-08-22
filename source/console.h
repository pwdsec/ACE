//
// Created by pwd0kernel on 8/15/2021.
//

#ifndef ACE_CONSOLE_H
#define ACE_CONSOLE_H

#include <consoleapi2.h>
#include <stdio.h>

static void AllowConsole(const char *cname, const char *window_name, const char *window_new_name) {
    FILE *c;
    AllocConsole();
    freopen_s(&c, "CONOUT$", "w", stdout);
    freopen_s(&c, "CONIN$", "r", stdin);
    SetWindowTextA(FindWindowA(NULL, window_name), window_new_name);
    SetConsoleTitleA(cname);
}

static void ConsoleOutput(const char *text) {
    printf_s("[Console]: %s \n", text);
}

#endif //ACE_CONSOLE_H
