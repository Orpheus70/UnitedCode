#include <stdio.h>
#include <windows.h>

// Макрос для импорта функции из DLL
#ifdef _WIN32
#define IMPORT __declspec(dllimport)
#else
#define IMPORT
#endif

typedef void (*ResultCallbackPort)(int status, const char* d);

// Временная реализация send_command для теста
int send_command(const char* d, ResultCallbackPort callback_result) {
    callback_result(0, d);
    return 0;
}

// Реализация callback-функции
void callback_result(int status, const char* d) {
    printf("%d %s\n", status, d);
}



