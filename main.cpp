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
		cin >> choice;

		switch (choice) {
		case 1: {
			system("cls");
			Game game;
			game.startGame();
			break;
		}
		case 2:
			system("cls");
			//rules
			break;
		case 3:
			//quit
			break;
		default:
			cout << "\nInvalid Choice!\n";
			break;
		}
	} while (choice != 3);
	
	//hand.playHand();

	//Score score;
	//score.calculateTotalChips(hand.getPlayedCards());
	//score.displayScore(hand.getPlayedCards());

	//cout << "\n\n";
	//for (int c = 0; c < 3; c++) {
	//	hand.addCard(deck.drawCard());
	//}
	//hand.sortHand();
	//hand.displayHand();
	//cout << "Remaining Cards: " << deck.remainingCards() << "/52\n";
	
	return 0;
}