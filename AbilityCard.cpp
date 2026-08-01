#include <iostream>

#include "AbilityCard.h"

AbilityCard::AbilityCard(std::string name, std::string des) {
	abilityName = name;
	description = des;
}

std::string AbilityCard::displayCard() const {
	return ". " + abilityName + ": " + description;
}

void AbilityCard::play() {
	std::cout << displayCard()<<"\n";
}

std::string AbilityCard::getName() const {
	return abilityName;
}