#include <iostream>
#include <Windows.h>
#include <string>

#include "Game.h"

using namespace std;

int main() {
	// show suit icons
	SetConsoleOutputCP(CP_UTF8);

	int choice;

	do {
		system("cls");
		cout << "===== Big Three =====\n\n";
		cout << "1. Start Game\n";
		cout << "2. How to play\n";
		cout << "3. Quit\n";
		cout << "\n" << string(21, '=') << "\n";
		cout << "Choose: ";
		
		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter a number!\n";
			system("pause");
			continue;
		}

		switch (choice) {
		case 1: {
			system("cls");
			Game game;
			game.startGame();
			break;
		}
		case 2:
			system("cls");
			cout << string(20, '=') << " How to Play " << string(20, '=');
			cout << "\nPlay 3 cards each round and defeat the Joker within the given rounds.\n";
			cout << "Each played card has its own base chips.\n";
			cout << "Every round will get an Ability card.\n";
			cout << "\n" << string(20, '=') << "Hand Types " << string(20, '=');
			cout << "\nHigh Card: 10 Chips × 1.5\n";
			cout << "Pair: 15 Chips × 2\n";
			cout << "Flush: 10 Chips x 2\n";
			cout << "Straight: 20 Chips x 2\n";
			cout << "Straight Flush: 45 Chips x 4\n";
			cout << "Big Three: 30 Chips × 3 (instantly breaks Joker's Shield)\n\n";
			system("pause");
			break;
		case 3:
			break;
		default:
			cout << "\nInvalid Choice!\n";
			system("pause");
			break;
		}
	} while (choice != '3');

	exit(0);
	
	return 0;
}