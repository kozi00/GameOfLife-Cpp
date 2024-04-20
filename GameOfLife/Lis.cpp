#include "Lis.h"
#include "Swiat.h"
#include <iostream>

Lis::Lis(int pozycjaX, int pozycjaY) : Zwierze(pozycjaX, pozycjaY, 3, inicjatywa, oznaczenie) {
	this->wiek = 0;
}
Lis::Lis(int pozycjaX, int pozycjaY, int sila, int wiek) : Zwierze(pozycjaX, pozycjaY, sila, inicjatywa, oznaczenie, wiek) {
	this->wiek = wiek;
}
void Lis::Akcja() {
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
		lisMozeIsc = true;

		if (nowaPozycjaX < 0 || nowaPozycjaX >= GetSwiat()->GetRozmiarX() || nowaPozycjaY < 0 || nowaPozycjaY >= GetSwiat()->GetRozmiarY()) {//sprawdz czy miesci sie w planszy
			pole[i].sprawdzone = true;
			lisMozeIsc = false;
			continue;
		}
		
		Organizm* przeciwnyOrganizm = GetSwiat()->SprawdzPole(nowaPozycjaX, nowaPozycjaY);
		if (przeciwnyOrganizm != nullptr && przeciwnyOrganizm->GetSila() > this->GetSila()) {//sprawdz czy przeciwnik jest silniejszy
			pole[i].sprawdzone = true;
			lisMozeIsc = false;
		}
		liczbaSprawdzonychPol = 0;
		for (Pole p : pole) {//jesli wszystkie pola zostaly sprawdzone to znaczy ze lis jest miedzy silniejszymi organizmami i nie moze wykonac ruchu
			if (p.sprawdzone) { liczbaSprawdzonychPol++; }
		}
		if (liczbaSprawdzonychPol == 4) {
			nowaPozycjaX = this->GetPozycjaX();
			nowaPozycjaY = this->GetPozycjaY();
			break;
		}
	} while (!lisMozeIsc);
	std::cout << *this << " idzie na pole ( " << nowaPozycjaX << ", " << nowaPozycjaY << " )\n";
	GetSwiat()->UmiescNaPolu(nowaPozycjaX, nowaPozycjaY, this);
}


