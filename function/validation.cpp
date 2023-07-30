// ����� ����, ϲ-18-01
// ��������� �.�.
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Header.h"
using namespace std;

int valid_street(houses *s, int i)
{
	int c = 0;
	for (int j = 0; j < strlen(s[i].street); j++)
		if (s[i].street[j] >= '0' && s[i].street[j] <= '9' || s[i].street[j] == '!' || s[i].street[j] == '~' || s[i].street[j] == '@' || s[i].street[j] == '#' || s[i].street[j] == '�' || s[i].street[j] == '$' || s[i].street[j] == '%' || s[i].street[j] == '^' || s[i].street[j] == '&' || s[i].street[j] == '*' || s[i].street[j] == '(' || s[i].street[j] == ')' || s[i].street[j] == '+' || s[i].street[j] == '=' || s[i].street[j] == '[' || s[i].street[j] == ']' || s[i].street[j] == '{' || s[i].street[j] == '}' || s[i].street[j] == ';' || s[i].street[j] == ':' || s[i].street[j] == '"' || s[i].street[j] == '<' || s[i].street[j] == '>' || s[i].street[j] == ',' || s[i].street[j] == '.' || s[i].street[j] == '?' || s[i].street[j] == '/' || s[i].street[j] == '|')
			c++;
	if (c > 0)
	{
		cout << "� ���� ������ ������� ����������� �������! ������ �� ������.." << endl << endl;
		return 0;
	}
	else
	{
		return 1;
	}
	return c;
}

int valid_number(houses* s, int i)
{
	int c = 0;
	if (cin.fail() || s[i].number_house <= 0 || s[i].number_house > 10000)
	{
		c++;
		cin.clear();
		cin.sync();
		cout << "����� ������� ������� �����������! ������ ���� ������.."<<endl;
		return 0;
	}
	else
	{
		return 1;
	}

	return c;
}

int valid_meshk(houses* s, int i)
{
	int c = 0;
	if (cin.fail() || s[i].kol_meshk < 0 || s[i].kol_meshk > 10000)
	{
		c++;
		cin.clear();
		cin.sync();
		cout << "������� ����������� �������� ������� ������ � �������! ������ ���� ������.." << endl;
		return 0;
	}
	else
	{
		return 1;
	}

	return c;
}

int valid_year(houses* s, int i)
{
	int c = 0;
	if (cin.fail() || s[i].year_construct < 0 || s[i].year_construct > 10000)
	{
		c++;
		cin.clear();
		cin.sync();
		cout << "������� ����������� �������� ���� �������� �������! ������ ���� ������.." << endl;
		return 0;
	}
	else
	{
		return 1;
	}

	return c;
}

int valid_date(houses* s, int i)
{
	if ((s[i].date[2] == '.') && (s[i].date[5] == '.') && ((((s[i].date[0] - '0') * 10) + (s[i].date[1] - '0')) <= 30) && ((((s[i].date[3] - '0') * 10) + (s[i].date[4] - '0')) <= 12) && ((((s[i].date[6] - '0') * 1000) + ((s[i].date[7] - '0') * 100) + ((s[i].date[8] - '0') * 10) + ((s[i].date[9] - '0'))) <= 2020) && ((((s[i].date[6] - '0') * 1000) + ((s[i].date[7] - '0') * 100) + ((s[i].date[8] - '0') * 10) + ((s[i].date[9] - '0'))) >= 1950))
		return 1;
	else
	{
		cout << "������� ����������� �������� ���� ���������� �� ����! ������ �� ������.." << endl;
		return 0;
	}
}

int valid_repair(houses *s, int i)
{
	if (strcmp(s[i].repair, "���") == 0 || strcmp(s[i].repair, "���") == 0 || strcmp(s[i].repair, "ͳ") == 0 || strcmp(s[i].repair, "�") == 0 || strcmp(s[i].repair, "yes") == 0 || strcmp(s[i].repair, "Yes") == 0 || strcmp(s[i].repair, "no") == 0 || strcmp(s[i].repair, "No") == 0)
		return 1;
	else
	{
		cout << "������� ���������� ������� ���� �������� �������! ������ �� ������.." << endl;
		return 0;
	}
}

int valid_n(int n)
{
	int c = 0;
	if (cin.fail() || n <= 0 || n > 100)
	{
		c++;
		cin.clear();
		cin.sync();
		cout << "������� ����������� ������� ������! ������ �� ������..\n";
		return 0;
	}
	else
	{
		return 1;
	}
	return c;
}

