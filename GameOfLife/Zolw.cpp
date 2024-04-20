#include "Zolw.h"
#include "Swiat.h"
#include <iostream>
Zolw::Zolw(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie) {
	this->wiek = 0;
}
Zolw::Zolw(int pozycjaX, int pozycjaY, int sila, int wiek) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie, wiek) {
	this->wiek = wiek;
}

void Zolw::Akcja() {
	int szansa = rand() % 4;
	if (szansa == 3) {
		this->Zwierze::Akcja();
	}
	else {
		std::cout << *this << " zostal na swoim miejscu" << std::endl;
	}
}
void Zolw::Kolizja(Organizm* atakujacy) {
	if (this->GetOznaczenie() == atakujacy->GetOznaczenie()) {//urodzenie
		std::pair<int, int> wolnePole = this->ZnajdzWolnePole();
		if (wolnePole.first != -1 && wolnePole.second != -1) {
			this->Rozmnoz(wolnePole.first, wolnePole.second);
		}
		std::cout << *this << " rozmnozyl sie z " << *atakujacy << std::endl;
	}
	else {
		if (atakujacy->GetSila() >= 5) {
			Zwierze::Kolizja(atakujacy);
		}
		else {
			std::cout << *this << " odparl atak od " << *atakujacy << std::endl;
		}
	}
}
