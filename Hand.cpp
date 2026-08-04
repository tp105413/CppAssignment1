#include <algorithm>
#include <iostream>

#include "Hand.h"

void Hand::addCard(BaseCard card) {
	hand.push_back(card);
}

void Hand::addAbility(AbilityCard ability) {
	playerAbilities.push_back(ability);
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

	std::cout << "\nAbility Card: \n";
	if (playerAbilities.empty()) {
		std::cout << "No ability card\n";
	}
	else {
		for (int a = 0; a < playerAbilities.size(); a++) {
			std::cout << a + 1;
			playerAbilities[a].play();
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

		// prevent infinite loop when invalid input happens
		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter a number!\n";
			i--;
			continue;
		}

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

	// sort the selected cards descending
	std::sort(selectCards.rbegin(), selectCards.rend());
	for (int index : selectCards) {
		hand.erase(hand.begin() + index);
	}

	handRemaining--;
}

// display played cards and ability
void Hand::displayHandPlayed(std::string& abilityName) {

	system("cls");
	
	if (abilityName != "") {
		std::cout << "Use " << abilityName << " Ability!\n";
	}

	std::cout << "Playing cards: ";
	for (BaseCard& card : playedCards) {
		card.play();
	}
}

int Hand::discardHand() {
	int choice;
	std::vector<int> selectCards;
	int discardCount = 0;

	std::cout << "\nDiscard up to 3 cards! Select 0 to stop discard!\n";
	for (int i = 0; i < 3; i++) {
		std::cout << "Choose Card " << i + 1 << ": ";

		if (!(std::cin >> choice)) {
			std::cin.clear();
			std::cin.ignore(1000, '\n');
			std::cout << "Please enter a number!\n";
			i--;
			continue;
		}

		if (choice == 0) {
			break;
		}

		if (choice < 1 || choice > hand.size()) {
			std::cout << "Invalid card!\n";
			i--;
			continue;
		}

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
		discardCount++;
	}

	std::sort(selectCards.rbegin(), selectCards.rend());
	for (int index : selectCards) {
		hand.erase(hand.begin() + index);
	}

	if (discardCount > 0) {
		discardRemaining--;
	}

	return discardCount;
}

std::vector<BaseCard> Hand::getPlayedCards() const {
	return playedCards;
}

void Hand::handReset() {
	handRemaining = 3;
	discardRemaining = 2;
	hand.clear();
}

int Hand::getRemainingHands() const {
	return handRemaining;
}

int Hand::getRemainingDiscards() const {
	return discardRemaining;
}

bool Hand::hasAbility() {
	return !playerAbilities.empty();
}

AbilityCard Hand::getAbility(int index) const {
	return playerAbilities[index];
}

void Hand::removeAbilityCard(int index) {
	playerAbilities.erase(playerAbilities.begin() + index);
}

size_t Hand::getPlayerAbilitySize() {
	return playerAbilities.size();
}