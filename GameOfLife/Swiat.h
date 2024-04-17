#pragma once
#include <iostream>
#include <vector>

class Organizm;

class Swiat
{
private:
	int sizeX, sizeY;
	char **board;
	std::vector<Organizm*> organizmy;
public:
	Swiat(int sizeX,int sizeY);
	void Inicjalizuj();
	void rysujSwiat();
	void wykonajTure();
	Organizm* SprawdzPole(int x, int y);
	int GetSizeX() const;
	int GetSizeY() const;
	std::vector<Organizm*> GetOrganizmy() const;
	void UmiescNaPolu(int x, int y, Organizm* organizm);
	~Swiat();
};

