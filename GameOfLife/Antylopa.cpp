#include "Antylopa.h"
#include "Swiat.h"
#include <iostream>

Antylopa::Antylopa(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie) {
	this->wiek = 0;
}
Antylopa::Antylopa(int pozycjaX, int pozycjaY, int sila, int wiek) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie, wiek) {
	this->wiek = wiek;
}

void Antylopa::Akcja() {
	int i, nowaPozycjaX, nowaPozycjaY;

	std::pair<int, int> ruch[4] = { {2,0}, { -2, 0}, {0 , 2}, {0, -2} };
	do {
		i = rand() % 4;
		nowaPozycjaX = ruch[i].first + this->GetPozycjaX();
		nowaPozycjaY = ruch[i].second + this->GetPozycjaY();
	} while (nowaPozycjaX < 0 || nowaPozycjaX >= GetSwiat()->GetRozmiarX() || nowaPozycjaY < 0 || nowaPozycjaY >= GetSwiat()->GetRozmiarY());

	std::cout << *this << " idzie na pole ( " << nowaPozycjaX << ", " << nowaPozycjaY << " )\n";
	GetSwiat()->UmiescNaPolu(nowaPozycjaX, nowaPozycjaY, this);
}

void Antylopa::Kolizja(Organizm* atakujacy) {
	if (atakujacy->GetOznaczenie() == this->GetOznaczenie()) {
		std::pair<int, int> wolnePole = this->ZnajdzWolnePole();
		if (wolnePole.first != -1 && wolnePole.second != -1) {
			this->Rozmnoz(wolnePole.first, wolnePole.second);
		}
		std::cout << *this << " rozmnozyl sie z " << *atakujacy << std::endl;
	}
	else {
		int szansa = rand() % 2;
		if (szansa == 1) {
			std::pair<int, int> wolnePole = this->ZnajdzWolnePole();
			if (wolnePole.first != -1 && wolnePole.second != -1) {

				atakujacy->ZmienPozycje(this->GetPozycjaX(), this->GetPozycjaY());
				this->ZmienPozycje(wolnePole.first, wolnePole.second);
				std::cout << *this << " uciekl" << std::endl;
			}
			else {
				this->Zwierze::Kolizja(atakujacy);
			}
		}
		else {
			this->Zwierze::Kolizja(atakujacy);
		}
	}
}



