// Косак Аліна, ПІ-18-01
// Балабаник О.К.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
using namespace std;

//меню 1
int output1()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* f;
	f = fopen("streets.txt", "r"); // відкриття файлу для зчитування
	if (f == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, numb;
	shapka();
	fscanf(f, "%i", &n);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fscanf(f, "%s", &h[i].street);
		fscanf(f, "%i", &h[i].number_house);
		fscanf(f, "%i", &h[i].kol_meshk);
		fscanf(f, "%i ", &h[i].year_construct);
		fscanf(f, "%s ", &h[i].date);
		fscanf(f, "%s\n", &h[i].repair);
	}
	for (int i = 0; i < n; i++)
	{
		numb = i + 1;
		line2(1);
		output_struct_console(h, i);
		cout << "  "; line2(1);
		cout << endl << "       ";
		if (i != n - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
	}
	line1(150); cout << endl;
	fclose(f); // закриття файлу
	delete[] h; // звiльнення пам'яті
	return 0;
}
int output2()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb;
	fb = fopen("street.dat", "rb"); // відкриття файлу street.dat для зчитування
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, numb;
	shapka();
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		line2(1);
		output_struct_console(h, i);
		cout << "  "; line2(1);
		cout << endl << "       ";
		if (i != n - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
	}
	line1(150); cout << endl;
	fclose(fb); // закриття файлу
	delete[]h;
	return 0;
}

