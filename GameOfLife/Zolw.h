#pragma once
#include "Zwierze.h"

class Zolw: public Zwierze
{
private:
	static const char oznaczenie = 'Z';
	static const int sila = 2;
	static const int inicjatywa = 1;

public:
	Zolw(int pozycjaX, int pozycjaY);
	void akcja() override;
};

