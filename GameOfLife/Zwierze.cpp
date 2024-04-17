#include "Zwierze.h"
#include "Swiat.h"

#include <iostream>
Zwierze::Zwierze(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie):Organizm(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie) {
}
void Zwierze::akcja() {
	int i, nowaPozycjaX, nowaPozycjaY;

	std::pair<int, int> ruch[4] = { {1,0}, { -1, 0}, {0 , 1}, {0, -1} };
	do {
		 i = rand() % 4;
		 nowaPozycjaX = ruch[i].first + this->GetPozycjaX();
		 nowaPozycjaY = ruch[i].second + this->GetPozycjaY();
	} while (nowaPozycjaX <= 0 || nowaPozycjaX >= swiat->GetSizeX() || nowaPozycjaY <= 0 && nowaPozycjaY >= swiat->GetSizeY());

	swiat->UmiescNaPolu(nowaPozycjaX, nowaPozycjaY, this);
}
void Zwierze::kolizja(Organizm* organizm) {

}
