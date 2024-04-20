#include "Zwierze.h"
#include "Swiat.h"

#include <iostream>
Zwierze::Zwierze(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie):Organizm(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie) {
}
Zwierze::Zwierze(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie, int wiek) :Organizm(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie, wiek) {
}
void Zwierze::Akcja() {
	int i, nowaPozycjaX, nowaPozycjaY;

	std::pair<int, int> ruch[4] = { {1,0}, { -1, 0}, {0 , 1}, {0, -1} };
	do {
		 i = rand() % 4;
		 nowaPozycjaX = ruch[i].first + this->GetPozycjaX();
		 nowaPozycjaY = ruch[i].second + this->GetPozycjaY();
	} while (nowaPozycjaX < 0 || nowaPozycjaX >= GetSwiat()->GetRozmiarX() || nowaPozycjaY < 0 || nowaPozycjaY >= GetSwiat()->GetRozmiarY());

	std::cout << *this << " idzie na pole ( " << nowaPozycjaX << ", " << nowaPozycjaY << " )\n";
	GetSwiat()->UmiescNaPolu(nowaPozycjaX, nowaPozycjaY, this);
}
void Zwierze::Kolizja(Organizm* atakujacy) {
	if (this->GetOznaczenie() == atakujacy->GetOznaczenie()) {//urodzenie
		std::pair<int,int> wolnePole = this->ZnajdzWolnePole();
		if (wolnePole.first != -1 && wolnePole.second != -1) {
			this->Rozmnoz(wolnePole.first, wolnePole.second);
		}
		std::cout << *this << " rozmnozyl sie z " << *atakujacy << std::endl;
	}
	else {
		if (this->GetSila() <= atakujacy->GetSila()) {
			atakujacy->ZmienPozycje(this->GetPozycjaX(), this->GetPozycjaY());
			this->UsunZeSwiata(GetSwiat());
			std::cout << *atakujacy << " zabil " << *this << std::endl;
		}
		else {
			atakujacy->UsunZeSwiata(GetSwiat());
			std::cout << *this << " zabil " << *atakujacy << std::endl;
		}
	}
}
