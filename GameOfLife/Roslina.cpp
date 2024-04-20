#include "Swiat.h"
#include "Roslina.h"

Roslina::Roslina(int pozycjaX, int pozycjaY, int sila, char oznaczenie) : Organizm(pozycjaX, pozycjaY, sila, 0, oznaczenie) {

}
void Roslina::Akcja() {
	int szansa = rand() % 50;
	if (szansa == 0) {
		std::pair<int, int> wolnePole = this->ZnajdzWolnePole();
		if (wolnePole.first != -1 && wolnePole.second != -1) {
			this->Rozmnoz(wolnePole.first, wolnePole.second);
		}
		std::cout << *this << " rozsprzestrzenil sie" << std::endl;
	}
}
void Roslina::Kolizja(Organizm* atakujacy) {
	if (this->GetSila() <= atakujacy->GetSila()) {
		atakujacy->ZmienPozycje(this->GetPozycjaX(), this->GetPozycjaY());
		this->UsunZeSwiata(GetSwiat());
		std::cout << *atakujacy << " zjadl " << *this << std::endl;
	}
	else {
		atakujacy->UsunZeSwiata(GetSwiat());
		std::cout << *this << " zabil " << *atakujacy << std::endl;
	}
}