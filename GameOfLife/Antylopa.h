#pragma once
#include "Zwierze.h"
class Antylopa : public Zwierze
{
	void akcja() override;
	void kolizja(Organizm* organizm) override;
};

