#pragma once

#include <string>

#include "Deck.h"
#include "Hand.h"
#include "Score.h"
#include "Joker.h"

class Game {
private:
	Deck deck;
	Hand hand;
	Score score;
	Joker joker;

public:
	Game();
	void resetGame();
	void startGame();
	void playRound();
	void nextLevel();
};