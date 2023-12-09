#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

#include "arcanoid.h"

using namespace std;

void Menu::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Objects::gotoxy(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void Menu::intro()
{
	ShowCursor(false);
	system("COLOR 0E");
	gotoxy(1, 8);
	cout << "          XXX          XXXXXXX     XXX   XXX           XXX          XXXX   XXX      XXXXXXX     XXX  XXXXXXXX       " << endl;
	Sleep(50);
	gotoxy(1, 9);
	cout << "         XXXXX         XXXXXXXX    XXX  XXX           XXXXX         XXXXX  XXX    XXX     XXX   XXX  XXXXXXXXXX     " << endl;
	Sleep(50);
	gotoxy(1, 10);
	cout << "        XXXXXXX        XXX   XX    XXX XXX           XXXXXXX        XXXXXX XXX   XXX       XXX  XXX  XXX    XXXX    " << endl;
	Sleep(50);
	gotoxy(1, 11);
	cout << "       XXX   XXX       XXX   XX    XXXXXX           XXX   XXX       XXX XXXXXX  XXX         XXX XXX  XXX     XXXX   " << endl;
	Sleep(50);
	gotoxy(1, 12);
	cout << "      XXX     XXX      XXXXXXX     XXXXXX          XXX     XXX      XXX  XXXXX  XXX         XXX XXX  XXX      XXXX  " << endl;
	Sleep(50);
	gotoxy(1, 13);
	cout << "     XXXXXXXXXXXXX     XXXXXX      XXX XXX        XXXXXXXXXXXXX     XXX   XXXX  XXX         XXX XXX  XXX     XXXX   " << endl;
	Sleep(50);
	gotoxy(1, 14);
	cout << "    XXXXXXXXXXXXXXX    XXX  XX     XXX  XXX      XXXXXXXXXXXXXXX    XXX    XXX   XXX       XXX  XXX  XXX    XXXX    " << endl;
	Sleep(50);
	gotoxy(1, 15);
	cout << "   XXXX         XXXX   XXX   XXX   XXX   XXX    XXXX         XXXX   XXX    XXX    XXX     XXX   XXX  XXXXXXXXXX     " << endl;
	Sleep(50);
	gotoxy(1, 16);
	cout << "  XXXX           XXXX  XXX    XXX  XXX    XXX  XXXX           XXXX  XXX    XXX      XXXXXXX     XXX  XXXXXXXX       " << endl;
	Sleep(50);
	Sleep(2000);
	system("cls");
}

void Menu::mainMenu()
{
	while (true)
	{

		system("cls");
		system("COLOR 0E");
		gotoxy(30, 9);
		cout << "|-----------------------------------------------------| ";
		gotoxy(30, 10);
		cout << "|                                                     | ";
		gotoxy(30, 11);
		cout << "|               >>>>>>> G R A <<<<<<<                 | ";
		gotoxy(30, 12);
		cout << "|                                                     | ";
		gotoxy(30, 13);
		cout << "|                  1 - Gra                            | ";
		gotoxy(30, 14);
		cout << "|                  2 - Statystyki                     | ";
		gotoxy(30, 15);
		cout << "|                  3 - Wyjscie                        | ";
		gotoxy(30, 16);
		cout << "|                                                     | ";
		gotoxy(30, 17);
		cout << "|-----------------------------------------------------|";
		gotoxy(30, 18);
		cout << "Wybiez dostepna opcje z menu: " << endl;
		choice = getchar();

		switch (choice)
		{
		case '1':
			system("cls");
			system("COLOR 0E");
			gotoxy(40, 10);
			cout << "Wprowadz nazwe gracza " << endl;
			gotoxy(40, 11);
			cout << "Nazwa gracza: " << endl;
			cin >> player;
			system("cls");
			// punkty = gra();
			// zapisz_do_pliku(gracz, punkty);
			break;

		case '2':
			system("cls");
			// odczytaj_z_pliku();
			cout << "Odczyt z pliku" << endl;
			break;

		case '3':
			exit(0);
			break;
		}
	}
}

void Menu::gameFrame()
{
	system("cls");
	for (int i = 4; i < 24; i++) // left wall
	{
		gotoxy(20, i);
		cout << "|";
	}
	for (int i = 4; i < 24; i++) // right wall
	{
		gotoxy(120, i);
		cout << "|";
	}
	for (int i = 21; i < 120; i++) // upper wall
	{
		gotoxy(i, 3);
		cout << "_";
	}
	for (int i = 21; i < 120; i++) // bottom wall
	{
		gotoxy(i, 23);
		cout << "_";
	}
	gotoxy(0, 30);
}

void Menu::dataFrame()
{
	system("COLOR 0A");
	gotoxy(130, 10);
	cout << " ____________________";
	gotoxy(130, 11);
	cout << "|                    |";
	gotoxy(130, 12);
	cout << "| Punkty:            |";
	gotoxy(130, 13);
	cout << "| Czas:              |";
	gotoxy(130, 14);
	cout << "|                    |";
	gotoxy(130, 15);
	cout << "|  Q  - wyjscie      |";
	gotoxy(130, 16);
	cout << "|                    |";
	gotoxy(130, 17);
	cout << "|____________________|";
	gotoxy(0, 30);
}
void Objects::move()
{
	ShowCursor(false);
	int i = 60;
	gotoxy(i, 21);
	cout << "====" << endl;
	while (true)
	{
		while (_kbhit())
		{
			arrows = _getch();
			if (arrows == 'a') // move left
			{
				gotoxy(i, 21);
				cout << " ==== ";
				i--;
			}
			else if (arrows == 'd') // move right
			{
				gotoxy(i, 21);
				cout << " ==== ";
				i++;
			}
		}
	}
}

void Menu::ShowCursor(bool show) {
	HANDLE hConsoleOutput;
	CONSOLE_CURSOR_INFO structCursorInfo;
	hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
	GetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
	structCursorInfo.bVisible = show;
	SetConsoleCursorInfo(hConsoleOutput, &structCursorInfo);
}
