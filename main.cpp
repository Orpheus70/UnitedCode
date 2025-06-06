#include <windows.h>
#include <stdio.h>
#include <iostream>
#include <string>

#include "examplePulseReader.cpp"
#include "LMexample.cpp"
#include "examplePort.cpp"
#include "exampleTomom.cpp"

int main() 
{
    examplePulseReader();
    LMexample();
    send_command("123", callback_result);
    start_measure(callback_result);
    return 0;
}
