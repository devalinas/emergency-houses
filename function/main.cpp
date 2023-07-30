// Косак Аліна, ПІ-18-01
// Балабаник О.К.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
#include "Windows.h"

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	FILE *f, *fb, *newf;
	int n;
	fullConsole();
	f = fopen("streets.txt", "r");
	if (f == NULL)
	{
		cout << "Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit (1);
	}
	newf = fopen("str_operations.txt", "w+");
	if (newf == NULL)
	{
		cout << "Текстовий файл не створено!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	fb = fopen("street.dat", "w+b");
	if (fb == NULL)
	{
		cout << "Бінарний файл не створено!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	fscanf(f, "%i ", &n);
	fwrite(&n, sizeof(int), 1, fb);
	houses* h = new houses[n];
	for(int i=0; i<n; i++)
	{
		fscanf(f, "%s", &h[i].street);
		fwrite(&h[i].street, sizeof(h[i].street), 1, fb);
		fscanf(f, "%i", &h[i].number_house);
		fwrite(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fscanf(f, "%i", &h[i].kol_meshk);
		fwrite(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fscanf(f, "%i ", &h[i].year_construct);
		fwrite(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fscanf(f, "%s ", &h[i].date);
		fwrite(&h[i].date, sizeof(h[i].date), 1, fb);
		fscanf(f, "%s", &h[i].repair);
		fwrite(&h[i].repair, sizeof(h[i].repair), 1, fb);
	} 
	fseek(fb, 0, SEEK_SET);
	menu();
	fclose(f);
	fclose(fb);
	fclose(newf);
	delete[]h;
	system("pause");
	return 0;
}