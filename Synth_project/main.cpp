
#include <iostream>
using namespace std;

#include "olcNoiseMaker.h"

double makenoise(double dTime) {
    return 0.5 * sin(440.0 * 2 * 3.14159 * dTime);
}

int main()
{
    vector<wstring> devices = olcNoiseMaker<short>::Enumerate();

    for (auto d : devices) wcout << "found output device: " << d << endl;

    olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);

    sound.SetUserFunction(makenoise);

    while (1) {
        if(GetAsyncKeyState('A') & 0x8000)

    }

    return 0;
}
