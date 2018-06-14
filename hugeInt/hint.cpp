#include "hint.h"
#include <iostream>
using namespace std;

hint::hint() { for(int i = 0; i < 1024; i++) { digits[i] = 0;} }

void hint::randomInit()
{

}

void hint::print()
{
    for(int i = 1023; i >=0; i--){
        cout << (int)digits[i] << ", ";
    }

}
