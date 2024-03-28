#pragma once
#include "Zwierze.h"
class Zolw: public Zwierze
{
private:
	const char oznaczenie = 'Z';
	const int sila = 2;
	const int inicjatywa = 1;

public:
	Zolw(int pozycjaX, int pozycjaY);
	void akcja() override;
};

