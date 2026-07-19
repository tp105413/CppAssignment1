#pragma once

#include <string>

class Card {
public:
	// destructor
	virtual ~Card() = default;
	virtual std::string displayCard() const = 0;
	virtual void play() = 0;
};