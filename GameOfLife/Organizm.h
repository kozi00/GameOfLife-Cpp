#pragma once
#include <iostream>

class Swiat;

class Organizm
{
	char oznaczenie;
	int sila;
	int inicjatywa;
	int pozycjaX, pozycjaY;
	int wiek;
	Swiat* swiat;
	
public:
	Organizm(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie);
	Organizm(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie, int wiek);
	virtual void Akcja() = 0;
	virtual void Kolizja(Organizm* organizm) = 0;
	std::pair<int,int> ZnajdzWolnePole();
	void Rozmnoz(int x, int y);
	static bool PorownajInicjatywy(const Organizm* a, const Organizm* b);
	void ZmienPozycje(int x, int y);
	void Postarz();
	void DodajDoSwiata(Swiat* swiat);
	void UsunZeSwiata(Swiat* swiat);
	Swiat*& GetSwiat();
	int GetPozycjaX() const;
	int GetPozycjaY() const;
	int GetInicjatywa() const;
	int GetSila() const;
	void SetSila(int s);
	int GetWiek() const;
	char GetOznaczenie() const;
	friend std::ostream& operator<<(std::ostream& out, const Organizm& org);
};

