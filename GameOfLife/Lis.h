#pragma once
#include "Zwierze.h"

class Lis : public Zwierze
{
private:
	static const char oznaczenie = 'L';
	static const int inicjatywa = 7;
	int sila = 3;
	int wiek;

public:
	Lis(int pozycjaX, int pozycjaY);
	Lis(int pozycjaX, int pozycjaY, int sila, int wiek);
	void Akcja() override;
};

