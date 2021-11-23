#pragma once
#include <iostream>

class ADSR {
public:
    double AttackT = 0.05;
    double DecayT = 0.02;
    double ReleaseT = 0.2;

    double SustainA = 0.8;
    double StartA = 0.8;

    double TriggerOn = 0.0;
    double TriggerOff = 0.0;

    bool KeyState = false;

    double GetAmpl(double dTime) {
        double Amplitude = 0.0;
        double cycle = dTime - TriggerOn;

        if (KeyState) {
            if (cycle <= AttackT){ Amplitude = (cycle / AttackT) * StartA; } //attack    
            if (cycle > AttackT && cycle <= (DecayT + AttackT)){ Amplitude = ((cycle - AttackT) / DecayT) * (SustainA - StartA) + StartA; } //decay
            if (cycle > (DecayT + AttackT)){ Amplitude = SustainA; } //sustain           
        }
        else{ Amplitude = (dTime - TriggerOff) / ReleaseT * (0.0 - SustainA) + SustainA; } //release          

        if (Amplitude <= 0.0001){ Amplitude = 0; }          
        return Amplitude;
    }

    void NoteOn(double TimeOn) { KeyState = true; TriggerOn = TimeOn; }
    void NoteOff(double TimeOff) { KeyState = false; TriggerOff = TimeOff; }
};

