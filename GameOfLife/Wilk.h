#pragma once
#include "Zwierze.h"

class Wilk : public Zwierze
{
private:
	static const char oznaczenie = 'W';
	static const int inicjatywa = 5;
	int sila = 9;
	int wiek;

public:
	Wilk(int pozycjaX, int pozycjaY);
	Wilk(int pozycjaX, int pozycjaY, int sila, int wiek);
};

