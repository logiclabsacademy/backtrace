CC = gcc
CFLAGS = -std=c2x -Wall
LDFLAGS = -ldl

all: src/backtrace

src/backtrace: src/backtrace.o
	$(CC) $(CFLAGS) -o bin/src/backtrace src/backtrace.o $(LDFLAGS)

src/backtrace.o: src/backtrace.c
	$(CC) $(CFLAGS) -c src/backtrace.c

clean:
	rm -f *.o bin/src/backtrace

