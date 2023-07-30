// Косак Аліна, ПІ-18-01
// Балабаник О.К.
#include <iostream>
#include "Header.h"

void gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}