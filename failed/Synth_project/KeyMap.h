#pragma once
#include <iostream>
#include "olcNoiseMaker.h"

class KeyMap {
public:
	int CurrKey = -1;
	bool keypress = false;
	bool GetKeyVal(int k) { return (GetAsyncKeyState((unsigned char)("QZSEDFTGYHUJK\xbc\xbe"[k])) & 0x8000); }
};