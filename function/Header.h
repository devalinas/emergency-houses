#ifndef HeaderH
#define HeaderH
#include <iostream>
#include <conio.h>
#include <iomanip>
#include <time.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <Windows.h>
using namespace std;

struct houses
{
	char street[30];
	int number_house;
	int kol_meshk;
	int year_construct;
	char date[11];
	char repair[4];
};

void menu();
void fullConsole();
void output_struct_txt(FILE* newf, houses h[], int i);
void output_struct_console(houses h[], int i);
int valid_street(houses *s, int i);
int valid_number(houses *s, int i);
int valid_date(houses *s, int i);
int valid_meshk(houses *s, int i);
int valid_year(houses *s, int i);
int valid_repair(houses *s, int i);
int valid_n(int n);
int edit();
int repair();
int with_repair();
int repair_yes();
int oblik_current_year();
int oblik_year2000();
int oblik_year_10ago();
int oblik_year_recently();
int more_kol_meshk();
int smaller_kol_meshk();
int more_houses_100year();
int year_created90();
int year_created_1920_1950();
int year_created2000();
int limit_kol_meshk10(int x);
int kol_oblik_current();
int kilkzap();
void shapka();
void shapka_txt(FILE* newf, int n);
int output1();
int output2();
int record_start();
int record_end();
int sort_street(int x);
int sort_date(int x);
int sort_repair(int x);
int sort_year_constructed(int x);
int sort_kol_meshk(int x);
void del();
void del_street();
void line(int n);
void linee(int n);
void line1(int n);
void line2(int n);
void line3(int n);
void gotoxy(int x, int y);
#endif
