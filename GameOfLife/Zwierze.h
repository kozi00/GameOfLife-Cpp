#pragma once
#include "Organizm.h"

class Zwierze : public Organizm
{
public:
	Zwierze(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie);
	Zwierze(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie, int wiek);
	virtual void Akcja();
	virtual void Kolizja(Organizm* atakujacy);
};

