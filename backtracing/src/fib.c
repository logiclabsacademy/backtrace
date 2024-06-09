#include <stdio.h>
#include <stdlib.h>
#ifdef __linux__
#include <execinfo.h>
#elif defined(_WIN32)
#include <windows.h>
#include <DbgHelp.h>
#endif

void print_backtrace() {
#ifdef __linux__
    void* buffer[10];
    int nptrs = backtrace(buffer, 10);
    backtrace_symbols_fd(buffer, nptrs, fileno(stderr));
#elif defined(_WIN32)
    void* buffer[10];
    USHORT frames = RtlCaptureStackBackTrace(0, 10, buffer, NULL);
    for (USHORT i = 0; i < frames; i++) {
        fprintf(stderr, "%p\n", buffer[i]);
    }
#endif
}

int fib(int n) {
    if (n < 0) {
        fprintf(stderr, "Error: Negative input is not allowed.\n");
        print_backtrace();
        exit(EXIT_FAILURE);
    }
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fib(n-1) + fib(n-2);
}

int main() {
    int n = 10; // Change this value to test different inputs
    printf("Fibonacci of %d is %d\n", n, fib(n));
    // Test with negative input to trigger the backtrace
    n = -5;
    printf("Fibonacci of %d is %d\n", n, fib(n));

    return 0;
}
