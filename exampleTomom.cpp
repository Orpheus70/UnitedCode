#include <iostream>

#ifdef _WIN32
#define IMPORT __declspec(dllimport)
#else
#define IMPORT
#endif
typedef void (*ResultCallback)(int status, float highAD, float AD , float pulse);

extern "C" {
   IMPORT int start_measure(ResultCallback callback);
}

void callback_result(int status,float highAD, float AD , float pulse)
{

printf("%d,%f,%f,%f/n",highAD,AD,pulse);
}
