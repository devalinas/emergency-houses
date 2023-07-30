#include <iostream>
#include "Header.h"
HANDLE hConsole, hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);

int m_pos = 0, max_pos = 6;        // позиції меню 1
int m_pos2 = 0, max_pos2 = 3;      // позиції меню 2
int m_pos3 = 0, max_pos3 = 4;      // позиції меню 3
int m_pos4 = 0, max_pos4 = 4;      // позиції меню 4
int m_pos5 = 0, max_pos5 = 6;      // позиції меню 5
int m_pos31 = 0, max_pos31 = 3;    // позиції підменю 3 1
int m_pos41 = 0, max_pos41 = 6;    // позиції підменю 4 1
int m_pos42 = 0, max_pos42 = 7;    // позиції підменю 4 2
int m_pos43 = 0, max_pos43 = 4;    // позиції підменю 4 3
int m_pos51 = 0, max_pos51 = 2;    // позиції підменю 5 1
int m_pos52 = 0, max_pos52 = 2;    // позиції підменю 5 2
int m_pos53 = 0, max_pos53 = 2;    // позиції підменю 5 3
int m_pos54 = 0, max_pos54 = 2;    // позиції підменю 5 4
int m_pos55 = 0, max_pos55 = 2;    // позиції підменю 5 5
int m_pos6 = 0, max_pos6 = 5;    // позиції підменю 6


enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

void SetColor(int text, int background) // колір
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}

void menu();
void menu2();
void menu3();
void menu31();
void menu4();
void menu41();
void menu42();
void menu43();
void menu5();
void menu51();
void menu52();
void menu53();
void menu54();
void menu55();
void menu6();
void menuK();
void menuK2();
void menuK3();
void menuK31();
void menuK4();
void menuK41();
void menuK42();
void menuK43();
void menuK5();
void menuK51();
void menuK52();
void menuK53();
void menuK54();
void menuK55();
void menuK6();


void go(int b) // Якщо натиснули Enter
{
	int v = 0;
	if (b == 0) { menu2(); v = 1; _getch(); }
	if (b == 1) { menu3(); v = 1; _getch(); }
	if (b == 2) { menu4(); v = 1; _getch(); }
	if (b == 3) { menu5(); v = 1; _getch(); }
	if (b == 4) { menu6(); v = 1; _getch(); }
	if (b == 5) exit(0);
	if (v == 1) menu();
}

void go2(int b)
{
	int v = 0;
	if (b == 0) { output1(); v = 1; _getch(); }
	if (b == 1) { output2(); v = 1; _getch(); }
	if (b == 2)  menu(); 
	if (v == 1)  menu(); 
}

void go3(int b)
{
	int v = 0;
	if (b == 0) { menu31();  v = 1; _getch(); }
	if (b == 1) { edit();  v = 1; _getch(); }
	if (b == 2) { del();  v = 1; _getch(); }
	if (b == 3) menu(); 
	if (v == 1) menu(); 
}

void go31(int b)
{
	int v = 0;
	if (b == 0) { record_start();  v = 1; _getch(); }
	if (b == 1) { record_end();  v = 1; _getch(); }
	if (b == 2) menu3(); 
	if (v == 1) menu(); 
}

void go4(int b)
{
	int v = 0;
	if (b == 0) { menu41();  v = 1; _getch(); }
	if (b == 1) { menu42();  v = 1; _getch(); }
	if (b == 2) { menu43();  v = 1; _getch(); }
	if (b == 3) menu(); 
	if (v == 1) menu(); 
}

void go41(int b)
{
	int v = 0;
	if (b == 0) { oblik_current_year();  v = 1; _getch(); }
	if (b == 1) { oblik_year_10ago();   v = 1; _getch(); }
	if (b == 2) { oblik_year2000();  v = 1; _getch(); }
	if (b == 3) { year_created90();  v = 1; _getch(); }
	if (b == 4) { year_created_1920_1950();  v = 1; _getch(); }
	if (b == 5) { menu4();  v = 1; _getch(); }
	if (v == 1)  menu(); 
}

void go42(int b)
{
	int v = 0;
	if (b == 0) { more_kol_meshk();  v = 1; _getch(); }
	if (b == 1) { smaller_kol_meshk(); v = 1; _getch(); }
	if (b == 2) { limit_kol_meshk10(0);  v = 1; _getch(); }
	if (b == 3) { limit_kol_meshk10(1);  v = 1; _getch(); }
	if (b == 4) { kol_oblik_current();  v = 1; _getch(); }
	if (b == 5) { more_houses_100year();  v = 1; _getch(); }
	if (b == 6) { menu4();  v = 1; _getch(); }
	if (v == 1)  menu();
}

