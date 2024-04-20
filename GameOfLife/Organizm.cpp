#include "Swiat.h"
#include "Zwierze.h"
#include "Roslina.h"
#include "Zolw.h"
#include "Wilk.h"
#include "Antylopa.h"
#include "Lis.h"
#include "Owca.h"
#include "Czlowiek.h"
#include "WilczeJagody.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"

Organizm::Organizm(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie) {
	this->pozycjaX = pozycjaX;
	this->pozycjaY = pozycjaY;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->oznaczenie = oznaczenie;
	this->wiek = 0;
	this->swiat = nullptr;
}
Organizm::Organizm(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie, int wiek) {
	this->pozycjaX = pozycjaX;
	this->pozycjaY = pozycjaY;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->oznaczenie = oznaczenie;
	this->wiek = wiek;
	this->swiat = nullptr;
}
std::pair<int, int> Organizm::ZnajdzWolnePole() {//ggdzies jest infinite loop
	struct Pole {
		std::pair<int, int> ruch;
		bool sprawdzone;
	};
	int i, pozycjaX, pozycjaY, liczbaSprawdzonychPol = 0;
	bool mozeUrodzic = true;
	Pole pole[4] = {
		{	{1,0}, false},
		{	{0,1}, false},
		{	{-1,0}, false},
		{	{0,-1}, false}
	};
	do {
		i = rand() % 4;
		pozycjaX = pole[i].ruch.first + this->GetPozycjaX();
		pozycjaY = pole[i].ruch.second + this->GetPozycjaY();
		mozeUrodzic = true;

		if (pozycjaX < 0 || pozycjaX >= swiat->GetRozmiarX() || pozycjaY < 0 || pozycjaY >= swiat->GetRozmiarY()) {//sprawdz czy miesci sie na planszy
			pole[i].sprawdzone = true;
			mozeUrodzic = false;
			continue;
		}
		Organizm* innyOrganizm = swiat->SprawdzPole(pozycjaX, pozycjaY);
		if (innyOrganizm == nullptr) {//sprawdz czy nie ma nikogo na polu
			std::pair<int, int> wolnePole(pozycjaX, pozycjaY);
			return wolnePole;
		}
		else {
			pole[i].sprawdzone = true;
			mozeUrodzic = false;
		}

		pole[i].sprawdzone = true;
		liczbaSprawdzonychPol = 0;
		for (Pole p : pole) {
			if (p.sprawdzone) { liczbaSprawdzonychPol++; }
		}
		if (liczbaSprawdzonychPol == 4) {
			std::cout << "Brak miejsca na urodzenie" << std::endl;
			std::pair<int, int> brakWolnegoPola(-1, -1);
			return brakWolnegoPola;
		}
	} while (!mozeUrodzic);
}
void Organizm::Rozmnoz(int x, int y) {
	Organizm* dziecko = this;
	switch (this->GetOznaczenie())
	{
	case 'Z':
		dziecko = new Zolw(x, y);
		break;
	case 'A':
		dziecko = new Antylopa(x, y);
		break;
	case 'W':
		dziecko = new Wilk(x, y);
		break;
	case 'L':
		dziecko = new Lis(x, y);
		break;
	case 'O':
		dziecko = new Owca(x, y);
		break;
	case 'C':
		dziecko = new Czlowiek(x, y);
		break;
	case 'B':
		dziecko = new BarszczSosnowskiego(x, y);
		break;
	case 'G':
		dziecko = new Guarana(x, y);
		break;
	case 'M':
		dziecko = new Mlecz(x, y);
		break;
	case 'J':
		dziecko = new WilczeJagody(x, y);
		break;
	case 'T':
		dziecko = new Trawa(x, y);
		break;
	default:
		dziecko = nullptr;
		break;
	}
	dziecko->DodajDoSwiata(this->swiat);//dodaj wskaznik do swiata
	this->swiat->GetOrganizmy().push_back(dziecko);//dodaj do listy organizmow
	std::cout << *dziecko << " urodzil sie" << std::endl;
}
bool Organizm::PorownajInicjatywy(const Organizm* a, const Organizm* b) {
	if(a->GetInicjatywa() > b->GetInicjatywa()) {
		return true;
	}
	else if(a->GetInicjatywa() == b->GetInicjatywa()){
		return a->GetWiek() > b->GetWiek();
	}
	else {
		return false;
	}
}
void Organizm::ZmienPozycje(int x, int y) {
	this->pozycjaX = x;
	this->pozycjaY = y;
}
void Organizm::Postarz() {
	this->wiek = this->wiek + 1;
}
void Organizm::DodajDoSwiata(Swiat* swiat){
	this->swiat = swiat;
}
void Organizm::UsunZeSwiata(Swiat* swiat) {
	int i = 0;
	for (Organizm* organizm : swiat->GetOrganizmy()) {
		if (organizm == this) {
			swiat->GetOrganizmy().erase(swiat->GetOrganizmy().begin() + i);
			return;
		}
		i++;
	}
}
Swiat*& Organizm::GetSwiat() {
	return swiat;
}
int Organizm::GetPozycjaX() const{
	return pozycjaX;
}
int Organizm::GetPozycjaY() const {
	return pozycjaY;
}
int Organizm::GetInicjatywa() const {
	return inicjatywa;
}
int Organizm::GetSila() const {
	return sila;
}
void Organizm::SetSila(int s) {
	this->sila = s;
}
int Organizm::GetWiek() const {
	return wiek;
}
char Organizm::GetOznaczenie()const {
	return oznaczenie;
}
std::ostream& operator<<(std::ostream& out, const Organizm& org) {
	switch (org.GetOznaczenie())
	{
	case 'Z':
		out << "Zolw na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'A':
		out << "Antylopa na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'W':
		out << "Wilk na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'L':
		out << "Lis na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'O':
		out << "Owca na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'C':
		out << "Czlowiek na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'B':
		out << "Barsz Sosnowskiego na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'G':
		out << "Guarana na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'M':
		out << "Mlecz na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'J':
		out << "Wilcze jagody na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	case 'T':
		out << "Trawa na polu " << "( " << org.GetPozycjaX() << ", " << org.GetPozycjaY() << " ) ";
		break;
	default:
		break;
	}
	return out;
}
