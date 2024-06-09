#include <windows.h>
#include <stdio.h>

void InjectDLL(DWORD processID, const char* dllPath) {
    HANDLE hProcess = OpenProcess(PROCESS_ALL_ACCESS, FALSE, processID);
    if (hProcess == NULL) {
        fprintf(stderr, "Error: Unable to open process.\n");
        return;
    }

    void* pRemoteMemory = VirtualAllocEx(hProcess, NULL, strlen(dllPath) + 1, MEM_COMMIT, PAGE_READWRITE);
    if (pRemoteMemory == NULL) {
        fprintf(stderr, "Error: Unable to allocate memory in remote process.\n");
        CloseHandle(hProcess);
        return;
    }

    WriteProcessMemory(hProcess, pRemoteMemory, dllPath, strlen(dllPath) + 1, NULL);
    HANDLE hThread = CreateRemoteThread(hProcess, NULL, 0, (LPTHREAD_START_ROUTINE)LoadLibraryA, pRemoteMemory, 0, NULL);
    if (hThread == NULL) {
        fprintf(stderr, "Error: Unable to create remote thread.\n");
        VirtualFreeEx(hProcess, pRemoteMemory, 0, MEM_RELEASE);
        CloseHandle(hProcess);
        return;
    }

    WaitForSingleObject(hThread, INFINITE);
    VirtualFreeEx(hProcess, pRemoteMemory, 0, MEM_RELEASE);
    CloseHandle(hThread);
    CloseHandle(hProcess);
}


int main(int argc, char* argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <process_id> <dll_path>\n", argv[0]);
        return 1;
    }

    DWORD processID = (DWORD)atoi(argv[1]);
    const char* dllPath = argv[2];

    InjectDLL(processID, dllPath);

    return 0;
}