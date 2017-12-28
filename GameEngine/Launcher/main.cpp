#include <Windows.h>
#include <cstdlib>
#include <iostream>

using namespace std;

int GetInput()
{
	int choice;
	cin >> choice;
	return choice;
}

void DisplayMainMenu()
{
	cout << "Main Menu\n";
	cout << "Please make your selection\n";
	cout << "1 - Snake\n";
	cout << "2 - Platformer\n";
	cout << "3 - Exit\n";
	cout << "Selection: ";
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
			system("start ..\\Debug\\Game.exe");
			break;
		case 2:
			system("start ..\\Debug\\Platform.exe");
		case 3:
			break;
		default:
			break;
		}
	} while (choice != 3);
	return 0;
}