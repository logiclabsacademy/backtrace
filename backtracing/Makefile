CC = gcc
CFLAGS = -std=c2x -Wall -fPIC

# Detect platform
ifeq ($(OS),Windows_NT)
    TARGET = backtrace.dll
    CFLAGS += -D_WIN32
    LDFLAGS =
else
    TARGET = backtrace.so
    CFLAGS += -D__linux__
    LDFLAGS = -ldl
endif

all: $(TARGET) fib

fib: src/fib.o
	$(CC) $(CFLAGS) -o bin/$@ $<

src/fib.o: src/fib.c
	$(CC) $(CFLAGS) -c $< -o $@

backtrace.so: src/backtrace.o
	$(CC) -shared -o bin/$@ $< $(LDFLAGS)

backtrace.dll: src/backtrace.o
	$(CC) -shared -o bin/$@ $< $(LDFLAGS)

src/backtrace.o: src/backtrace.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f src/*.o bin/$(TARGET)
