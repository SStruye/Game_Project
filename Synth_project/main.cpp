
#include <iostream>
using namespace std;

#include "olcNoiseMaker.h"
#include "ADSR.h"
#include "WaveForms.h"
#include "KeyMap.h"
#include "Note.h"

ADSR ADSRobj;
WaveForms WaveFormsobj;
KeyMap KeyMapobj;

double makenoise(double dTime) { return ADSRobj.GetAmpl(dTime) * WaveFormsobj.Osc(WaveFormsobj.frequency, dTime, 3, 5.0, 0.005); }

int main()
{   
    vector<wstring> devices = olcNoiseMaker<short>::Enumerate();
    olcNoiseMaker<short> sound(devices[0], 44100, 1, 8, 512);
    sound.SetUserFunction(makenoise);

    while (1) {
        KeyMapobj.keypress = false;
        
        for (int k = 0; k < 15; k++) {
            if (KeyMapobj.GetKeyVal(k)){
                if (KeyMapobj.CurrKey != k) {
                    ADSRobj.NoteOn(sound.GetTime());
                    WaveFormsobj.frequency = WaveFormsobj.NoteIncrement(k);
                    KeyMapobj.CurrKey = k;
                }
                KeyMapobj.keypress = true;
            }
        }
        if (!KeyMapobj.keypress)
            if (KeyMapobj.CurrKey != -1) {
                ADSRobj.NoteOff(sound.GetTime());
                KeyMapobj.CurrKey = -1;
            }
    }
    return 0;
}
