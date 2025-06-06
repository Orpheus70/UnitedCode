//#include <iostream>

#ifdef _WIN32
#define IMPORT __declspec(dllimport)
#else
#define IMPORT
#endif

extern "C" {
    typedef void (*ResultCallback)(int status, float* pulse, float* spo2);
    IMPORT void start_(ResultCallback callback);
}

// Реализация callback-функции
void resultReceiver(int status, float* pulse, float* spo2) {
    if (status != 0 || !pulse || !spo2) {
        std::cout << "The data has not been read. Repeat the measurement again." << std::endl;
    } else {
        std::cout << "Pulse: " << *pulse << " bpm" << std::endl;
        std::cout << "SpO2: " << *spo2 << " %" << std::endl;
    }
}

int examplePulseReader() {
    start_(resultReceiver);
    return 0;
}