#pragma once

class Swiat;

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
	int GetPozycjaX() const;
	int GetPozycjaY() const;
	int GetInicjatywa() const;
	int GetSila() const;
	static bool PorownajInicjatywy(const Organizm* a, const Organizm* b);
	static bool PorownajSile(const Organizm* a, const Organizm* b);
	void ZmienPozycje(int x, int y);
	void DodajDoSwiata(Swiat* swiat);
	char GetOznaczenie() const; 
};

