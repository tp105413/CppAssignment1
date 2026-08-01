#pragma once

#include <string>

#include "Card.h"

class AbilityCard : public Card {
private:
	std::string abilityName;
	std::string description;

public:
	AbilityCard(std::string name, std::string description);


	std::string displayCard() const override;
	void play() override;
	std::string getName() const;
};