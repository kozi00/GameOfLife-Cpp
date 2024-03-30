#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
private:
	static const char oznaczenie = 'W';
	static const int sila = 9;
	static const int inicjatywa = 5;

public:
	Wilk(int pozycjaX, int pozycjaY);
	void akcja() override;
};

