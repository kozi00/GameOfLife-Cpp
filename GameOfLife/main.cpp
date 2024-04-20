#include<iostream>
#include<windows.h>
#include "Swiat.h"


using namespace std;

int main() {
	srand((unsigned)time(NULL));
	SetConsoleTitle(L"Kacper Kozak 198223");\

	int sizeX, sizeY;
	char n;
	cout << "Wpisz wysokosc swiata: ";
	cin >> sizeX;
	cout << "Wpisz szerokosc swiata: ";
	cin >> sizeY;
	Swiat swiat(sizeX, sizeY);
	swiat.Inicjalizuj();
	swiat.RysujSwiat();
	cout << "Kliknij 'n' aby przejsc do nastepnej tury, aby 'z' zapisac rozgrywke, 'w' aby wczytac rozgrywke: ";
	cin >> n;
	std::cout << "\033[2J\033[1;1H";//czysc ekran

	while (swiat.GetLiczbaTur() < 101) {
		switch (n) {
			case 'n':
				std::cout << std::endl;
				cout << "Tura numer: " << swiat.GetLiczbaTur() << "   Liczba organizmow: " << swiat.GetOrganizmy().size() << endl;
				swiat.WykonajTure();
				swiat.RysujSwiat();
				break;
			case 'z':
				swiat.Zapisz();
				break;
			case 'w':
				swiat.Wczytaj();
				std::cout << std::endl;
				cout << "Tura numer: " << swiat.GetLiczbaTur() << "   Liczba organizmow: " << swiat.GetOrganizmy().size() << endl;
				swiat.RysujSwiat();
				break;
			default:
				cout << "Zly przycisk\n";
				break;
		}
		cout << "Kliknij 'n' aby przejsc do nastepnej tury, aby 'z' zapisac rozgrywke, 'w' aby wczytac rozgrywke: ";
		cin >> n;
		std::cout << "\033[2J\033[1;1H";//czysc ekran
	}
	
}