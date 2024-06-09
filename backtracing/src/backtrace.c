#include <stdio.h>
#if defined(__linux__)
#include <execinfo.h>
#include <dlfcn.h>
#elif defined(_WIN32)
// Include the necessary headers for Windows platform
#else 
#error "Unsupported platform"
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
void setup_hook() {
    original_backtrace = dlsym(RTLD_NEXT, "backtrace");
    if (!original_backtrace) {
        fprintf(stderr, "Error: Unable to find original backtrace function.\n");
        return;
    }

    // Set the custom backtrace handler
    if (dlinfo(RTLD_SELF, RTLD_DI_LINKMAP, &custom_backtrace) != 0) {
        fprintf(stderr, "Error: Unable to set custom backtrace handler.\n");
        return;
    }
}

int main() {
    // Set up the hook
    setup_hook();

    // Example usage
    void* buffer[10];
    int frames = backtrace(buffer, 10);

    // Print the stack trace
    for (int i = 0; i < frames; i++) {
        printf("%p\n", buffer[i]);
    }

    return 0;
}

