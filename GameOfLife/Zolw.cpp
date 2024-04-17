#include "Zolw.h"
#include "Swiat.h"
#include <iostream>
Zolw::Zolw(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie) {
}

void Zolw::akcja() {
	int szansa = rand() % 4;
	if (szansa < 3) {

	}
	else {
		Zwierze::akcja();
	}
}