//меню 2
int record_start()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* f, * fb, * newf; // відкриття файлового потоку
	f = fopen("streets.txt", "r+"); // відкриття файлу 
	if (f == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int k;
	houses* h = new houses[100]; // оголошення динамічного масиву структур 
	houses* h1 = new houses[100]; // оголошення динамічного масиву структур 
	fread(&k, sizeof(int), 1, fb);
	for (int i = 0; i < k; i++) 
	{
		// зчитування даних з файлу
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
	}
	fclose(f); // закриття файлу
	fclose(fb);
	f = fopen("streets.txt", "w"); // відкриття файлу для запису
	if (f == NULL)
	{
		cout << " Текстовий файл не створено!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	fb = fopen("street.dat", "wb");
	if (fb == NULL)
	{
		cout << " Бінарний файл не створено!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n = kilkzap();
	int z=k + n;
	fprintf(f, "%i\n", z);
	fwrite(&z, sizeof(k), 1, fb);
	fseek(newf, 0, SEEK_END);
	fprintf(newf, " Додані нові дані на початок файлу:\n");
	cout << " Введіть дані для дозапису!" << endl;
	shapka_txt(newf, 0);
	for (int i = 0; i < n; i++) // цикл від 0 до n
	{
		while (1)
		{
			cout << " Назва вулиці: ";
			cin >> h1[i].street;
			if (valid_street(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Номер будинку: ";
			cin >> h1[i].number_house;
			if (valid_number(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Кількість жителів: ";
			cin >> h1[i].kol_meshk;
			if (valid_meshk(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Рік побудови будинку: ";
			cin >> h1[i].year_construct;
			if (valid_year(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Дата постановки на облік (стандартний формат): ";
			cin >> h1[i].date;
			if (valid_date(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Наявність ремонту за останні 20 років (так/ні): ";
			cin >> h1[i].repair;
			if (valid_repair(h1, i) == 1)
				break;
		}
		cout << endl;
		output_struct_txt(newf, h1, i);
		fprintf(f, "%s\t", h1[i].street);
		fwrite(&h1[i].street, sizeof(h1[i].street), 1, fb);
		fprintf(f, "%i\t", h1[i].number_house);
		fwrite(&h1[i].number_house, sizeof(h1[i].number_house), 1, fb);
		fprintf(f, "%i\t", h1[i].kol_meshk);
		fwrite(&h1[i].kol_meshk, sizeof(h1[i].kol_meshk), 1, fb);
		fprintf(f, "%i\t", h1[i].year_construct);
		fwrite(&h1[i].year_construct, sizeof(h1[i].year_construct), 1, fb);
		fprintf(f, "%s\t", h1[i].date);
		fwrite(&h1[i].date, sizeof(h1[i].date), 1, fb);
		fprintf(f, "%s\n", h1[i].repair);
		fwrite(&h1[i].repair, sizeof(h1[i].repair), 1, fb);
	}
	for (int i = 0; i < k; i++) 
	{
		// запис даних у файли
		fprintf(f, "%s\t", h[i].street);
		fwrite(&h[i].street, sizeof(h[i].street), 1, fb);
		fprintf(f, "%i\t", h[i].number_house);
		fwrite(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fprintf(f, "%i\t", h[i].kol_meshk);
		fwrite(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fprintf(f, "%i\t", h[i].year_construct);
		fwrite(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fprintf(f, "%s\t", h[i].date);
		fwrite(&h[i].date, sizeof(h[i].date), 1, fb);
		fprintf(f, "%s\n", h[i].repair);
		fwrite(&h[i].repair, sizeof(h[i].repair), 1, fb);
	}
	shapka_txt(newf, 1);
	cout <<endl<< " Записи успішно внесено в базу даних!"<<endl;
	fclose(f); // закриття файлу
	fclose(fb);
	fclose(newf);
	delete[]h1; // звільнення пам'яті
	delete[]h;
	cin.get();
	return 0;
}
int record_end()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* f, * fb, * newf; // відкриття файлового потоку
	f = fopen("streets.txt", "r+"); // відкриття файлу для зчитування
	if (f == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int k, numb;
	int n = kilkzap();
	houses* h1 = new houses[100]; // оголошення динамічного масиву структур 
	fscanf(f, "%i ", &k);
	fwrite(&k, sizeof(int), 1, fb);
	fseek(newf, 0, SEEK_END);
	fprintf(newf, " Додані нові дані в кінець файлу:\n");
	shapka_txt(newf, 0);
	cout << " Введіть дані для дозапису!" << endl;
	for (int i = 0; i < n; i++)
	{
		while (1)
		{
			cout << " Назва вулиці: ";
			cin >> h1[i].street;
			if (valid_street(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Номер будинку: ";
			cin >> h1[i].number_house;
			if (valid_number(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Кількість жителів: ";
			cin >> h1[i].kol_meshk;
			if (valid_meshk(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Рік побудови будинку: ";
			cin >> h1[i].year_construct;
			if (valid_year(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Дата постановки на облік (стандартний формат): ";
			cin >> h1[i].date;
			if (valid_date(h1, i) == 1)
				break;
		}
		while (1)
		{
			cout << " Наявність ремонту за останні 20 років (так/ні): ";
			cin >> h1[i].repair;
			if (valid_repair(h1, i) == 1)
				break;
		}
		fseek(fb, 0, SEEK_END);
		fseek(f, 0, SEEK_END);
		output_struct_txt(newf, h1, i);
		fprintf(f, "\n%s\t", h1[i].street);
		fwrite(&h1[i].street, sizeof(h1[i].street), 1, fb);
		fprintf(f, "%i\t", h1[i].number_house);
		fwrite(&h1[i].number_house, sizeof(h1[i].number_house), 1, fb);
		fprintf(f, "%i\t", h1[i].kol_meshk);
		fwrite(&h1[i].kol_meshk, sizeof(h1[i].kol_meshk), 1, fb);
		fprintf(f, "%i\t", h1[i].year_construct);
		fwrite(&h1[i].year_construct, sizeof(h1[i].year_construct), 1, fb);
		fprintf(f, "%s\t", h1[i].date);
		fwrite(&h1[i].date, sizeof(h1[i].date), 1, fb);
		fprintf(f, "%s\n", h1[i].repair);
		fwrite(&h1[i].repair, sizeof(h1[i].repair), 1, fb);
	}
	shapka_txt(newf, 1);
	fseek(fb, 0, SEEK_SET);
	fseek(f, 0, SEEK_SET);
	k += n;
	fprintf(f, "%i", k);
	fwrite(&k, sizeof(k), 1, fb);
	cout <<endl<< " Записи успішно внесено в базу даних!"<<endl;
	fclose(f); // закриття файлу
	fclose(fb);
	fclose(newf);
	delete[]h1; // звільнення пам'яті
	cin.get();
	return 0;
}
int edit()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * f;  // відкриття файлового потоку
	fb = fopen("street.dat", "r+b"); // відкриття файлу 
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, num, z;
	while (1)
	{
	fseek(fb, 0, SEEK_SET);
	fread(&n, sizeof(int), 1, fb);
	houses* h = new houses[n];
	output2();
	while (1)
	{
		cout << " Введіть номер запису, інформацію якого потрібно відредагувати: ";
		cin >> num;
		if (num > 0 && num <= n)
			break;
		else
			cout << " Некоректне введення! Введіть значення заново.." << endl;
	}
	num--;
	fseek(fb, num * 57, SEEK_CUR);
	cout << " Введіть дані для оновлення!" << endl;
	while (1)
	{
		cout << " Назва вулиці: ";
		cin >> h[num].street;
		if (valid_street(h, num) == 1)
			break;
	}
	while (1)
	{
		cout << " Номер будинку: ";
		cin >> h[num].number_house;
		if (valid_number(h, num) == 1)
			break;
	}
	while (1)
	{
		cout << " Кількість жителів: ";
		cin >> h[num].kol_meshk;
		if (valid_meshk(h, num) == 1)
			break;
	}
	while (1)
	{
		cout << " Рік побудови будинку: ";
		cin >> h[num].year_construct;
		if (valid_year(h, num) == 1)
			break;
	}
	while (1)
	{
		cout << " Дата постановки на облік (стандартний формат): ";
		cin >> h[num].date;
		if (valid_date(h, num) == 1)
			break;
	}
	while (1)
	{
		cout << " Наявність ремонту за останні 20 років (так/ні): ";
		cin >> h[num].repair;
		if (valid_repair(h, num) == 1)
			break;
	}
	fwrite(&h[num].street, sizeof(h[num].street), 1, fb);
	fwrite(&h[num].number_house, sizeof(h[num].number_house), 1, fb);
	fwrite(&h[num].kol_meshk, sizeof(h[num].kol_meshk), 1, fb);
	fwrite(&h[num].year_construct, sizeof(h[num].year_construct), 1, fb);
	fwrite(&h[num].date, sizeof(h[num].date), 1, fb);
	fwrite(&h[num].repair, sizeof(h[num].repair), 1, fb);
	delete[] h;
	cout << " Дані успішно змінені!" << endl;
	cout << " Якщо ви впевнені, що бажаєте продовжити, натисніть 1, а якщо ні - 0\nВибір >> ";
	cin >> z;
	if (z != '1')
		break;
	cin.get();
	}
	f = fopen("streets.txt", "w");
	if (f == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	fseek(fb, 0, SEEK_SET);
	fread(&n, sizeof(int), 1, fb);
	fprintf(f, "%i\n", n);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fprintf(f, "%s\t", h[i].street);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fprintf(f, "%i\t", h[i].number_house);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fprintf(f, "%i\t", h[i].kol_meshk);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fprintf(f, "%i\t", h[i].year_construct);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fprintf(f, "%s\t", h[i].date);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		fprintf(f, "%s\n", h[i].repair);
	}
	cin.get();
	fclose(fb);
	fclose(f);
	return 0;
}
void del()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	houses* h = new houses[100];
	output2();
	FILE* f, * fb; // відкриття файлового потоку
	f = fopen("streets.txt", "r+"); // відкриття файлу 
	if (f == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, num, k = 1, numb;
	fread(&n, sizeof(int), 1, fb);
	while (1)
	{
		cout << "\n\n Введіть номер запису, який потрібно видалити: ";
		cin >> num;
		if (num > 0 && num <= n)
			break;
	}
	fseek(fb, 4, SEEK_SET);
	fseek(f, 4, SEEK_SET);
	for (int i = 0; i <= n; i++)
	{
		if ((i + 1) != num)
		{
			fwrite(&h[i].street, sizeof(h[i].street), 1, fb);
			fwrite(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
			fwrite(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
			fwrite(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
			fwrite(&h[i].date, sizeof(h[i].date), 1, fb);
			fwrite(&h[i].repair, sizeof(h[i].repair), 1, fb);
			fprintf(f, "%s\t\t", h[i].street);
			fprintf(f, "%i\t\t", h[i].number_house);
			fprintf(f, "%i\t\t", h[i].kol_meshk);
			fprintf(f, "%i\t\t", h[i].year_construct);
			fprintf(f, "%s\t\t", h[i].date);
			fprintf(f, "%s\n", h[i].repair);
		}
	}
	cout << "\n Обраний запис успішно видалено!\n";
	n -= 1;
	fseek(fb, 0, SEEK_SET);
	fseek(f, 0, SEEK_SET);
	fwrite(&n, sizeof(int), 1, fb);
	fprintf(f, "%i", n);
	delete[] h;
	fclose(f);
	fclose(fb);
	cin.get();
}

//меню 3
int more_kol_meshk()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb, sum=0;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		sum += h[i].kol_meshk;
	}
	int ser = sum / n;
	fseek(newf, 0, SEEK_END);
	fprintf(newf, "\n Середня кількість жителів у аварійних будинках : %i", ser);
	shapka();
	fprintf(newf, "\n Будинки, в яких кількість жителів перевищує середню:\n");
	shapka_txt(newf, 0);
	for(int i=0; i<n; i++)
	{
			if (h[i].kol_meshk>ser)
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
	}
	shapka_txt(newf, 1);
	cout << " Середня кількість жителів у аварійних будинках: " << ser << endl;
	line1(150); cout << endl;
	delete[] h;
	fclose(fb);
	fclose(newf);
	return 0;
}
int smaller_kol_meshk()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb, sum = 0;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		sum += h[i].kol_meshk;
	}
	int ser = sum / n;
	fseek(newf, 0, SEEK_END);
	fprintf(newf, "\n Середня кількість жителів у аварійних будинках : %i", ser);
	shapka();
	fprintf(newf, "\n Будинки, в яких кількість жителів перевищує середню:\n");
	shapka_txt(newf, 0);
	for (int i = 0; i < n; i++)
	{
		if (h[i].kol_meshk < ser)
		{
			line2(1);
			output_struct_txt(newf, h, i);
			output_struct_console(h, i);
			cout << "  "; line2(1);
			cout << endl << "       ";
			if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
		}
	}
	shapka_txt(newf, 1);
	line1(150); cout << endl;
	cout << "\n Середня кількість жителів у аварійних будинках : " << ser << endl;
	delete[] h;
	fclose(fb);
	fclose(newf);
	return 0;
}
int more_houses_100year()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	time_t t;
	time(&t);
	int year = localtime(&t)->tm_year+1900, years=year+10; //поточний рік
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, kol = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if (years-h[i].year_construct >= 100)
			kol++;
	}
	if (kol == 0)
		cout << " У базі немає будинків, які через 10 років святкуватимуть ювілей!" << endl;
	else
	{
		fseek(newf, 0, SEEK_END);
		shapka();
		fprintf(newf, "\n Будинки, які через 10 років святкуватимуть ювілей:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if (years - h[i].year_construct >= 100)
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != kol - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		line1(150); cout << endl;
		shapka_txt(newf, 1);
	}
	delete[] h;
	fclose(fb);
	fclose(newf);
	return 0;
}
int oblik_current_year()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	time_t t;
	time(&t);
	int year = localtime(&t)->tm_year + 1900;
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) == year))
			k++;
	}
	if (k == 0)
		cout << " У базі немає будинків, поставлених на облік поточного року!" << endl;
	else
	{
		shapka();
		fprintf(newf, "\n Будинки, поставлені на облік поточного року:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) == year))
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}
int oblik_year2000()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) >= 2000))
			k++;
	}
	if (k == 0)
		cout << " У базі немає будинків, поставлених на облік протягом 2000-х років!" << endl;
	else
	{
		shapka();
		fprintf(newf, "\n Будинки, поставлені на облік протягом 2000-х років:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) >= 2000))
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}
int oblik_year_recently()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) >= 2010))
			k++;
	}
	if (k == 0)
		cout << " У базі немає будинків, недавно поставлених на облік!" << endl;
	else
	{
		fseek(newf, 0, SEEK_END);
		shapka();
		fprintf(newf, "\n Будинки, недавно поставлені на облік:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) >= 2010))
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}
int year_created90()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if (h[i].year_construct>=1990 && h[i].year_construct<2000)
			k++;
	}
	if (k == 0)
		cout << " У базі немає будинків, побудованих протягом 90-х років!" << endl;
	else
	{
		shapka();
		fprintf(newf, "\n Будинки, побудовані протягом 90-х років:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if (h[i].year_construct >= 1990 && h[i].year_construct < 2000)
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}
int year_created2000()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if (h[i].year_construct >= 2000)
			k++;
	}
	if (k == 0)
		cout << " У базі немає будинків, побудованих протягом 2000-х років!" << endl;
	else
	{
		fseek(newf, 0, SEEK_END);
		shapka();
		fprintf(newf, "\n Будинки, побудовані протягом 2000-х років:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if (h[i].year_construct >= 2000)
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}
int year_created_1920_1950()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if (h[i].year_construct >= 1990 && h[i].year_construct < 2000)
			k++;
	}
	if (k == 0)
		cout << " У базі немає будинків, побудованих протягом 1920-1950-х років!" << endl;
	else
	{
		shapka();
		fprintf(newf, "\n Будинки, побудовані протягом 1920-1950-х років:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if (h[i].year_construct >= 1920 && h[i].year_construct < 1960)
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}
int repair_yes()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if (strcmp(h[i].repair, "так") == 0 || strcmp(h[i].repair, "Так") == 0 || strcmp(h[i].repair, "yes") == 0 || strcmp(h[i].repair, "Yes") == 0)
			k++;
	}
	if (k == 0)
		cout << " У базі немає будинків, в яких здійснювався ремонт протягом останніх 20 років!" << endl;
	else
	{
		shapka();
		fprintf(newf, "\n Будинки, в яких здійснювався ремонт протягом останніх 20 років:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if (strcmp(h[i].repair, "так") == 0 || strcmp(h[i].repair, "Так") == 0 || strcmp(h[i].repair, "yes") == 0 || strcmp(h[i].repair, "Yes") == 0)
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}
int with_repair()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if ((strcmp(h[i].repair, "так") == 0 || strcmp(h[i].repair, "Так") == 0 || strcmp(h[i].repair, "yes") == 0 || strcmp(h[i].repair, "Yes") == 0)&& h[i].year_construct>=1990 && (((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) >= 2010)
			k++;
	}
	if (k == 0)
		cout << " У базі немає будинків, які взагалі не потребують ремонту!" << endl;
	else
	{
		fseek(newf, 0, SEEK_END);
		shapka();
		fprintf(newf, "\n Будинки, що взагалі не потребують ремонту:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if ((strcmp(h[i].repair, "так") == 0 || strcmp(h[i].repair, "Так") == 0 || strcmp(h[i].repair, "yes") == 0 || strcmp(h[i].repair, "Yes") == 0) && h[i].year_construct >= 1990 && (((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) >= 2010)
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}
int limit_kol_meshk10(int x)
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb, sum = 0;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
	}
	fseek(newf, 0, SEEK_END);
	shapka();
	if (x == 0)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (h[i].kol_meshk > h[j].kol_meshk) {
					swap(h[i], h[j]);
				}
			}
		}
		fprintf(newf, "\n 10 будинків з найбільшою кількістю жителів:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < 10; i++)
		{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != 9) { line2(1); line3(150); line2(1); cout << endl << "       "; }
		}
	}
	else
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (h[i].kol_meshk < h[j].kol_meshk) {
					swap(h[i], h[j]);
				}
			}
		}
		fprintf(newf, "\n 10 будинків з найменшою кількістю жителів:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < 10; i++)
		{
			line2(1);
			output_struct_txt(newf, h, i);
			output_struct_console(h, i);
			cout << "  "; line2(1);
			cout << endl << "       ";
			if (i != 9) { line2(1); line3(150); line2(1); cout << endl << "       "; }
		}
	}
	shapka_txt(newf, 1);
	line1(150); cout << endl;
	delete[] h;
	fclose(fb);
	fclose(newf);
	return 0;
}
int kol_oblik_current()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	time_t t;
	time(&t);
	int year = localtime(&t)->tm_year + 1900; //поточний рік
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << " Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << " Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, kol = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) == year))
			kol++;
	}
	if (kol == 0)
		cout << " У базі немає будинків, поставлених на облік поточного року!" << endl;
	else
	{
		fseek(newf, 0, SEEK_END);
		shapka();
		fprintf(newf, "\n Кількість будинків, поставлених на облік поточного року: %i.", kol);
		fprintf(newf, "\n Будинки, поставлені на облік поточного року:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) == year))
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != kol - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		line1(150); cout << endl;
		shapka_txt(newf, 1);
		cout << "\n Кількість будинків, поставлених на облік поточного року: "<< kol<<"."<<endl;
	}
	delete[] h;
	fclose(fb);
	fclose(newf);
	return 0;
}

//меню 4
int sort_street(int x)
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << "Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
	}
	shapka();
	if (x == 0)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (int res = strcmp(h[i].street, h[j].street) < 0) {
					swap(h[i], h[j]);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (int res = strcmp(h[i].street, h[j].street) > 0) {
					swap(h[i], h[j]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		line2(1);
		output_struct_console(h, i);
		cout << "  "; line2(1);
		cout << endl << "       ";
		if (i != n - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
	}
	line1(150); cout << endl;
	delete[] h;
	fclose(fb);
	return 0;
}
int sort_kol_meshk(int x)
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << "Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
	}
	shapka();
	if (x == 0)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (h[i].kol_meshk < h[j].kol_meshk) {
					swap(h[i], h[j]);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (h[i].kol_meshk > h[j].kol_meshk) {
					swap(h[i], h[j]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		line2(1);
		output_struct_console(h, i);
		cout << "  "; line2(1);
		cout << endl << "       ";
		if (i != n - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
	}
	line1(150); cout << endl;
	delete[] h;
	fclose(fb);
	return 0;
}
int sort_year_constructed(int x)
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << "Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
	}
	shapka();
	if (x == 0)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (h[i].year_construct < h[j].year_construct) {
					swap(h[i], h[j]);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (h[i].year_construct > h[j].year_construct) {
					swap(h[i], h[j]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		line2(1);
		output_struct_console(h, i);
		cout << "  "; line2(1);
		cout << endl << "       ";
		if (i != n - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
	}
	line1(150); cout << endl;
	delete[] h;
	fclose(fb);
	return 0;
}
int sort_date(int x)
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << "Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
	}
	shapka();
	if (x == 0)
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - i - 1; j++)
				if (((((h[j].date[0] - '0') * 10) + (h[j].date[1] - '0')) + ((((h[j].date[3] - '0') * 10) + (h[j].date[4] - '0')) * 30) + ((((h[j].date[6] - '0') * 1000) + ((h[j].date[7] - '0') * 100) + ((h[j].date[8] - '0') * 10) + (h[j].date[9] - '0')) * 365)) > ((((h[j + 1].date[0] - '0') * 10) + (h[j + 1].date[1] - '0')) + ((((h[j + 1].date[3] - '0') * 10) + (h[j + 1].date[4] - '0')) * 30) + ((((h[j + 1].date[6] - '0') * 1000) + ((h[j + 1].date[7] - '0') * 100) + ((h[j + 1].date[8] - '0') * 10) + (h[j + 1].date[9] - '0')) * 365)))
				{
					swap(h[j + 1], h[j]);
				}
	}
	else
	{
		for (int i = 0; i < n - 1; i++)
			for (int j = 0; j < n - i - 1; j++)
				if (((((h[j].date[0] - '0') * 10) + (h[j].date[1] - '0')) + ((((h[j].date[3] - '0') * 10) + (h[j].date[4] - '0')) * 30) + ((((h[j].date[6] - '0') * 1000) + ((h[j].date[7] - '0') * 100) + ((h[j].date[8] - '0') * 10) + (h[j].date[9] - '0')) * 365)) < ((((h[j + 1].date[0] - '0') * 10) + (h[j + 1].date[1] - '0')) + ((((h[j + 1].date[3] - '0') * 10) + (h[j + 1].date[4] - '0')) * 30) + ((((h[j + 1].date[6] - '0') * 1000) + ((h[j + 1].date[7] - '0') * 100) + ((h[j + 1].date[8] - '0') * 10) + (h[j + 1].date[9] - '0')) * 365)))
				{
					swap(h[j + 1], h[j]);
				}
	}
	for (int i = 0; i < n; i++)
	{
		line2(1);
		output_struct_console(h, i);
		cout << "  "; line2(1);
		cout << endl << "       ";
		if (i != n - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
	}
	line1(150); cout << endl;
	delete[] h;
	fclose(fb);
	return 0;
}
int sort_repair(int x)
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << "Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
	}
	shapka();
	if (x == 0)
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (int res = strcmp(h[i].repair, h[j].repair) > 0) {
					swap(h[i], h[j]);
				}
			}
		}
	}
	else
	{
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (int res = strcmp(h[i].repair, h[j].repair) < 0) {
					swap(h[i], h[j]);
				}
			}
		}
	}
	for (int i = 0; i < n; i++)
	{
		line2(1);
		output_struct_console(h, i);
		cout << "  "; line2(1);
		cout << endl << "       ";
		if (i != n - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
	}
	line1(150); cout << endl;
	delete[] h;
	fclose(fb);
	return 0;
}

