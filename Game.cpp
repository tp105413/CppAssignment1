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

	hand.addAbility(deck.drawAbilityCard());

	do {
		joker.displayJoker();
		hand.sortHand();
		hand.displayHand();
		std::cout << "\nRemaining Cards: " << deck.remainingCards() << "/52\n";
		std::cout << "Remaining Hands: " << hand.getRemainingHands() << "/3\t";
		std::cout << "Remaining Discards: " << hand.getRemainingDiscards() << "/2\n";

		int action = 0;
		do {
			std::cout << "\n1. Play\t2. Discard\nChoose: ";
			
			if (!(std::cin >> action)) {
				std::cin.clear();
				std::cin.ignore(1000, '\n');
				std::cout << "Please enter a number!\n";
				continue;
			}

			switch (action) {
			case 1:
			{
				std::string abilityName = "";

				hand.playHand();

				int choose;
				if (hand.hasAbility()) {

					std::cout << "\nUse Ability Card (0 to not use): ";
					if (!(std::cin >> choose)) {
						std::cin.clear();
						std::cin.ignore(1000, '\n');
						choose = 0;
					}
				}
				else {
					choose = 0;
				}

				if (choose > 0 && choose < hand.getPlayerAbilitySize()) {
					AbilityCard ability = hand.getAbility(choose - 1);
					abilityName = ability.getName();
					hand.removeAbilityCard(choose - 1);
				}
				else {
					choose = 0;
				}

				hand.displayHandPlayed(abilityName);
				score.calculateTotalChips(hand.getPlayedCards(), abilityName);
				score.displayScore(hand.getPlayedCards());
				joker.takeDamage(score.getTotalChips(), score.getHandType());

				std::cout << "\n\n";

				for (int c = 0; c < 3; c++) {
					hand.addCard(deck.drawCard());
				}
				break;
			}
			case 2:
			{
				if (hand.getRemainingDiscards() > 0) {
					int discardCard = hand.discardHand();
					system("cls");
					std::cout << "\nDiscard " << discardCard << " Cards\n\n";
					for (int i = 0; i < discardCard; i++) {
						hand.addCard(deck.drawCard());
					}
				}
				else {
					system("cls");
					std::cout << "\nYou have no more discard!\n";
				}
				break;
			}
			default:
				std::cout << "Invalid Choice!\n";
				break;
			}
		} while (action != 1 && action != 2);

	} while (hand.getRemainingHands() > 0 && !joker.isDead());
}

void Game::nextLevel() {
	joker.jokerLvUp();
	joker.spawnJoker();
	resetGame();
}