#include "BarszczSosnowskiego.h"
#include "Swiat.h"
#include "Zwierze.h"

BarszczSosnowskiego::BarszczSosnowskiego(int pozycjaX, int pozycjaY) : Roslina(pozycjaX, pozycjaY, sila, oznaczenie) {
}
void BarszczSosnowskiego::Akcja() {
	this->Roslina::Akcja();

	std::pair<int, int> pole[4] = { {1,0}, { -1, 0}, {0 , 1}, {0, -1} };
	for (int i = 0; i < 4; i++) {
		int x = this->GetPozycjaX() + pole[i].first;
		int y = this->GetPozycjaY() + pole[i].second;
		if ((x >= 0 || x < GetSwiat()->GetRozmiarX() || y >= 0 || y < GetSwiat()->GetRozmiarY())) {
			Organizm* organizm = GetSwiat()->SprawdzPole(x, y);
			if (organizm != nullptr) {
				if (dynamic_cast<Zwierze*>(organizm)) {
					organizm->UsunZeSwiata(GetSwiat());
					std::cout << *this << " zabil " << *organizm << std::endl;
				}
			}
		}
	}
}
void BarszczSosnowskiego::Kolizja(Organizm* atakujacy) {
	if (this->GetSila() <= atakujacy->GetSila()) {
		atakujacy->ZmienPozycje(this->GetPozycjaX(), this->GetPozycjaY());
		this->UsunZeSwiata(GetSwiat());
		std::cout << *atakujacy << " zjadl " << *this << std::endl;

		if (dynamic_cast<Zwierze*>(atakujacy)) {
			atakujacy->UsunZeSwiata(GetSwiat());
			std::cout << "Barszcz sosnowskiego zatrul i zabil " << *atakujacy << std::endl;
		}
	}
	else {
		atakujacy->UsunZeSwiata(GetSwiat());
		std::cout << *this << " zabil " << *atakujacy << std::endl;
	}
}