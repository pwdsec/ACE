#include <Windows.h>

#include "core.h"
#include "console.h"

int __RPC_CALLEE main() {
    AllowConsole("ACE", "AssaultCube", "ACE - 1.0");
    ConsoleOutput("Loaded");
    while (1) {
        char data[99];
        printf("> ");
        fgets(data, 99, stdin);
        AC_execute(data);
    }
}

BOOL APIENTRY DllMain(HMODULE hModule,
                      DWORD ul_reason_for_call,
                      LPVOID lpReserved
) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main, NULL, 0, NULL);
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH:
            break;
        default:
            CreateThread(NULL, 0, (LPTHREAD_START_ROUTINE)main, NULL, 0, NULL);
    }
    return TRUE;
}
