#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
private:
	static const char oznaczenie = 'C';
	static const int sila = 5;
	static const int inicjatywa = 4;

public:
	Czlowiek(int pozycjaX, int pozycjaY);
	void akcja() override;
};

