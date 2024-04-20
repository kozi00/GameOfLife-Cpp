#pragma once
#include "Roslina.h"
class WilczeJagody : public Roslina
{
private:
	static const char oznaczenie = 'J';
	static const int sila = 99;

public:
	WilczeJagody(int pozycjaX, int pozycjaY);
	void Kolizja(Organizm* atakujacy) override;
};