void go43(int b)
{
	int v = 0;
	if (b == 0) { with_repair();  v = 1; _getch(); }
	if (b == 1) { oblik_year_recently();   v = 1; _getch(); }
	if (b == 2) { year_created2000();  v = 1; _getch(); }
	if (b == 3) { menu4();  v = 1; _getch(); }
	if (v == 1)  menu();
}

void go5(int b)
{
	int v = 0;
	if (b == 0) { menu51();  v = 1; _getch(); }
	if (b == 1) { menu52();  v = 1; _getch(); }
	if (b == 2) { menu53();  v = 1; _getch(); }
	if (b == 3) { menu54();  v = 1; _getch(); }
	if (b == 4) { menu55();  v = 1; _getch(); }
	if (b == 5) menu();
	if (v == 1) menu(); 
}

void go51(int b)
{
	int v = 0;
	if (b == 0) { sort_street(0);  v = 1; _getch(); }
	if (b == 1) { sort_street(1);  v = 1; _getch(); }
	if (v == 1)  menu(); 
}

void go52(int b)
{
	int v = 0;
	if (b == 0) { sort_date(0);  v = 1; _getch(); }
	if (b == 1) { sort_date(1);  v = 1; _getch(); }
	if (v == 1)  menu(); 
}

void go53(int b)
{
	int v = 0;
	if (b == 0) { sort_year_constructed(0);  v = 1; _getch(); }
	if (b == 1) { sort_year_constructed(1);  v = 1; _getch(); }
	if (v == 1) menu(); 
}

void go54(int b)
{
	int v = 0;
	if (b == 0) { sort_kol_meshk(0);  v = 1; _getch(); }
	if (b == 1) { sort_kol_meshk(1);  v = 1; _getch(); }
	if (v == 1) menu(); 
}

void go55(int b)
{
	int v = 0;
	if (b == 0) { sort_repair(0);  v = 1; _getch(); }
	if (b == 1) { sort_repair(1);  v = 1; _getch(); }
	if (v == 1) menu(); 
}

void go6(int b)
{
	int v = 0;
	if (b == 0) { sort_year_constructed(0);  v = 1; _getch(); }
	if (b == 1) { repair();  v = 1; _getch(); }
	if (b == 2) { oblik_year_10ago();  v = 1; _getch(); }
	if (b == 3) { del_street();  v = 1; _getch(); }
	if (b == 4) { menu();  v = 1; _getch(); }
	if (v == 1)  menu(); 
}

void cls(short x, short y, int n)
{
	gotoxy(x, y);
	for (int i = 0; i < n; i++)
		cout << " ";
}

void choice() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos + 1 < max_pos) ++m_pos;
		menuK();
		break;
	case 72: // вгору
		if (m_pos - 1 >= 0) --m_pos;
		menuK();
		break;
	case 13: // Enter
		go(m_pos);
		break;
	case 27: // Esc
		exit(0);
	default:
		goto l;
	}
}

void choice2() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos2 + 1 < max_pos2) ++m_pos2;
		menuK2();
		break;
	case 72: // вгору
		if (m_pos2 - 1 >= 0) --m_pos2;
		menuK2();
		break;
	case 13: // Enter
		go2(m_pos2);
		break;
	case 27: // Esc
		menu();
		break;
	default:
		goto l;
	}
}

void choice3() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos3 + 1 < max_pos3) ++m_pos3;
		menuK3();
		break;
	case 72: // вгору
		if (m_pos3 - 1 >= 0) --m_pos3;
		menuK3();
		break;
	case 13: // Enter
		go3(m_pos3);
		break;
	case 27: // Esc
		menu();
		break;
	default:
		goto l;
	}
}

void choice31() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos31 + 1 < max_pos31) ++m_pos31;
		menuK31();
		break;
	case 72: // вгору
		if (m_pos31 - 1 >= 0) --m_pos31;
		menuK31();
		break;
	case 13: // Enter
		go31(m_pos31);
		break;
	case 27: // Esc
		menu3();
		break;
	default:
		goto l;
	}
}

void choice4() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos4 + 1 < max_pos4) ++m_pos4;
		menuK4();
		break;
	case 72: // вгору
		if (m_pos4 - 1 >= 0) --m_pos4;
		menuK4();
		break;
	case 13: // Enter
		go4(m_pos4);
		break;
	case 27: // Esc
		menu();
		break;
	default:
		goto l;
	}
}

