#pragma once
#include "Zwierze.h"

class Czlowiek : public Zwierze
{
private:
	static const char oznaczenie = 'C';
	static const int inicjatywa = 4;
	int sila = 5;
	int wiek;
	int czasTrwaniaUmiejetnosci;
	int czasOdnawianiaUmiejetnosci;
	bool umiejetnoscAktywna;
	bool umiejetnoscMozeBycAktywowana;

public:
	Czlowiek(int pozycjaX, int pozycjaY);
	Czlowiek(int pozycjaX, int pozycjaY, int sila, int wiek, int czasTrwaniaUmiejetnosci, int czasOdnawianiaUmiejetnosci, bool umiejetnoscAktywna, bool umiejetnoscMozeBycAktywowana);
	void Akcja() override;
	void Kolizja(Organizm* atakujacy) override;
	void ObslugaUmiejetnosci();
	int GetCzasTrwaniaUmiejetnosci() const;
	int GetCzasOdnawianiaUmiejetnosci() const;
	bool GetUmiejetnoscAktywna() const;
	bool GetUmiejetnoscMozeBycAktywowana() const;
};

