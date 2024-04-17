#include "Czlowiek.h"
#include "Swiat.h">
#include <iostream>

Czlowiek::Czlowiek(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie) {
}

void Czlowiek::akcja() {
	char move;
	int nowaPozycjaX = 0, nowaPozycjaY = 0;
	std::cin >> move;
	switch (move) {
	case 'w':
		nowaPozycjaX = this->GetPozycjaX() - 1;
		nowaPozycjaY = this->GetPozycjaY();
		break;
	case 's':
		nowaPozycjaX = this->GetPozycjaX() + 1;
		nowaPozycjaY = this->GetPozycjaY();
		break;
	case 'd':
		nowaPozycjaX = this->GetPozycjaX();
		nowaPozycjaY = this->GetPozycjaY() + 1;
		break;
	case 'a':
		nowaPozycjaX = this->GetPozycjaX();
		nowaPozycjaY = this->GetPozycjaY() - 1;
		break;
	default:
		break;
	}
	swiat->UmiescNaPolu(nowaPozycjaX, nowaPozycjaY, this);
}

