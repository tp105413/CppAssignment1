#pragma once

#include <vector>
#include <string>

#include "BaseCard.h"

class Score {
private:
	int baseChips = 0;
	int cardChips = 0;
	double multiplier = 1.0;
	int totalChips = 0;
	std::string handTypes;

	bool isBigThree(const std::vector<BaseCard>& cards);
	bool isPair(const std::vector<BaseCard>& cards);
	bool isFlush(const std::vector<BaseCard>& cards);

public:
	void calculateTotalChips(const std::vector<BaseCard>& cards);
	void displayScore(const std::vector<BaseCard>& cards) const;
};