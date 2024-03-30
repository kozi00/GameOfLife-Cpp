#include<iostream>
#include<windows.h>
#include "Swiat.h"
#include "Organizm.h"
#include "Zolw.h"
#include "Wilk.h"
#include "Antylopa.h"
#include "Owca.h"
#include "Czlowiek.h"
#include "Lis.h"
#include "BarszczSosnowskiego.h"
#include "Guarana.h"
#include "Mlecz.h"
#include "Trawa.h"
#include "WilczeJagody.h"

#define EMPTY_FIELD (char)219

using namespace std;

int main() {
	srand((unsigned)time(NULL));
	SetConsoleTitle(L"Kacper Kozak 198223");\

	int sizeX, sizeY;
	cin >> sizeX;
	cin >> sizeY;
	Swiat swiat(sizeX,sizeY);
	
	initializer_list<Organizm*> organizmy = {
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
		organizm->DodajDoSwiata(&swiat);
		organizm->rysowanie();
	}
	swiat.rysujSwiat();
	
}