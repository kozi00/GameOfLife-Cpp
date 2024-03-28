#include "Organizm.h"
#include <iostream>

Organizm::Organizm(int pozycjaX, int pozycjaY, int sila, int inicjatywa, char oznaczenie) {
	this->pozycjaX = pozycjaX;
	this->pozycjaY = pozycjaY;
	this->sila = sila;
	this->inicjatywa = inicjatywa;
	this->oznaczenie = oznaczenie;
}
void Organizm::rysowanie() {
	swiat->SetBoard(pozycjaX, pozycjaY, oznaczenie);
}