//меню 5
void del_street()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* f, * fb; // відкриття файлового потоку
	f = fopen("streets.txt", "r+"); // відкриття файлу для зчитування
	if (f == NULL)
	{
		cout << "Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << "Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, numb, kol = 0;
	fseek(fb, 0, SEEK_SET);
	fseek(f, 0, SEEK_SET);
	fread(&n, sizeof(int), 1, fb);
	houses* h = new houses[n];
	shapka();
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if (strcmp(h[i].street, "Пішонівська") == 0 || strcmp(h[i].street, "пішонівська") == 0)
		{
			kol++;
			line2(1);
			output_struct_console(h, i);
			cout << "  "; line2(1);
			cout << endl << "       ";
			if (i != kol - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
		}
	}
	line1(150); cout << endl;
	if (kol / 10.0 >= 1)
		cout << " Всього записів: " << kol << ". " << endl;
	else
		cout << " Всього записів:  " << kol << ". " << endl;
	fclose(f);
	fclose(fb);
	f = fopen("streets.txt", "w"); // відкриття файлу для запису
	if (f == NULL)
	{
		cout << "Текстовий файл не створено!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	fb = fopen("street.dat", "wb");
	if (fb == NULL)
	{
		cout << "Бінарний файл не створено!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int x, k=0;
	cout << "\n Ви справді бажаєте видалити наведені записи?" << endl <<" Якщо так, натисніть 1, а ні - 0."<<endl<< " Відповідь >> ";
	cin >> x;
	switch (x)
	{
	case 1:
	{
		fseek(fb, 0, SEEK_SET);
		fseek(f, 0, SEEK_SET);
		k=n - kol;
		fwrite(&k, sizeof(int), 1, fb);
		fprintf(f, "%i\n", k);
		for (int i = 0; i < n; i++)
		{
			if ((strcmp(h[i].street, "Пішонівська") == 0) || (strcmp(h[i].street, "пішонівська") == 0))
			{
				continue;
			}
			fprintf(f, "%s\t", h[i].street);
			fwrite(&h[i].street, sizeof(h[i].street), 1, fb);
			fprintf(f, "%i\t", h[i].number_house);
			fwrite(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
			fprintf(f, "%i\t", h[i].kol_meshk);
			fwrite(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
			fprintf(f, "%i\t", h[i].year_construct);
			fwrite(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
			fprintf(f, "%s\t", h[i].date);
			fwrite(&h[i].date, sizeof(h[i].date), 1, fb);
			fprintf(f, "%s\n", h[i].repair);
			fwrite(&h[i].repair, sizeof(h[i].repair), 1, fb);
		}
		cout << "\n Записи, що стосуються вулиці Пішонівської, успішно видалено!\n\n";
		break;
	}
	default:
		cout << " За вашим бажанням записи не видалені.." << endl;
	}
	
	delete[] h;
	fclose(f);
	fclose(fb);
	cin.get();
}
int oblik_year_10ago()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << "Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << "Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) <= 2010))
			k++;
	}
	if (k == 0)
		cout << "У базі немає будинків, поставлених на облік понад 10 років тому!" << endl;
	else
	{
		shapka();
		fprintf(newf, "\nБудинки, поставлені на облік понад 10 років тому:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if ((h[i].date[2] == '.') && (h[i].date[5] == '.') && ((((h[i].date[0] - '0') * 10) + (h[i].date[1] - '0')) <= 30) && ((((h[i].date[3] - '0') * 10) + (h[i].date[4] - '0')) <= 12) && ((((h[i].date[6] - '0') * 1000) + ((h[i].date[7] - '0') * 100) + ((h[i].date[8] - '0') * 10) + ((h[i].date[9] - '0'))) <= 2010))
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}
int repair()
{
	system("cls"); // очищення екрану
	system("color 70"); // встановлення кольору за замовчуванням
	FILE* fb, * newf; // відкриття файлового потоку
	fb = fopen("street.dat", "r+b");
	if (fb == NULL)
	{
		cout << "Бінарний файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	newf = fopen("str_operations.txt", "r+");
	if (newf == NULL)
	{
		cout << "Текстовий файл не відкрито!" << endl;
		cin.get(); // затримка екрану
		exit(1);
	}
	int n, k = 0, numb;
	fread(&n, sizeof(n), 1, fb);
	houses* h = new houses[n];
	for (int i = 0; i < n; i++)
	{
		fread(&h[i].street, sizeof(h[i].street), 1, fb);
		fread(&h[i].number_house, sizeof(h[i].number_house), 1, fb);
		fread(&h[i].kol_meshk, sizeof(h[i].kol_meshk), 1, fb);
		fread(&h[i].year_construct, sizeof(h[i].year_construct), 1, fb);
		fread(&h[i].date, sizeof(h[i].date), 1, fb);
		fread(&h[i].repair, sizeof(h[i].repair), 1, fb);
		if (h[i].kol_meshk > 50 && h[i].year_construct < 1941 && (strcmp(h[i].repair, "Ні") == 0 || strcmp(h[i].repair, "ні") == 0 || strcmp(h[i].repair, "no") == 0 || strcmp(h[i].repair, "No") == 0))
			k++;
	}
	if (k == 0)
		cout << "У базі немає будинків, що перебувають в аварійному стані та потребують негайного ремонту!" << endl;
	else
	{
		shapka();
		fprintf(newf, "\nБудинки, що перебувають в аварійному стані та потребують негайного ремонту:\n");
		shapka_txt(newf, 0);
		for (int i = 0; i < n; i++)
		{
			if (h[i].kol_meshk > 50 && h[i].year_construct < 1941 && (strcmp(h[i].repair, "Ні") == 0 || strcmp(h[i].repair, "ні") == 0 || strcmp(h[i].repair, "no") == 0 || strcmp(h[i].repair, "No") == 0))
			{
				line2(1);
				output_struct_txt(newf, h, i);
				output_struct_console(h, i);
				cout << "  "; line2(1);
				cout << endl << "       ";
				if (i != k - 1) { line2(1); line3(150); line2(1); cout << endl << "       "; }
			}
		}
		shapka_txt(newf, 1);
		line1(150); cout << endl;
		delete[] h;
		fclose(fb);
		fclose(newf);
		return 0;
	}
}

//додаткові функції
int kilkzap()
{
	int n;
	while (1)
	{
		cout << " Введіть кількість записів, які потрібно додати у файл: ";
		cin >> n; // введення кількості записів
		if (valid_n(n) == 1)
			break;
	}
	cout << endl;
	return n;
}
void shapka()
{
	cout << "       ";
	line(150);
	cout << endl;
	cout << "       ";
	line2(1);
	cout << " № запису |	  Назва вулиці        |  Номер будинку  | Кількість мешканців | Рік побудови | Дата постановки на облік | Ремонт за останні 20 років  ";
	line2(1);
	cout << endl << "       ";
	line2(1);
	linee(150);
	line2(1);
	cout << endl << "       ";
}
void shapka_txt(FILE* newf, int n)
{
	if (n == 0)
	{
		fprintf(newf, "/———————————————————————~—————————————————~—————————————————————~——————————————~——————————————————————————~———————————————————————————\\\n");
		fprintf(newf, "|    Назва вулиці       |  Номер будинку  | Кількість мешканців | Рік побудови | Дата постановки на облік | Ремонт за останні 20 років|\n");
		fprintf(newf, "+———————————————————————+—————————————————+-————————————————————+——————————————+——————————————————————————+———————————————————————————+\n");
	}
	else
		fprintf(newf, "\\———————————————————————^—————————————————^—————————————————————^——————————————^——————————————————————————^———————————————————————————/\n");
}
void output_struct_txt(FILE* newf, houses h[], int i)
{
	fprintf(newf, "|%-23s|", h[i].street);
	fprintf(newf, "%17i|", h[i].number_house);
	fprintf(newf, "%21i|", h[i].kol_meshk);
	fprintf(newf, "%14i|", h[i].year_construct);
	fprintf(newf, "%26s|", h[i].date);
	fprintf(newf, " %-26s|\n", h[i].repair);
}
void output_struct_console(houses h[], int i)
{
	int numb = i + 1;
	cout << "  " << setw(8) << right << numb << "|";
	cout << " " << setw(26) << left << h[i].street << "|";
	cout << setw(16) << right << h[i].number_house << " |";
	cout << setw(20) << right << h[i].kol_meshk << " |";
	cout << " " << setw(13) << right << h[i].year_construct << "|";
	cout << " " << setw(25) << right << h[i].date << "|";
	cout << " " << setw(26) << left << h[i].repair;
}
void fullConsole()
{
	system("mode con COLS=700");
	ShowWindow(GetConsoleWindow(), SW_MAXIMIZE);
	SendMessage(GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);
}