#include <algorithm>
#include <iostream>

#include "Hand.h"

void Hand::addCard(Card card) {
	hand.push_back(card);
}

// arrange hand by comparing rank then suit
void Hand::sortHand() {
	std::sort(hand.begin(), hand.end(), [](const Card& a, const Card& b) {
		if (a.getRank() != b.getRank()) {
			return static_cast<int>(a.getRank()) < static_cast<int>(b.getRank());
		}
		return static_cast<int>(a.getSuit()) < static_cast<int>(b.getSuit());
	});
}

void Hand::displayHand() {

	sortHand();

	for (int c = 0; c < hand.size(); c++) {
		std::cout << c + 1 << "." << hand[c].displayCard()<<"\t";

		if ((c + 1) % 5 == 0) {
			std::cout << "\n";
		}
	}
}