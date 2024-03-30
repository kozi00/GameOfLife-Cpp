#pragma once
#include "Organizm.h"
class Roslina : public Organizm
{
public:
	Roslina(int pozycjaX, int pozycjaY, int sila, char oznaczenie);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) override;
};


