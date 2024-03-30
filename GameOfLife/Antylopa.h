#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze
{
private:
	static const char oznaczenie = 'A';
	static const int sila = 4;
	static const int inicjatywa = 4;

public:
	Antylopa(int pozycjaX, int pozycjaY);
	void akcja() override;
};

