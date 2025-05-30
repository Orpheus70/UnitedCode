// example.cpp
#include <iostream>

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif
typedef void (*ResultCallback)(int status, float highAD, float AD , float pulse);

extern "C" {

    EXPORT int start_measure(ResultCallback callback_result) {
        
    callback_result(0,120.,80.,160.);
    return 0;
    }
  
}