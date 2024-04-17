#include "Lis.h"
#include "Swiat.h"
#include <iostream>

Lis::Lis(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie) {
}

void Lis::akcja() {
	struct Pole {
		std::pair<int, int> ruch;
		bool sprawdzone;//unikniecie nieskonczonej petli
	};
	int i, nowaPozycjaX, nowaPozycjaY, liczbaSprawdzonychPol = 0;
	bool lisMozeIsc = true;
	Pole pole[4] = { 
		{	{1,0}, false},
		{	{0,1}, false},
		{	{-1,0}, false},
		{	{0,-1}, false} 
	};

	do {
		i = rand() % 4;
		nowaPozycjaX = pole[i].ruch.first + this->GetPozycjaX();
		nowaPozycjaY = pole[i].ruch.second + this->GetPozycjaY();
		
		Organizm* przeciwnyOrganizm = swiat->SprawdzPole(nowaPozycjaX, nowaPozycjaY);
		if (przeciwnyOrganizm != nullptr && Organizm::PorownajSile(przeciwnyOrganizm, this)) {//sprawdz czy przeciwnik jest silniejszy
			lisMozeIsc = false;
		}
		

		pole[i].sprawdzone = true;
		for (Pole p : pole) {//jesli wszystkie pola zostaly sprawdzone to znaczy ze lis jest miedzy silniejszymi organizmami i nie moze wykonac ruchu
			if (p.sprawdzone) { liczbaSprawdzonychPol++; }
		}
		if (liczbaSprawdzonychPol == 4) {
			nowaPozycjaX = this->GetPozycjaX();
			nowaPozycjaY = this->GetPozycjaY();
			break;
		}
	} while (lisMozeIsc == false && (nowaPozycjaX <= 0 || nowaPozycjaX >= swiat->GetSizeX() || nowaPozycjaY <= 0 && nowaPozycjaY >= swiat->GetSizeY()));

	swiat->UmiescNaPolu(nowaPozycjaX, nowaPozycjaY, this);
}


