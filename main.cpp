#include <iostream>
#include <Windows.h>

#include "Deck.h"
#include "Hand.h"

using namespace std;

int main() {
	// show suit icons
	SetConsoleOutputCP(CP_UTF8);

	Deck deck;
	deck.shuffle();

	Hand hand;
	for (int c = 0; c < 13; c++) {
		hand.addCard(deck.drawCard());
	}

	hand.displayHand();
	cout << "\nRemaining Cards: " << deck.remainingCards() << "/52";
	
	return 0;
}