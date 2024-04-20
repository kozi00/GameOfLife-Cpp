#pragma once
#include "Zwierze.h"

class Owca : public Zwierze
{
private:
	static const char oznaczenie = 'O';
	static const int inicjatywa = 4;
	int sila = 4;
	int wiek;

public:
	Owca(int pozycjaX, int pozycjaY);
	Owca(int pozycjaX, int pozycjaY, int sila, int wiek);
};

