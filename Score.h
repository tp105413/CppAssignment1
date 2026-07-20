#pragma once

#include <vector>

#include "BaseCard.h"

class Score {
private:
	int baseChips;
	int cardChips;
	double multiplier;
	int totalChips;
	bool isBigThree(const std::vector<BaseCard>& cards);
	bool isPair(const std::vector<BaseCard>& cards);

public:
	void calculateTotalChips(const std::vector<BaseCard>& cards);
	void displayScore(const std::vector<BaseCard>& cards) const;
};