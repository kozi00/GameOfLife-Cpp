#pragma once
#include "Zwierze.h"
class Lis : public Zwierze
{
	void akcja() override;
	void kolizja(Organizm* organizm) override;
};

