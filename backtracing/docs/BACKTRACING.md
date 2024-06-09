
```sh
$ gcc -o bin/fib src/fib.c -lDbgHelp
$ gcc -shared -o bin/backtrace.dll src/backtrace.c -lDbgHelp
```

```sh
$ gcc -shared -o bin/backtrace.dll src/backtrace.c -lDbgHelp
$ gcc -o bin/fib src/fib.c -lDbgHelp
```