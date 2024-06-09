CC = gcc
CFLAGS = -std=c2x -Wall -fPIC
LDFLAGS = -ldl

all: backtrace.so

backtrace.so: src/backtrace.o
	$(CC) -shared -o bin/backtrace.so src/backtrace.o $(LDFLAGS)

src/backtrace.o: src/backtrace.c
	$(CC) $(CFLAGS) -c src/backtrace.c -o src/backtrace.o

clean:
	rm -f src/*.o bin/backtrace.so
