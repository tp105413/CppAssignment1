#include <iostream>
#include <algorithm>

#include "Score.h"

bool Score::isBigThree(const std::vector<BaseCard>& cards) {
	return cards[0].getRank() == cards[1].getRank() &&
		cards[1].getRank() == cards[2].getRank();
}

bool Score::isStraightFlush(const std::vector<BaseCard>& cards) {
	return isStraight(cards) && isFlush(cards);
}

bool Score::isStraight(const std::vector<BaseCard>& cards) {
	std::vector<BaseCard> temp = cards;

	std::sort(temp.begin(), temp.end(), [](const BaseCard& a, const BaseCard& b) {
		return static_cast<int>(a.getRank()) < static_cast<int>(b.getRank());
		});

	int r1 = static_cast<int>(temp[0].getRank());
	int r2 = static_cast<int>(temp[1].getRank());
	int r3 = static_cast<int>(temp[2].getRank());

	return r2 == r1 + 1 && r3 == r2 + 1;
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

void Score::calculateTotalChips(const std::vector<BaseCard>& cards, std::string abilityName) {
	if (isBigThree(cards)) {
		handTypes = "Big Three";
		baseChips = 30;
		multiplier = 3;
	}
	else if (isStraightFlush(cards)) {
		handTypes = "Straight Flush";
		baseChips = 45;
		multiplier = 4;
	}
	else if (isStraight(cards)) {
		handTypes = "Straight";
		baseChips = 20;
		multiplier = 2;
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

	if (abilityName != "") {
		if (abilityName == "Big 3") {
			handTypes = "Big Three";
			baseChips = 30;
			multiplier = 3;
		}
		else if (abilityName == "Power Chips") {
			baseChips += 20;
		}
		else if (abilityName == "Power Multiplier") {
			multiplier += 1;
		}
		else if (abilityName == "Shield Breaker") {
			handTypes = "Shield Breaker";
		}
	}

	totalChips = static_cast<int>((baseChips + cardChips) * multiplier);
}

void Score::displayScore(const std::vector<BaseCard>& cards) const {
	std::cout << "\nHand Types: " << handTypes;
	std::cout << "\nCard Chips: ";
	for (int i = 0; i < cards.size(); i++) {
		std::cout << cards[i].getChips();

		if (i < cards.size() - 1) {
			std::cout << "+";
		}
	}
	std::cout << " = " << cardChips;

	std::cout << "\nBase Chips: " << baseChips;
	std::cout << "\nMultiplier: " << multiplier;
	std::cout << "\nTotal Chips: " << "(" << baseChips << "+" << cardChips << ")" << "*" << multiplier << " = " << totalChips << "\n";
}

int Score::getTotalChips() const {
	return totalChips;
}

std::string Score::getHandType() {
	return handTypes;
}