#pragma once
#include "Zwierze.h"

class Antylopa : public Zwierze
{
private:
	static const char oznaczenie = 'A';
	static const int inicjatywa = 4;
	int sila = 4;
	int wiek;

public:
	Antylopa(int pozycjaX, int pozycjaY);
	Antylopa(int pozycjaX, int pozycjaY, int sila, int wiek);
	void Akcja() override;
	void Kolizja(Organizm* organizm) override;
};

