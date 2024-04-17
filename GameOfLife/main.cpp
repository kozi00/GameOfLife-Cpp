#include<iostream>
#include<windows.h>
#include "Swiat.h"


using namespace std;

int main() {
	srand((unsigned)time(NULL));
	SetConsoleTitle(L"Kacper Kozak 198223");\

	int sizeX, sizeY;
	cin >> sizeX;
	cin >> sizeY;
	Swiat swiat(sizeX, sizeY);
	swiat.Inicjalizuj();

	while (true) {
		swiat.rysujSwiat();
		swiat.wykonajTure();
		std::cout << "\033[2J\033[1;1H";//clear screen
	}
	
}