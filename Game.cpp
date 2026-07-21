#include <iostream>

#include "Game.h"

Game::Game() {
	resetGame();
}

void Game::resetGame() {
	deck.deckReset();
	deck.shuffle();
	hand.handReset();
}

void Game::startGame() {

	for (int c = 0; c < 10; c++) {
		hand.addCard(deck.drawCard());
	}
	hand.sortHand();
	hand.displayHand();
	std::cout << "Remaining Cards: " << deck.remainingCards() << "/52\n";
}