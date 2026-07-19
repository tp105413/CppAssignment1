#pragma once

#include <string>

#include "Card.h"

class AbilityCard : public Card {
private:
	std::string abilityName;

public:
	AbilityCard(std::string name);

	std::string displayCard() const override;
};