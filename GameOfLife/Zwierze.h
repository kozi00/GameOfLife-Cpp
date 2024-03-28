#pragma once
#include "Organizm.h"
class Zwierze : public Organizm
{
public:
	Zwierze(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) override;
};

