#pragma once
#include "Roslina.h"
class BarszczSosnowskiego : public Roslina
{
private:
	static const char oznaczenie = 'B';
	static const int sila = 10;

public:
	BarszczSosnowskiego(int pozycjaX, int pozycjaY);
	void akcja() override;
};

