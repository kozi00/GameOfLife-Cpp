#pragma once
#include "Zwierze.h"
class Lis : public Zwierze
{
private:
	static const char oznaczenie = 'L';
	static const int sila = 3;
	static const int inicjatywa = 7;

public:
	Lis(int pozycjaX, int pozycjaY);
	void akcja() override;
};

