#pragma once
#include "Roslina.h"
class Trawa : public Roslina
{
private:
	static const char oznaczenie = 'T';
	static const int sila = 0;

public:
	Trawa(int pozycjaX, int pozycjaY);
};

