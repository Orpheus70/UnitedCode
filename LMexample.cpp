//#include <iostream>
//#include <string>

using namespace std;

#ifdef _WIN32
#define IMPORT __declspec(dllimport)
#else
#define IMPORT
#endif

extern "C" {
    typedef void (*Start_Level_Meter_type)(int length_layer1, int length_layer2, int gas_layer);
    IMPORT void Start_Level_Meter(Start_Level_Meter_type CallBack);
}

void CallBack(int length_layer1, int length_layer2, int gas_layer)
{
    cout << "Length Layer 1: " << length_layer1 << "\t";
    cout << "Length Layer 2: " << length_layer2 << "\t";
    cout << "Gas Layer: " << gas_layer << endl;
}
 int LMexample()
 {
    Start_Level_Meter(CallBack);
    return 0;
 }