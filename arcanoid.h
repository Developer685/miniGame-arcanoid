#include <iostream>
#include <stdio.h>
#include <windows.h>
#include <conio.h>

using namespace std;

class Menu
{
private:
    int privateDate;
    int width;
    int height;
    int x; // curosor positions
    int y;
    int points;
    int choice;
    string player;

public:
    void mainMenu();
    void gotoxy(int x, int y);
    void intro();
    void gameFrame(); // main frame
    void dataFrame(); // frame with player data (points, time and so on)
    void ShowCursor(bool show);
};

class Objects
{
private:
    char arrows;
    int x, y; // cursor positions
public:
    void gotoxy(int x, int y);
    void move();
    void ball();
    void brick();
};
