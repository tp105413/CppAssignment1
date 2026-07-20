#include <iostream>
#include <Windows.h>

#include "Deck.h"
#include "Hand.h"
#include "Score.h"

using namespace std;

int main() {
	// show suit icons
	SetConsoleOutputCP(CP_UTF8);

	Deck deck;
	deck.shuffle();

	Hand hand;
	for (int c = 0; c < 10; c++) {
		hand.addCard(deck.drawCard());
	}

	hand.sortHand();
	hand.displayHand();
	cout << "\nRemaining Cards: " << deck.remainingCards() << "/52";

	hand.playHand();

	Score score;
	score.calculateTotalChips(hand.getPlayedCards());
	score.displayScore(hand.getPlayedCards());
	
	return 0;
}