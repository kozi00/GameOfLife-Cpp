#include<iostream>
#include<windows.h>
#include "Swiat.h"
#include "Zolw.h"

#define EMPTY_FIELD (char)219

using namespace std;

int main() {
	int sizeX, sizeY;
	SetConsoleTitle(L"Kacper Kozak 198223");
	cin >> sizeX;
	cin >> sizeY;
	Swiat swiat(sizeX,sizeY);
	swiat.rysujSwiat();
	
}