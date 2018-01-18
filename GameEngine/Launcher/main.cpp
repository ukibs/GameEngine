#include <Windows.h>
#include <cstdlib>
#include <iostream>
#include "..\Platform\GameManager.h"
#include "..\VerticalShooter\GameManager.h"
#include "..\Game\GameManager.h"

using namespace std;

int GetInput()
{
	int choice;
	cin >> choice;
	return choice;
}

void gotoxy(int x, int y) {

	HANDLE hCon;
	hCon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;//estructura de coordenadas
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hCon, dwPos);//para posicionar el cursor
}

void DisplayMainMenu()
{
	for (int i = 2; i < 78; i++)//lineas horizontales del recuadro
	{
		gotoxy(i, 1);  cout << char(205);
		gotoxy(i, 13); cout << char(205);
	}

	gotoxy(2, 1);  cout << char(201);
	gotoxy(2, 13); cout << char(200);
	gotoxy(77, 1); cout << char(187);
	gotoxy(77, 13); cout << char(188);

	gotoxy(3, 2);
	cout << "\n     ---------------------------MAIN MENU----------------------------------\n";
	cout << "\n                             1. Snake                                        ";
	cout << "\n                             2. Platformer                                   ";
	cout << "\n                             3. Vertical Shooter                             ";
	cout << "\n                             4. Exit                                         ";
	cout << "\n                                                                             ";
	cout << "\n                            Select option => ";
}

int main(int argc, char *argv[])
{
	int choice = 0;

	do
	{
		system("cls");
		DisplayMainMenu();
		choice = GetInput();
		switch (choice) {
		case 1:
		{
			Snake::GameManager* gManager = new Snake::GameManager();
			while (!gManager->update()) {}
			gManager->close();
			break;
		}
		case 2:
		{
			Platform::GameManager* gManager = new Platform::GameManager();
			while (!gManager->update()) {}
			gManager->close();
			break;
		}
		case 3:
		{
			VerticalShooter::GameManager* gManager = new VerticalShooter::GameManager();
			while (!gManager->update()) {}
			gManager->close();
			break;
		}
		case 4:
			break;
		default:
			break;
		}
	} while (choice != 4);
	return 0;
}