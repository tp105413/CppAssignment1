#include "AbilityCard.h"

AbilityCard::AbilityCard(std::string name) {
	abilityName = name;
}

std::string AbilityCard::displayCard() const {
	return abilityName;
}