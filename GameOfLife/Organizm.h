#pragma once
#include "Swiat.h"
class Organizm
{
	char oznaczenie;
	int sila;
	int inicjatywa;
	int pozycjaX, pozycjaY;
	
protected:
	Swiat* swiat;
public:
	Organizm(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie);
	virtual void akcja() = 0;
	virtual void kolizja(Organizm* organizm) = 0;
	void rysowanie() const;
	int GetPozycjaX() const;
	int GetPozycjaY() const;
	void DodajDoSwiata(Swiat* swiat);
	char GetOznaczenie() const; 
};

