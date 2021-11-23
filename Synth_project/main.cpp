
#include <iostream>
using namespace std;

#include "olcNoiseMaker.h"
#include "ADSR.h"

atomic<double> frequency = 0.0;
double BaseFreq = 110.0;
double root = pow(2.0, 1.0 / 12.0);


double BasicWave(double frequency) { return frequency * 2 * PI; }


double Osc(double frequency, double dTime, int OscType) {
    switch (OscType) {
    case 0: return sin(BasicWave(frequency) * dTime); //sine wave      
    case 1: return sin(BasicWave(frequency) * dTime) > 0.0 ? 1 : -1; //square wave       
    case 2: return asin(sin(BasicWave(frequency) * dTime)) * 2.0 * PI; //triangle wave        
    case 3: return (2.0 / PI) * (frequency * PI * fmod(dTime, 1.0 / frequency) - (PI / 2.0)); //saw wave       
    default: return 0.0;       
    }
}

ADSR ADSRobj;
double makenoise(double dTime) { return ADSRobj.GetAmpl(dTime) * Osc(frequency, dTime, 0); }

int main()
{
    
    vector<wstring> devices = olcNoiseMaker<short>::Enumerate();

    for (auto d: devices) wcout << "found output device: " << d << endl;

    olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);

    sound.SetUserFunction(makenoise);

    int CurrKey = -1;

    while (1) {

        bool keypress = false;

        for (int k = 0; k < 15; k++) {

            if (GetAsyncKeyState((unsigned char)("QZSEDFTGYHUJK\xbc\xbe"[k])) & 0x8000){
                if (CurrKey != k) {
                    ADSRobj.NoteOn(sound.GetTime());
                    frequency = BaseFreq * pow(root, k + 3);                
                    CurrKey = k;
                }
                keypress = true;
            }
        }
        if (!keypress)
            if (CurrKey != -1) {
                ADSRobj.NoteOff(sound.GetTime());
                CurrKey = -1;
            }
    }

    return 0;
}
