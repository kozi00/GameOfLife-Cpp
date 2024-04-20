#include "Mlecz.h"
Mlecz::Mlecz(int pozycjaX, int pozycjaY) : Roslina(pozycjaX, pozycjaY, sila, oznaczenie) {
}

void Mlecz::Akcja() {
	for (int i = 0; i < 3; i++) {
		this->Roslina::Akcja();
	}
}
