#include <iostream>
#include <fstream>
#include <string>
#include <random>


using namespace std;

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

typedef void (*Start_Level_Meter_type)(int length_layer1, int length_layer2, int gas_layer);

extern "C" {
    EXPORT void Start_Level_Meter(Start_Level_Meter_type CallBack)
    {
        ifstream data_level("input.txt");

        int Length_pipe = 10;
        bool Gas_environment = true;
        data_level >> Length_pipe >> Gas_environment;
        int randomEr = rand() % 100;

        int length_layer1; 
        int length_layer2; 
        int gas_layer;
        
        if(randomEr >= 90)
        {
            Length_pipe *= 1.1 ;
        }

        if(Gas_environment){
            length_layer1 = rand() % Length_pipe;
            length_layer2 = rand() % (Length_pipe-length_layer1);
            gas_layer = Length_pipe - (length_layer1 + length_layer2);
        }
        else{
            length_layer1 = rand() % Length_pipe;
            length_layer2 = Length_pipe - length_layer1;
            gas_layer = 0;
        }
        CallBack(length_layer1, length_layer2, gas_layer);

        /*
        cout << "Length pipe: " << Length_pipe << "\t";
        cout << "Gas environment: " << Gas_environment << endl;
        */




    } 
}

// float Length_pipe,bool Gas_environment