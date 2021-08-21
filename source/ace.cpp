#include <string>
#include <iostream>
#include <Windows.h>

#include "core.h"
#include "console.h"

int __RPC_CALLEE main() {
    Console::Console_A::AllowConsole("ACE", "AssaultCube", "ACE - 1.0");
    std::string data;
    Console::Console_A::ConsoleOutput("Loaded");
    while (true) {
        std::cout << "> ";
        std::getline(std::cin, data);
        if (data == "exit") return 0;
        else AC_execute(data.c_str());
    }
}

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(main), nullptr, 0, nullptr);
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
        default:
            CreateThread(nullptr, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>(main), nullptr, 0, nullptr);
    }
    return TRUE;
}
