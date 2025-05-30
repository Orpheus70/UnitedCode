
#include <windows.h>
#include <fstream>
#include <iostream>
#include <string>
#include <thread>
#include <chrono>
#include <random>
#include <sstream>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

typedef void (*ResultCallback)(int status, char* d);

extern "C" {

// Отправка команды устройству
EXPORT int send_command(char *d, ResultCallback callback_result) {

    // Пример вызова callback с фиксированными данными
    callback_result(0, (char*)"123");
    Sleep(1000);

    // Случайный генератор ошибки
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> errorDist(1, 5);
    bool showError = errorDist(gen) == 1;
  
    if (showError) {
        int status = 1;
        callback_result(status, nullptr);
    } else {
        int status = 0;
        callback_result(status, d);
    }

    return 0;
}

} // extern "C"
