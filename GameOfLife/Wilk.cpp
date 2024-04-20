#include "Wilk.h"

Wilk::Wilk(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, 9, inicjatywa, oznaczenie) {
	this->wiek = 0;
}
Wilk::Wilk(int pozycjaX, int pozycjaY, int sila, int wiek) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie, wiek) {
	this->wiek = wiek;
}

