#include <stdio.h>
#ifdef __linux__
#include <execinfo.h>
#include <dlfcn.h>
#include <stdint.h>
#elif defined(_WIN32)
#include <windows.h>
#include <DbgHelp.h>
#endif

#ifdef __linux__
// Original backtrace function pointer
static int (*original_backtrace)(void**, int) = NULL;

// Custom backtrace handler
int custom_backtrace(void** buffer, int size) {
    // Call the original backtrace function
    int frames = original_backtrace(buffer, size);

    // Obfuscate/mangle the stack trace frames
    for (int i = 0; i < frames; i++) {
        buffer[i] = (void*)((uintptr_t)buffer[i] ^ 0xDEADBEEF); // Example mangling
    }

    return frames;
}

__attribute__((constructor))
void setup_hook() {
    original_backtrace = dlsym(RTLD_NEXT, "backtrace");
    if (!original_backtrace) {
        fprintf(stderr, "Error: Unable to find original backtrace function.\n");
    }
}
#elif defined(_WIN32)
// Original function pointers
typedef USHORT (WINAPI *RtlCaptureStackBackTraceType)(ULONG FramesToSkip, ULONG FramesToCapture, PVOID *BackTrace, PULONG BackTraceHash);
static RtlCaptureStackBackTraceType original_RtlCaptureStackBackTrace = NULL;

// Custom backtrace handler
USHORT WINAPI custom_RtlCaptureStackBackTrace(ULONG FramesToSkip, ULONG FramesToCapture, PVOID *BackTrace, PULONG BackTraceHash) {
    // Call the original function
    USHORT frames = original_RtlCaptureStackBackTrace(FramesToSkip, FramesToCapture, BackTrace, BackTraceHash);

    // Obfuscate/mangle the stack trace frames
    for (USHORT i = 0; i < frames; i++) {
        BackTrace[i] = (PVOID)((uintptr_t)BackTrace[i] ^ 0xDEADBEEF); // Example mangling
    }

    return frames;
}

BOOL WINAPI DllMain(HINSTANCE hinstDLL, DWORD fdwReason, LPVOID lpReserved) {
    if (fdwReason == DLL_PROCESS_ATTACH) {
        original_RtlCaptureStackBackTrace = (RtlCaptureStackBackTraceType)GetProcAddress(GetModuleHandle("ntdll.dll"), "RtlCaptureStackBackTrace");
        if (!original_RtlCaptureStackBackTrace) {
            fprintf(stderr, "Error: Unable to find original RtlCaptureStackBackTrace function.\n");
            return FALSE;
        }
    }
    return TRUE;
}
#endif

int main() {
#ifdef __linux__
    // Example usage on Linux
    void* buffer[10];
    int frames = backtrace(buffer, 10);
#elif defined(_WIN32)
    // Example usage on Windows
    PVOID buffer[10];
    USHORT frames = RtlCaptureStackBackTrace(0, 10, buffer, NULL);
#endif

    // Print the stack trace
    for (int i = 0; i < frames; i++) {
        printf("%p\n", buffer[i]);
    }

    return 0;
}
