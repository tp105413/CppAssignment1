#pragma once

#include <vector>

#include "BaseCard.h"
#include "AbilityCard.h"

class Hand {
private:
	std::vector<BaseCard> hand;
	std::vector<BaseCard> playedCards;
	std::vector<AbilityCard> playerAbilities;

	int handRemaining = 3;
	int discardRemaining = 2;

public:
	void addCard(BaseCard card);
	void addAbility(AbilityCard ability);
	void sortHand();
	void displayHand();
	void playHand();
	void displayHandPlayed(std::string& abilityName);
	int discardHand();
	std::vector<BaseCard> getPlayedCards() const;
	void handReset();
	int getRemainingHands() const;
	int getRemainingDiscards() const;
	bool hasAbility();
	AbilityCard getAbility(int index) const;
	void removeAbilityCard(int index);
};