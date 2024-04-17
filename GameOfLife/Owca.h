#pragma once
#include "Zwierze.h"

class Owca : public Zwierze
{
private:
	static const char oznaczenie = 'O';
	static const int sila = 4;
	static const int inicjatywa = 4;

public:
	Owca(int pozycjaX, int pozycjaY);
};

