#pragma once
#include "Roslina.h"
class Mlecz : public Roslina
{
private:
	static const char oznaczenie = 'M';
	static const int sila = 0;

public:
	Mlecz(int pozycjaX, int pozycjaY);
	void Akcja() override;
};

