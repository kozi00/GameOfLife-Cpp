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
#include<fstream>
#include<sstream>
#include <string>

#define PUSTE_POLE (char)219
using namespace std;

Swiat::Swiat(int rozmiarX, int rozmiarY) {
    this->rozmiarX = rozmiarX;
    this->rozmiarY = rozmiarY;
    this->liczbaTur = 1;

    plansza = new char* [rozmiarX];
    for (int i = 0; i < rozmiarX; ++i) {
        plansza[i] = new char[rozmiarY];
    }
    for (int x = 0; x < rozmiarX; x++) {
        for (int y = 0; y < rozmiarY; y++) {
            plansza[x][y] = PUSTE_POLE;
        }
    }
}
void Swiat::Inicjalizuj() {
    this->organizmy = {
       new Zolw(rand() % rozmiarX , rand() % rozmiarY),
       new Wilk(rand() % rozmiarX , rand() % rozmiarY),
       new Antylopa(rand() % rozmiarX , rand() % rozmiarY),
       new Lis(rand() % rozmiarX , rand() % rozmiarY),
       new Owca(rand() % rozmiarX , rand() % rozmiarY),
        //new Czlowiek(rand() % rozmiarX , rand() % rozmiarY),
       new WilczeJagody(rand() % rozmiarX , rand() % rozmiarY),
       new BarszczSosnowskiego(rand() % rozmiarX , rand() % rozmiarY),
       new Trawa(rand() % rozmiarX , rand() % rozmiarY),
       new Mlecz(rand() % rozmiarX , rand() % rozmiarY),
       new Guarana(rand() % rozmiarX , rand() % rozmiarY),
    };
    /*this->organizmy = {
        new Lis(rand() % sizeX , rand() % sizeY),
         new Lis(rand() % sizeX , rand() % sizeY),
          new Lis(rand() % sizeX , rand() % sizeY),
              new Lis(rand() % sizeX , rand() % sizeY),
         new Lis(rand() % sizeX , rand() % sizeY),
          new Lis(rand() % sizeX , rand() % sizeY),
              new Lis(rand() % sizeX , rand() % sizeY),
         new Lis(rand() % sizeX , rand() % sizeY),
          new Lis(rand() % sizeX , rand() % sizeY),
    };*/
    for (Organizm* organizm : organizmy) {
        organizm->DodajDoSwiata(this);
    }
    cout << "Stworzono swiat\n";
}
void Swiat::RysujSwiat() {
    for (int i = 0; i < rozmiarX; ++i) {
        for (int j = 0; j < rozmiarY; ++j) {
            Organizm* organizm = SprawdzPole(i, j);
            if (organizm == nullptr) {
                plansza[i][j] = PUSTE_POLE;
            }
            else {
                plansza[i][j] = organizm->GetOznaczenie();
            }
        }
    }
    cout << "~~~~~~~~~~~~~~Wizualizacja swiata~~~~~~~~~~~~~~\n\t\t";
    for (int i = 0; i < rozmiarX; ++i) {
        for (int j = 0; j < rozmiarY; ++j) {
            cout << plansza[i][j];
        }
        cout << endl << "\t\t";
    }
    cout << "\n";
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
    Organizm* przeciwnik = SprawdzPole(x, y);
    if (przeciwnik == nullptr || przeciwnik == organizm) {
        organizm->ZmienPozycje(x, y);
    }
    else {
        przeciwnik->Kolizja(organizm);
    }
}
void Swiat::WykonajTure() {
    sort(organizmy.begin(), organizmy.end(), Organizm::PorownajInicjatywy);
    cout << "------------------Przebieg tury------------------\n";
    for (int i = 0; i < organizmy.size(); i++) {
        organizmy[i]->Akcja();
    }
    for (Organizm* organizm : organizmy) {
        organizm->Postarz();
    }
    liczbaTur++;
}
int Swiat::GetRozmiarX() const {
    return this->rozmiarX;
}
int Swiat::GetRozmiarY() const {
    return this->rozmiarY;
}
int Swiat::GetLiczbaTur() const {
    return this->liczbaTur;
}
vector<Organizm*>& Swiat::GetOrganizmy(){
    return organizmy;
}
void Swiat::Zapisz() {
    ofstream plik("swiat.txt");
    if (!plik.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku." << endl;
    }
    plik << to_string(rozmiarX) << "-" << to_string(rozmiarY) << "-" << to_string(liczbaTur) << "\n";

    for (Organizm* organizm : organizmy) {
        plik << to_string(organizm->GetOznaczenie()) << "-";
        plik << to_string(organizm->GetPozycjaX()) << "-";
        plik << to_string(organizm->GetPozycjaY()) << "-";
        plik << to_string(organizm->GetInicjatywa()) << "-";
        plik << to_string(organizm->GetSila()) << "-";
        if (dynamic_cast<Czlowiek*>(organizm)) {
            Czlowiek* czlowiek = dynamic_cast<Czlowiek*>(organizm);
            plik << to_string(czlowiek->GetCzasTrwaniaUmiejetnosci()) << "-";
            plik << to_string(czlowiek->GetCzasOdnawianiaUmiejetnosci()) << "-";
            plik << to_string(czlowiek->GetUmiejetnoscAktywna()) << "-";
            plik << to_string(czlowiek->GetUmiejetnoscMozeBycAktywowana()) << "-";
        }
        plik << to_string(organizm->GetWiek()) << "\n";
    }

    plik.close();
    std::cout << "Zapisano rozgrywke\n";
}
void Swiat::Wczytaj() {
    ifstream plik("swiat.txt");
    if (!plik.is_open()) {
        cerr << "Nie mo¿na otworzyæ pliku." << endl;
        return;
    }

    string line;//stworz swiat
    if (getline(plik, line)) {
        istringstream iss(line);
        string token;
        getline(iss, token, '-');
        this->rozmiarX = stoi(token);
        getline(iss, token, '-');
        this->rozmiarY = stoi(token);
        getline(iss, token);
        this->liczbaTur = stoi(token);
    }
    plansza = new char* [rozmiarX];
    for (int i = 0; i < rozmiarX; ++i) {
        plansza[i] = new char[rozmiarY];
    }
    for (int x = 0; x < rozmiarX; x++) {
        for (int y = 0; y < rozmiarY; y++) {
            plansza[x][y] = PUSTE_POLE;
        }
    }
    
    organizmy.clear();//stworz organizmy
    while (getline(plik, line)) {
        istringstream iss(line);
        string token;
        int oznaczenie = 0, pozycjaX = 0, pozycjaY = 0, inicjatywa = 0, wiek = 0, sila = 0, czasTrwaniaUmiejetnosci = 0, czasOdnawianiaUmiejetnosci = 0;
        bool umiejetnoscAktywna = false, umiejetnoscMozeBycAktywowana = false;

        getline(iss, token, '-');
        oznaczenie = stoi(token);
        getline(iss, token, '-');
        pozycjaX = stoi(token);
        getline(iss, token, '-');
        pozycjaY = stoi(token);
        getline(iss, token, '-');
        inicjatywa = stoi(token);
        getline(iss, token, '-');
        sila = stoi(token);
        if (oznaczenie == 'C') {
            getline(iss, token, '-');
            czasTrwaniaUmiejetnosci = stoi(token);
            getline(iss, token, '-');
            czasOdnawianiaUmiejetnosci = stoi(token);
            getline(iss, token, '-');
            umiejetnoscAktywna = stoi(token);
            getline(iss, token, '-');
            umiejetnoscMozeBycAktywowana = stoi(token);
        }
        getline(iss, token);
        wiek = stoi(token);

        Organizm* organizm = nullptr;
        switch (char(oznaczenie)) {
        case 'Z':
            organizm = new Zolw(pozycjaX, pozycjaY, sila, wiek);
            break;
        case 'A':
            organizm = new Antylopa(pozycjaX, pozycjaY, sila, wiek);
            break;
        case 'W':
            organizm = new Wilk(pozycjaX, pozycjaY, sila, wiek);
            break;
        case 'L':
            organizm = new Lis(pozycjaX, pozycjaY, sila, wiek);
            break;
        case 'O':
            organizm = new Owca(pozycjaX, pozycjaY, sila, wiek);
            break;
        case 'C':
            organizm = new Czlowiek(pozycjaX, pozycjaY, sila, wiek, czasTrwaniaUmiejetnosci, czasOdnawianiaUmiejetnosci, umiejetnoscAktywna, umiejetnoscMozeBycAktywowana);
            break;
        case 'B':
            organizm = new BarszczSosnowskiego(pozycjaX, pozycjaY);
            break;
        case 'G':
            organizm = new Guarana(pozycjaX, pozycjaY);
            break;
        case 'M':
            organizm = new Mlecz(pozycjaX, pozycjaY);
            break;
        case 'J':
            organizm = new WilczeJagody(pozycjaX, pozycjaY);
            break;
        case 'T':
            organizm = new Trawa(pozycjaX, pozycjaY);
            break;
        default:
            organizm = nullptr;
            break;
        }
        organizmy.push_back(organizm);
    }
    for (Organizm* organizm : organizmy) {
        organizm->DodajDoSwiata(this);
    }
    plik.close();
    std::cout << "Wczytano rozgrywke\n";
}

Swiat::~Swiat() {
    for (int i = 0; i < rozmiarX; ++i) {
        delete[] plansza[i];
    }
    delete[] plansza;
}