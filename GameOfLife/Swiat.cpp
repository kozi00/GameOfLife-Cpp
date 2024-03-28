#include "Swiat.h"
#include "Organizm.h"
#include "Zolw.h"
#include <iostream>
#define EMPTY_FIELD (char)219
Swiat::Swiat(int sizeX, int sizeY) {
    this->sizeX = sizeX;
    this->sizeY = sizeY;

    board = new char* [sizeX];
    for (int i = 0; i < sizeX; ++i) {
        board[i] = new char[sizeY];
    }
    for (int x = 0; x < sizeX; x++) {
        for (int y = 0; y < sizeY; y++) {
            board[x][y] = EMPTY_FIELD;
        }
    }
}
void Swiat::rysujSwiat() {
    for (int i = 0; i < sizeX; ++i) {
        for (int j = 0; j < sizeY; ++j) {
            std::cout << board[i][j];
        }
        std::cout << std::endl;
    }
}
void Swiat::SetBoard(int x, int y, char znak) {
    board[x][y] = znak;
}
void InizjalizujSwiat() {
    new Zolw(2, 3);
    
}
Swiat::~Swiat() {
    for (int i = 0; i < sizeX; ++i) {
        delete[] board[i];
    }
    delete[] board;
}