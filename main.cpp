#include <stdio.h>
#include <windows.h>

// Макрос для импорта функций из DLL
#ifdef _WIN32
#define IMPORT __declspec(dllimport)
#else
#define IMPORT
#endif

typedef void (*ResultCallback)(int status, char* d);

extern "C" {
    IMPORT int send_command(char *d, ResultCallback callback_result);
}

// Реализация callback-функции
void callback_result(int status, char *d) {
    printf("%d %s\n", status, d);
}

int main() {
    send_command("123", callback_result);
    return 0;
}
