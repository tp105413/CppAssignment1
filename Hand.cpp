#include <algorithm>
#include <iostream>

#include "Hand.h"

void Hand::addCard(BaseCard card) {
	hand.push_back(card);
}

// arrange hand by comparing rank then suit
void Hand::sortHand() {
	std::sort(hand.begin(), hand.end(), [](const BaseCard& a, const BaseCard& b) {
		if (a.getRank() != b.getRank()) {
			return static_cast<int>(a.getRank()) < static_cast<int>(b.getRank());
		}
		return static_cast<int>(a.getSuit()) < static_cast<int>(b.getSuit());
	});
}

void Hand::displayHand() {
	for (int c = 0; c < hand.size(); c++) {
		std::cout << c + 1 << "." << hand[c].displayCard()<<"\t";

		if ((c + 1) % 5 == 0) {
			std::cout << "\n";
		}
	}
}

void Hand::playHand() {
	int choice;
	std::vector<int> selectCards;

	playedCards.clear();

	std::cout << "\nPlay 3 cards!\n";

	for (int i = 0;i < 3; i++) {
		std::cout << "Choose card " << i + 1 << ": ";
		std::cin >> choice;

		if (choice < 1 || choice > hand.size()) {
			std::cout << "Invalid card!\n";
			i--;
			continue;
		}
		
		// check duplicate select card
		bool selectedCheck = false;

		for (int selected : selectCards) {
			if (selected == choice - 1) {
				selectedCheck = true;
				break;
			}
		}

		if (selectedCheck) {
			std::cout << "Card is already selected!\n";
			i--;
			continue;
		}

		selectCards.push_back(choice - 1);
		playedCards.push_back(hand[choice - 1]);
	}

	std::cout << "\nPlaying cards: ";

	for (int index : selectCards) {
		hand[index].play();
	}

	// sort the selected cards descending
	std::sort(selectCards.rbegin(), selectCards.rend());
	for (int index : selectCards) {
		hand.erase(hand.begin() + index);
	}
}

std::vector<BaseCard> Hand::getPlayedCards() const {
	return playedCards;
}

void Hand::handReset() {
	hand.clear();
}