#include <iostream>

#include "Game.h"

Game::Game():joker("A", 50, 50, 1) {
	resetGame();
}

void Game::resetGame() {
	deck.deckReset();
	deck.shuffle();
	hand.handReset();
}

void Game::startGame() {
	while (true) {
		playRound();

		if (joker.getHp() <= 0) {
			std::cout << "Joker is defeated, proceed to next level!\n";
			system("pause");
			system("cls");
			nextLevel();
		}
		else if (hand.getRemainingHands() <= 0) {
			std::cout << "No hands left, you lose!\n";
			system("pause");
			system("cls");
			break;
		}
	}
}

void Game::playRound() {

	// first draw
	for (int c = 0; c < 10; c++) {
		hand.addCard(deck.drawCard());
	}

	do {
		joker.displayJoker();
		hand.sortHand();
		hand.displayHand();
		std::cout << "Remaining Cards: " << deck.remainingCards() << "/52\n";
		std::cout << "Remaining Hands: " << hand.getRemainingHands() << "/3\n";

		hand.playHand();

		score.calculateTotalChips(hand.getPlayedCards());
		score.displayScore(hand.getPlayedCards());
		joker.takeDamage(score.getTotalChips(), score.getHandType());

		std::cout << "\n\n";

		for (int c = 0; c < 3; c++) {
			hand.addCard(deck.drawCard());
		}
	} while (hand.getRemainingHands() > 0 && joker.getHp() > 0);
}

void Game::nextLevel() {
	joker.jokerLvUp();
	joker.spawnJoker();
	resetGame();
}