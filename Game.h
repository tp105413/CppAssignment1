#pragma once

#include "Deck.h"
#include "Hand.h"
#include "Score.h"

class Game {
private:
	Deck deck;
	Hand hand;
	Score score;

public:
	Game();
	void resetGame();
	void startGame();
};