// Косак Аліна, ПІ-18-01
// Балабаник О.К.
#include <iostream>
#include "Header.h"

void line(int n)
{
	SetConsoleCP(866); 
	SetConsoleOutputCP(866); 
	cout << char(201); 
	for (int q = 0; q < n; q++) 
		cout << char(205); 
	cout << char(187); 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
}

void linee(int n)
{
	SetConsoleCP(866); 
	SetConsoleOutputCP(866); 
	for (int q = 0; q < n; q++) 
		cout << char(205); 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251);
}

void line1(int n)
{
	SetConsoleCP(866); 
	SetConsoleOutputCP(866); 
	cout << char(200); 
	for (int q = 0; q < n; q++) 
		cout << char(205); 
	cout << char(188); 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
}

void line2(int n)
{
	SetConsoleCP(866); 
	SetConsoleOutputCP(866); 
	for (int q = 0; q < n; q++) 
		cout << char(186); 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
}

void line3(int n)
{
	SetConsoleCP(866); 
	SetConsoleOutputCP(866); 
	for (int q = 0; q < n; q++) 
		cout << char(196); 
	SetConsoleCP(1251); 
	SetConsoleOutputCP(1251); 
}