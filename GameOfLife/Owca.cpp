#include "Owca.h"

Owca::Owca(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, 4, inicjatywa, oznaczenie) {
	this->wiek = 0;
}
Owca::Owca(int pozycjaX, int pozycjaY, int sila, int wiek) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie, wiek) {
	this->wiek = wiek;
}


