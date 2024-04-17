#include "Swiat.h"
#include "Organizm.h"
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

#include<algorithm>
#include <iostream>

#define PUSTE_POLE (char)219

Swiat::Swiat(int sizeX, int sizeY) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    board = new char* [sizeX];
    for (int i = 0; i < sizeX; ++i) {
        board[i] = new char[sizeY];
    }
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            board[x][y] = PUSTE_POLE;
        }
    }
}
void Swiat::Inicjalizuj() {
    this->organizmy = {
        new Zolw(rand() % sizeX , rand() % sizeY),
        new Wilk(rand() % sizeX , rand() % sizeY),
        new Antylopa(rand() % sizeX , rand() % sizeY),
        new Lis(rand() % sizeX , rand() % sizeY),
        new Owca(rand() % sizeX , rand() % sizeY),
        new Czlowiek(rand() % sizeX , rand() % sizeY),
        new WilczeJagody(rand() % sizeX , rand() % sizeY),
        new BarszczSosnowskiego(rand() % sizeX , rand() % sizeY),
        new Trawa(rand() % sizeX , rand() % sizeY),
        new Mlecz(rand() % sizeX , rand() % sizeY),
        new Guarana(rand() % sizeX , rand() % sizeY)
    };
    for (Organizm* organizm : organizmy) {
        organizm->DodajDoSwiata(this);
    }
}
void Swiat::rysujSwiat() {
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            for (Organizm* organizm : organizmy) {
                if (i == organizm->GetPozycjaX() && j == organizm->GetPozycjaY()) {
                    board[i][j] = organizm->GetOznaczenie();
                    break;
                }
                else {
                    board[i][j] = PUSTE_POLE;
                }
            }
        }
    }
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}

void Swiat::wykonajTure() {
    sort(organizmy.begin(), organizmy.end(), Organizm::PorownajInicjatywy);
    for (Organizm* organizm : organizmy) {
        organizm->akcja();
    }
}
Organizm* Swiat::SprawdzPole(int x, int y) {
    for (Organizm* organizm : organizmy) {
        if (x == organizm->GetPozycjaX() && y == organizm->GetPozycjaY()) {
            return organizm;
        }
    }
    return nullptr;
}
void Swiat::UmiescNaPolu(int x, int y, Organizm* organizm) {
    if (board[x][y] == PUSTE_POLE) {
        organizm->ZmienPozycje(x, y);
    }
    else {
        //kolizja
    }
}
int Swiat::GetSizeX() const {
    return this->sizeX;
}
int Swiat::GetSizeY() const {
    return this->sizeY;
}
std::vector<Organizm*> Swiat::GetOrganizmy() const{
    return organizmy;
}
Swiat::~Swiat() {
    for (int i = 0; i < sizeX; ++i) {
        delete[] board[i];
    }
    delete[] board;
}