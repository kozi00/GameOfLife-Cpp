#pragma once
#include "Zwierze.h"
class Owca : public Zwierze
{
	void akcja() override;
	void kolizja(Organizm* organizm) override;
};

