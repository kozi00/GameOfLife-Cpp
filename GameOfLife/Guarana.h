#pragma once
#include "Roslina.h"
class Guarana : public Roslina
{
private:
	static const char oznaczenie = 'G';
	static const int sila = 0;

public:
	Guarana(int pozycjaX, int pozycjaY);
	void Kolizja(Organizm* atakujacy) override;
};

