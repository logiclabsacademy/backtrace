#include <stdio.h>
#ifdef _LINUX
#include <execinfo.h>
#include <dlfcn.h>
#include <stdint.h>
#elif  _WIN32
#include <windows.h>
#include <DbgHelp.h>
#endif


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

// Function to set up the hook
__attribute__((constructor))
void setup_hook() {
    original_backtrace = dlsym(RTLD_NEXT, "backtrace");
    if (!original_backtrace) {
        fprintf(stderr, "Error: Unable to find original backtrace function.\n");
    }
}

int main() {
    // Example usage
    void* buffer[10];
    int frames = backtrace(buffer, 10);

    // Print the stack trace
    for (int i = 0; i < frames; i++) {
        printf("%p\n", buffer[i]);
    }

    return 0;
}
