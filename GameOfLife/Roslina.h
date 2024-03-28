#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
public:
	Roslina(int sila, int inicjatywa, int pozycjaX, int pozycjaY);
	virtual void akcja();
	virtual void kolizja(Organizm* organizm);
};


