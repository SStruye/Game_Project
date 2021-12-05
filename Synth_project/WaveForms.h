#pragma once
#include <iostream>
#include "olcNoiseMaker.h"

class WaveForms {
public:
    atomic<double> frequency = 0.0;
    double BasicWave(double frequency) { return frequency * 2 * PI; }
    int transpose = 15;


    double Osc(double frequency, double dTime, int OscType, double LfoFreq, double LfoAmpl) {

        double freq = BasicWave(frequency) * dTime + LfoAmpl * frequency * sin(BasicWave(LfoFreq * dTime));

        switch (OscType) {
        case 0: return sin(freq); //sine wave      
        case 1: return sin(freq) > 0.0 ? 1 : -1; //square wave       
        case 2: return asin(sin(freq)) * 2.0 * PI; //triangle wave        
        case 3: { double Output = 0.0; for (double n = 1.0; n < 40.0;n++) { Output += (sin(n * freq)) / n; }return Output * (2.0 / PI); } //saw wave
        default: return 0.0;
        }
    }
    double NoteIncrement(int k) { return BaseFreq * pow(root, k + transpose); } 

private:
    double BaseFreq = 110.0; //Base frequency of note A
    double root = pow(2.0, 1.0 / 12.0); //doubles the frequency per note
};