void choice41() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos41 + 1 < max_pos41) ++m_pos41;
		menuK41();
		break;
	case 72: // вгору
		if (m_pos41 - 1 >= 0) --m_pos41;
		menuK41();
		break;
	case 13: // Enter
		go41(m_pos41);
		break;
	case 27: // Esc
		menu4();
		break;
	default:
		goto l;
	}
}

void choice42() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos42 + 1 < max_pos42) ++m_pos42;
		menuK42();
		break;
	case 72: // вгору
		if (m_pos42 - 1 >= 0) --m_pos42;
		menuK42();
		break;
	case 13: // Enter
		go42(m_pos42);
		break;
	case 27: // Esc
		menu4();
		break;
	default:
		goto l;
	}
}

void choice43() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos43 + 1 < max_pos43) ++m_pos43;
		menuK43();
		break;
	case 72: // вгору
		if (m_pos43 - 1 >= 0) --m_pos43;
		menuK43();
		break;
	case 13: // Enter
		go43(m_pos43);
		break;
	case 27: // Esc
		menu4();
		break;
	default:
		goto l;
	}
}

void choice5() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos5 + 1 < max_pos5) ++m_pos5;
		menuK5();
		break;
	case 72: // вгору
		if (m_pos5 - 1 >= 0) --m_pos5;
		menuK5();
		break;
	case 13: // Enter
		go5(m_pos5);
		break;
	case 27: // Esc
		menu();
		break;
	default:
		goto l;
	}
}

void choice51() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos51 + 1 < max_pos51) ++m_pos51;
		menuK51();
		break;
	case 72: // вгору
		if (m_pos51 - 1 >= 0) --m_pos51;
		menuK51();
		break;
	case 13: // Enter
		go51(m_pos51);
		break;
	case 27: // Esc
		menu5();
		break;
	default:
		goto l;
	}
}

void choice52() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos52 + 1 < max_pos52) ++m_pos52;
		menuK52();
		break;
	case 72: // вгору
		if (m_pos52 - 1 >= 0) --m_pos52;
		menuK52();
		break;
	case 13: // Enter
		go52(m_pos52);
		break;
	case 27: // Esc
		menu5();
		break;
	default:
		goto l;
	}
}

void choice53() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos53 + 1 < max_pos53) ++m_pos53;
		menuK53();
		break;
	case 72: // вгору
		if (m_pos53 - 1 >= 0) --m_pos53;
		menuK53();
		break;
	case 13: // Enter
		go53(m_pos53);
		break;
	case 27: // Esc
		menu5();
		break;
	default:
		goto l;
	}
}

void choice54() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos54 + 1 < max_pos54) ++m_pos54;
		menuK54();
		break;
	case 72: // вгору
		if (m_pos54 - 1 >= 0) --m_pos54;
		menuK54();
		break;
	case 13: // Enter
		go54(m_pos54);
		break;
	case 27: // Esc
		menu5();
		break;
	default:
		goto l;
	}
}

void choice55() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos55 + 1 < max_pos55) ++m_pos55;
		menuK55();
		break;
	case 72: // вгору
		if (m_pos55 - 1 >= 0) --m_pos55;
		menuK55();
		break;
	case 13: // Enter
		go55(m_pos55);
		break;
	case 27: // Esc
		menu5();
		break;
	default:
		goto l;
	}
}

void choice6() // функція вибору
{
l:
	int ch = _getch(); // зчитуємо значення натиснутої клавіші
	switch (ch)
	{
	case 80: // вниз
		if (m_pos6 + 1 < max_pos6) ++m_pos6;
		menuK6();
		break;
	case 72: // вгору
		if (m_pos6 - 1 >= 0) --m_pos6;
		menuK6();
		break;
	case 13: // Enter
		go6(m_pos6);
		break;
	case 27: // Esc
		menu();
		break;
	default:
		goto l;
	}
}

void menuK()
{
	
	SetColor(14, 5);
	if (m_pos == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); cls(51, 19, 2); gotoxy(0, 0); }
	if (m_pos == 3) { gotoxy(51, 19); cout << "->"; cls(51, 17, 2); cls(51, 21, 2); gotoxy(0, 0); }
	if (m_pos == 4) { gotoxy(51, 21); cout << "->"; cls(51, 19, 2); cls(51, 23, 2); gotoxy(0, 0); }
	if (m_pos == 5) { gotoxy(51, 23); cout << "->"; cls(51, 21, 2); gotoxy(0, 0); }
	choice();
	SetColor(15, 5);
}

void menuK2()
{
	SetColor(14, 5);
	if (m_pos2 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos2 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos2 == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	choice2();
	SetColor(15, 5);
}

void menuK3()
{
	SetColor(14, 5);
	if (m_pos3 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos3 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos3 == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); cls(51, 19, 2); gotoxy(0, 0); }
	if (m_pos3 == 3) { gotoxy(51, 19); cout << "->"; cls(51, 17, 2); gotoxy(0, 0); }
	choice3();
	SetColor(15, 5);
}

