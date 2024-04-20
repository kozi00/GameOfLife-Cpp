#include "WilczeJagody.h"
#include "Zwierze.h"

WilczeJagody::WilczeJagody(int pozycjaX, int pozycjaY) : Roslina(pozycjaX, pozycjaY, sila, oznaczenie) {
}
void WilczeJagody::Kolizja(Organizm* atakujacy) {

	if (this->GetSila() <= atakujacy->GetSila()) {
		atakujacy->ZmienPozycje(this->GetPozycjaX(), this->GetPozycjaY());
		this->UsunZeSwiata(GetSwiat());
		std::cout << *atakujacy << " zjadl " << *this << std::endl;

		if (dynamic_cast<Zwierze*>(atakujacy)) {
			atakujacy->UsunZeSwiata(GetSwiat());
			std::cout << "Wilcze jagody zatruly i zabil " << *atakujacy << std::endl;
		}
	}
	else {
		atakujacy->UsunZeSwiata(GetSwiat());
		std::cout << *this << " zabil " << *atakujacy << std::endl;
	}
}