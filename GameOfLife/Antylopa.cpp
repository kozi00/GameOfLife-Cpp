#include "Antylopa.h"
#include "Swiat.h"
#include <iostream>

Antylopa::Antylopa(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie) {
}

void Antylopa::akcja() {
	int i, nowaPozycjaX, nowaPozycjaY;

	std::pair<int, int> ruch[4] = { {2,0}, { -2, 0}, {0 , 2}, {0, -2} };
	do {
		i = rand() % 4;
		nowaPozycjaX = ruch[i].first + this->GetPozycjaX();
		nowaPozycjaY = ruch[i].second + this->GetPozycjaY();
	} while (nowaPozycjaX <= 0 || nowaPozycjaX >= swiat->GetSizeX() || nowaPozycjaY <= 0 && nowaPozycjaY >= swiat->GetSizeY());

	swiat->UmiescNaPolu(nowaPozycjaX, nowaPozycjaY, this);
}



