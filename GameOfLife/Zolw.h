#pragma once
#include "Zwierze.h"

class Zolw: public Zwierze
{
private:
	static const char oznaczenie = 'Z';
	static const int inicjatywa = 1;
	int sila = 2;
	int wiek;
public:
	Zolw(int pozycjaX, int pozycjaY);
	Zolw(int pozycjaX, int pozycjaY, int sila, int wiek);
	void Akcja() override;
	void Kolizja(Organizm* atakujacy) override;
};

