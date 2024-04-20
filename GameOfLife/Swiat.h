#pragma once
#include <iostream>
#include <vector>

class Organizm;

class Swiat
{
private:
	int rozmiarX, rozmiarY;
	int liczbaTur;
	char **plansza;
	std::vector<Organizm*> organizmy;
public:
	Swiat(int rozmiarX,int rozmiarY);
	void Inicjalizuj();
	void RysujSwiat();
	void WykonajTure();
	Organizm* SprawdzPole(int x, int y);
	int GetRozmiarX() const;
	int GetRozmiarY() const;
	int GetLiczbaTur() const;
	std::vector<Organizm*>& GetOrganizmy();
	void UmiescNaPolu(int x, int y, Organizm* organizm);
	void Zapisz();
	void Wczytaj();
	~Swiat();
};

