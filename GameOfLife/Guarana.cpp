#include "Guarana.h"
#include "Swiat.h"
Guarana::Guarana(int pozycjaX, int pozycjaY) : Roslina(pozycjaX, pozycjaY, sila, oznaczenie) {
}

void Guarana::Kolizja(Organizm* atakujacy) {
	if (this->GetSila() <= atakujacy->GetSila()) {
		atakujacy->ZmienPozycje(this->GetPozycjaX(), this->GetPozycjaY());
		this->UsunZeSwiata(GetSwiat());
		int sila = atakujacy->GetSila() + 3;
		atakujacy->SetSila(sila);
		std::cout << *atakujacy << " zjadl " << *this << " i zwiekszyl swoja sile" << std::endl;
	}
	else {
		atakujacy->UsunZeSwiata(GetSwiat());
		std::cout << *this << " zabil " << *atakujacy << std::endl;
	}
}