void menuK31()
{
	SetColor(14, 5);
	if (m_pos31 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos31 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos31 == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	choice31();
	SetColor(15, 5);
}

void menuK4()
{
	SetColor(14, 5);
	if (m_pos4 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos4 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos4 == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); cls(51, 19, 2); gotoxy(0, 0); }
	if (m_pos4 == 3) { gotoxy(51, 19); cout << "->"; cls(51, 17, 2); gotoxy(0, 0); }
	choice4();
	SetColor(15, 5);
}

void menuK41()
{
	SetColor(14, 5);
	if (m_pos41 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos41 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos41 == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); cls(51, 19, 2); gotoxy(0, 0); }
	if (m_pos41 == 3) { gotoxy(51, 19); cout << "->"; cls(51, 17, 2); cls(51, 21, 2); gotoxy(0, 0); }
	if (m_pos41 == 4) { gotoxy(51, 21); cout << "->"; cls(51, 19, 2); cls(51, 23, 2); gotoxy(0, 0); }
	if (m_pos41 == 5) { gotoxy(51, 23); cout << "->"; cls(51, 21, 2); gotoxy(0, 0); }
	choice41();
	SetColor(15, 5);
}

void menuK42()
{
	SetColor(14, 5);
	if (m_pos42 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos42 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos42 == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); cls(51, 19, 2); gotoxy(0, 0); }
	if (m_pos42 == 3) { gotoxy(51, 19); cout << "->"; cls(51, 17, 2); cls(51, 21, 2); gotoxy(0, 0); }
	if (m_pos42 == 4) { gotoxy(51, 21); cout << "->"; cls(51, 19, 2); cls(51, 23, 2); gotoxy(0, 0); }
	if (m_pos42 == 5) { gotoxy(51, 23); cout << "->"; cls(51, 21, 2); cls(51, 25, 2); gotoxy(0, 0); }
	if (m_pos42 == 6) { gotoxy(51, 25); cout << "->"; cls(51, 23, 2); gotoxy(0, 0); }
	choice42();
	SetColor(15, 5);
}

void menuK43()
{
	SetColor(14, 5);
	if (m_pos43 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos43 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos43 == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); cls(51, 19, 2); gotoxy(0, 0); }
	if (m_pos43 == 3) { gotoxy(51, 19); cout << "->"; cls(51, 17, 2); gotoxy(0, 0); }
	choice43();
	SetColor(15, 5);
}

void menuK5()
{
	SetColor(14, 5);
	if (m_pos5 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos5 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos5 == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); cls(51, 19, 2); gotoxy(0, 0); }
	if (m_pos5 == 3) { gotoxy(51, 19); cout << "->"; cls(51, 17, 2); cls(51, 21, 2); gotoxy(0, 0); }
	if (m_pos5 == 4) { gotoxy(51, 21); cout << "->"; cls(51, 19, 2); cls(51, 23, 2); gotoxy(0, 0); }
	if (m_pos5 == 5) { gotoxy(51, 23); cout << "->"; cls(51, 21, 2); gotoxy(0, 0); }
	choice5();
	SetColor(15, 5);
}

void menuK51()
{
	SetColor(14, 5);
	if (m_pos51 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos51 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); gotoxy(0, 0); }
	choice51();
	SetColor(15, 5);
}

void menuK52()
{
	SetColor(14, 5);
	if (m_pos52 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos52 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); gotoxy(0, 0); }
	choice52();
	SetColor(15, 5);
}

void menuK53()
{
	SetColor(14, 5);
	if (m_pos53 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos53 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); gotoxy(0, 0); }
	choice53();
	SetColor(15, 5);
}

void menuK54()
{
	SetColor(14, 5);
	if (m_pos54 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos54 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); gotoxy(0, 0); }
	choice54();
	SetColor(15, 5);
}

void menuK55()
{
	SetColor(14, 5);
	if (m_pos55 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos55 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); gotoxy(0, 0); }
	choice55();
	SetColor(15, 5);
}

