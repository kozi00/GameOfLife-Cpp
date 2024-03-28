#pragma once
#include "Zwierze.h"
class Wilk : public Zwierze
{
	void akcja() override;
	virtual void kolizja(Organizm* organizm) override;
};

