#include <iostream>

#include "Score.h"

bool Score::isBigThree(const std::vector<BaseCard>& cards) {
	return cards[0].getRank() == cards[1].getRank() &&
		cards[1].getRank() == cards[2].getRank();
}

bool Score::isPair(const std::vector<BaseCard>& cards) {
	return cards[0].getRank() == cards[1].getRank() ||
		cards[1].getRank() == cards[2].getRank() ||
		cards[0].getRank() == cards[2].getRank();
}

bool Score::isFlush(const std::vector<BaseCard>& cards) {
	return cards[0].getSuit() == cards[1].getSuit() &&
		cards[1].getSuit() == cards[2].getSuit() &&
		cards[0].getSuit() == cards[2].getSuit();
}

void Score::calculateTotalChips(const std::vector<BaseCard>& cards) {
	if (isBigThree(cards)) {
		handTypes = "Big Three";
		baseChips = 30;
		multiplier = 3;
	}
	else if (isPair(cards)) {
		handTypes = "Pair";
		baseChips = 15;
		multiplier = 2;
	}
	else if (isFlush(cards)) {
		handTypes = "Flush";
		baseChips = 10;
		multiplier = 2;
	}
	else {
		handTypes = "High Card";
		baseChips = 10;
		multiplier = 1.5;
	}

	cardChips = 0;

	for (const BaseCard& card : cards) {
		cardChips += card.getChips();
	}

	totalChips = static_cast<int>((baseChips + cardChips) * multiplier);
}

void Score::displayScore(const std::vector<BaseCard>& cards) const {
	std::cout << "\nHand Types: " << handTypes;
	std::cout << "\nCard Chips: ";
	for (int i = 0; i < cards.size(); i++) {
		std::cout << cards[i].getChips();

		if (i < cards.size() - 1) {
			std::cout << " + ";
		}
	}
	std::cout << " = " << cardChips;

	std::cout << "\nBase Chips: " << baseChips;
	std::cout << "\nMultiplier: " << multiplier;
}