#pragma once
#include "Organizm.h"

class Roslina : public Organizm
{
public:
	Roslina(int pozycjaX, int pozycjaY, int sila, char oznaczenie);
	virtual void Akcja();
	virtual void Kolizja(Organizm* organizm);
};


