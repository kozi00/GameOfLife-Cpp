#include "Organizm.h"
#include <iostream>

Organizm::Organizm(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie) {
	this->pozycjaX = pozycjaX;
	this->pozycjaY = pozycjaY;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->oznaczenie = oznaczenie;
}
void Organizm::rysowanie() const{
		swiat->SetBoard(pozycjaX, pozycjaY, oznaczenie);
}
int Organizm::GetPozycjaX() const{
	return pozycjaX;
}
int Organizm::GetPozycjaY() const {
	return pozycjaY;
}
char Organizm::GetOznaczenie()const {
	return oznaczenie;
}
void Organizm::DodajDoSwiata(Swiat* swiat){
	this->swiat = swiat;
}