void menuK6()
{
	SetColor(14, 5);
	if (m_pos6 == 0) { gotoxy(51, 13); cout << "->"; cls(51, 15, 2); gotoxy(0, 0); }
	if (m_pos6 == 1) { gotoxy(51, 15); cout << "->"; cls(51, 13, 2); cls(51, 17, 2); gotoxy(0, 0); }
	if (m_pos6 == 2) { gotoxy(51, 17); cout << "->"; cls(51, 15, 2); cls(51, 19, 2); gotoxy(0, 0); }
	if (m_pos6 == 3) { gotoxy(51, 19); cout << "->"; cls(51, 17, 2); cls(51, 21, 2); gotoxy(0, 0); }
	if (m_pos6 == 4) { gotoxy(51, 21); cout << "->"; cls(51, 19, 2); gotoxy(0, 0); }
	choice6();
	SetColor(15, 5);
}

void menu()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "  Комунальна служба по ремонту аварійних будинків    "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Виведення вмісту файлів на екран                  "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Операції із записами  БД                          "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Фільтрування даних                                "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Сортування даних по категоріях                    "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Актуальні функції комунальної служби              "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Завершення роботи програми                        "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK();
	cin.get();
}

void menu2()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "          Вивід вмісту файлів на екран               "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Вивід бази даних                                  "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Вміст бінарного файлу                             "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Повернутися у головне меню                        "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK2();
}

void menu3()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "              Операції із записами БД                "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Введення нових даних у файл                       "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Редагування інформації                            "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Видалення даних                                   "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Повернутися у головне меню                        "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK3();
}

void menu4()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(63); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "                      Фільтрування даних                       "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(63); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Аварійні будинки району міста по обліку/року спорудження    "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(63); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Необхідні розрахункові обчислення для комунальної служби    "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(63); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Дані про будинки, становище яких в задовільному стані       "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(63); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Повернутися у головне меню                                  "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(63); cout << " "; cout << endl; SetColor(15, 5);
	menuK4();
}

void menu5()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "               Сортування записів БД                 "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За назвою вулиці району міста                     "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За датою постановки будинку на облік              "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " "<< endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За роком побудови будинку                         "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За кількістю мешканців                            "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За наявністю ремонту за останні 20 років          "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Повернутися у головне меню                        "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK5();
}

void menu6()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "            Актуальні функції комунальної служби     "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Сортування записів по року побудови за зростанням "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, що потребують негайного ремонту чи зносу "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, поставлені на облік понад 10 років тому  "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Видалення будинків, розташованих на Пішонівській  "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Повернутися у головне меню                        "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK6();
}

void menu31()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "            Введення нових даних у файл              "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Додати запис на початок файлу                     "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Додати запис в кінець файлу                       "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Повернутися у підменю                             "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK31();
}

void menu41()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "  Аварійні будинки району по обліку/року спорудження "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, поставлені на облік цього року           "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, поставлені на облік понад 10 років тому  "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, поставлені на облік протягом 2000-х років"; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, споруджені протягом 90-х років           "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, споруджені в період 1920-1950 років      "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Повернутися у підменю                             "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK41();
}

void menu42()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "    Розрахункові обчислення для комунальної служби   "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, в яких к-сть жителів перевищує середню   "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, в яких к-сть жителів менша, ніж середня  "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   10 будинків з найбільшою кількістю жителів        "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   10 будинків з найменшою кількістю жителів         "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   К-сть будинків, поставлена на облік поточного року"; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, які через 10 років святкуватимуть ювілей "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Повернутися у підменю                             "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK42();
}

void menu43()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "Дані про будинки, становище яких в задовільному стані"; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Будинки, що взагалі не потребують ремонту         "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Ремонтовані будинки, поставлені на облік недавно  "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Відремонтовані будинки, споруджені впродовж 2000рр"; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Повернутися у підменю                             "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK43();
}

void menu51()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "             За назвою вулиці району міста           "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За зростанням                                     "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За спаданням                                      "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK51();
}

void menu52()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "         За датою постановки будинку на облік        "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За зростанням                                     "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За спаданням                                      "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK52();
}

void menu53()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "             За роком побудови будинку               "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За зростанням                                     "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За спаданням                                      "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK53();
}

void menu54()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "          За кількістю мешканців у будинку           "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За зростанням                                     "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   За спаданням                                      "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK54();
}

void menu55()
{
	system("cls");
	system("color 70");
	printf("\n\n\n\n\n\n\n\n\n\n");
	cout << "						"; SetColor(15, 5); cout << " "; line(53); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1);
	cout << "     За наявністю ремонту за останні 20 років        "; line2(1); cout << " " << endl;
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); linee(53); line2(1); cout << " "; cout << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Ремонт наявний                                    "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); line3(53); line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line2(1); cout << "   Ремонту ще не було                                "; line2(1); cout << " " << endl; SetColor(15, 5);
	cout << "						"; SetColor(15, 5); cout << " "; line1(53); cout << " "; cout << endl; SetColor(15, 5);
	menuK55();
}