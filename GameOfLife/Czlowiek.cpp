#include "Czlowiek.h"
#include "Swiat.h"
#include <iostream>

Czlowiek::Czlowiek(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, 5, inicjatywa, oznaczenie) {
	this->wiek = 0;
	this->czasOdnawianiaUmiejetnosci = 5;
	this->czasTrwaniaUmiejetnosci = 5;
	this->umiejetnoscAktywna = false;
	this->umiejetnoscMozeBycAktywowana = true;
}
Czlowiek::Czlowiek(int pozycjaX, int pozycjaY, int sila, int wiek, int czasTrwaniaUmiejetnosci, int czasOdnawianiaUmiejetnosci, bool umiejetnoscAktywna, bool umiejetnoscMozeBycAktywowana) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie, wiek) {
	this->wiek = wiek;
	this->czasOdnawianiaUmiejetnosci = czasOdnawianiaUmiejetnosci;
	this->czasTrwaniaUmiejetnosci = czasTrwaniaUmiejetnosci;
	this->umiejetnoscAktywna = umiejetnoscAktywna;
	this->umiejetnoscMozeBycAktywowana = umiejetnoscMozeBycAktywowana;
}

void Czlowiek::ObslugaUmiejetnosci() {
	if (umiejetnoscAktywna) {
		umiejetnoscMozeBycAktywowana = false;
		std::cout << "Umiejetnosc jest jeszcze aktywna przez " << czasTrwaniaUmiejetnosci << " tur\n";
		czasTrwaniaUmiejetnosci--;
		if (czasTrwaniaUmiejetnosci == 0) {//jesli skonczyl sie czas umiejetnosci
			umiejetnoscAktywna = false;
			czasTrwaniaUmiejetnosci = 5;
		}
	}
	else {
		if (umiejetnoscMozeBycAktywowana) {
			std::cout << "Tarcza Alzura jest gotowa do uzycia\n";
		}
		else {//umiejetnosc sie laduje
			umiejetnoscAktywna = false;
			czasOdnawianiaUmiejetnosci--;
			std::cout << "Umiejetnosc bedzie gotowa do uzycia za " << czasOdnawianiaUmiejetnosci << " tur\n";
			if (czasOdnawianiaUmiejetnosci == 0) {
				umiejetnoscMozeBycAktywowana = true;
				czasOdnawianiaUmiejetnosci = 5;
			}
		}
	}
}

void Czlowiek::Akcja() {
	char move;
	int nowaPozycjaX = 0, nowaPozycjaY = 0;
	
	ObslugaUmiejetnosci();
	std::cout << "Wybierz ruch dla czlowiek(w-gora, s-dol, a-prawo, d-lewo, q-umiejetnosc): ";
	std::cin >> move;
	switch (move) {
	case 'w':
		nowaPozycjaX = this->GetPozycjaX() - 1;
		nowaPozycjaY = this->GetPozycjaY();
		break;
	case 's':
		nowaPozycjaX = this->GetPozycjaX() + 1;
		nowaPozycjaY = this->GetPozycjaY();
		break;
	case 'd':
		nowaPozycjaX = this->GetPozycjaX();
		nowaPozycjaY = this->GetPozycjaY() + 1;
		break;
	case 'a':
		nowaPozycjaX = this->GetPozycjaX();
		nowaPozycjaY = this->GetPozycjaY() - 1;
		break;
	case 'q':
		nowaPozycjaX = this->GetPozycjaX();
		nowaPozycjaY = this->GetPozycjaY();
		if (umiejetnoscMozeBycAktywowana) { umiejetnoscAktywna = true; std::cout << "Umiejetnosc zostala aktywowana\n"; }
		else if(umiejetnoscAktywna){ std::cout << "Umiejetnosc jest juz aktywowana\n"; }
		else std::cout << "Umiejetnosc nie moze byc aktywowana, musisz poczekac " << czasOdnawianiaUmiejetnosci << " tur\n";
		break;
	default:
		nowaPozycjaX = this->GetPozycjaX();
		nowaPozycjaY = this->GetPozycjaY();
		std::cout << "Zly przycisk\n";
		break;
	}
	if (nowaPozycjaX < 0 || nowaPozycjaX >= GetSwiat()->GetRozmiarX() || nowaPozycjaY < 0 || nowaPozycjaY >= GetSwiat()->GetRozmiarY()) {
		std::cout << "Nie mozesz wyjsc poza plansze" << std::endl;
	}
	else {
		std::cout << *this << " idzie na pole ( " << nowaPozycjaX << ", " << nowaPozycjaY << " )\n";
		GetSwiat()->UmiescNaPolu(nowaPozycjaX, nowaPozycjaY, this);
	}
}
void Czlowiek::Kolizja(Organizm* atakujacy) {
	if (umiejetnoscAktywna) {
		if (this->GetOznaczenie() == atakujacy->GetOznaczenie()) {//urodzenie
			std::pair<int, int> wolnePole = this->ZnajdzWolnePole();
			if (wolnePole.first != -1 && wolnePole.second != -1) {
				this->Rozmnoz(wolnePole.first, wolnePole.second);
			}
			std::cout << *this << " rozmnozyl sie z " << *atakujacy << std::endl;
		}
		else {
			std::pair<int, int> wolnePole = this->ZnajdzWolnePole();
			if (wolnePole.first != -1 && wolnePole.second != -1) {
				GetSwiat()->UmiescNaPolu(wolnePole.first, wolnePole.second, atakujacy);
			}
			std::cout << *this << " odparl atak od " << *atakujacy << std::endl;
		}
	}
	else {
		this->Zwierze::Kolizja(atakujacy);
	}
}
int Czlowiek::GetCzasTrwaniaUmiejetnosci() const{
	return czasTrwaniaUmiejetnosci;
}
int  Czlowiek::GetCzasOdnawianiaUmiejetnosci() const {
	return czasOdnawianiaUmiejetnosci;
}
bool  Czlowiek::GetUmiejetnoscAktywna() const {
	return umiejetnoscAktywna;
}
bool  Czlowiek::GetUmiejetnoscMozeBycAktywowana() const {
	return umiejetnoscMozeBycAktywowana;
}

