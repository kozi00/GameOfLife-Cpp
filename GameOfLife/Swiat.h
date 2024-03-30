#pragma once
class Swiat
{
private:
	int sizeX, sizeY;
	char **board;
public:
	Swiat(int sizeX,int sizeY);
	void rysujSwiat();
	void wykonajTure();
	void SetBoard(int x, int y, char znak);
	~Swiat();
};

