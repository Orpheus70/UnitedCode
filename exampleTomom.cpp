//#include <iostream>

#ifdef _WIN32
#define IMPORT __declspec(dllimport)
#else
#define IMPORT
#endif
typedef void (*ResultCallbackTomom)(int status, float highAD, float AD , float pulse);

extern "C" {
   IMPORT int start_measure(ResultCallbackTomom callback);
}

void callback_result(int status,float highAD, float AD , float pulse)
{

printf("%d,%f,%f,%f/n",status,highAD,AD,pulse);
}
