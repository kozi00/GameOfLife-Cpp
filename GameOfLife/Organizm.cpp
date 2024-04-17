#include "Organizm.h"
#include "Swiat.h"
#include <iostream>

Organizm::Organizm(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie) {
	this->pozycjaX = pozycjaX;
	this->pozycjaY = pozycjaY;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->oznaczenie = oznaczenie;
	this->swiat = nullptr;
}
bool Organizm::PorownajInicjatywy(const Organizm* a, const Organizm* b) {
	return a->GetInicjatywa() > b->GetInicjatywa();
}
bool Organizm::PorownajSile(const Organizm* a, const Organizm* b) {
	return a->GetSila() > b->GetSila();
}
void Organizm::ZmienPozycje(int x, int y) {
	this->pozycjaX = x;
	this->pozycjaY = y;
}
void Organizm::DodajDoSwiata(Swiat* swiat){
	this->swiat = swiat;
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
	return inicjatywa;
}
char Organizm::GetOznaczenie()const {
	return oznaczenie;
}
