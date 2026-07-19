#include <string>

#include "Card.h"

Card::Card(Suit s, Rank r) {
	suit = s;
	rank = r;
}

Suit Card::getSuit() const {
	return suit;
}

Rank Card::getRank() const {
	return rank;
}

int Card::getChips() const {
	if (rank == Rank::Ace || rank == Rank::Jack || rank == Rank::Queen || rank == Rank::King) {
		return 10;
	}

	// static_cast take rank value as integer
	return static_cast<int>(rank);
}

// turn rank and suit to string
std::string Card::displayCard() const {
	std::string display;

	switch (suit) {
	case Suit::Spades:
		display = "♠️";
		break;
	case Suit::Hearts:
		display = "♥️";
		break;
	case Suit::Clubs:
		display = "♣️";
		break;
	case Suit::Diamonds:
		display = "♦️";
		break;
	}

	switch (rank) {
	case Rank::Ace:
		display += "A";
		break;
	case Rank::Jack:
		display += "J";
		break;
	case Rank::Queen:
		display += "Q";
		break;
	case Rank::King:
		display += "K";
		break;
	default:
		display += std::to_string(static_cast<int>(rank));
	}

	return display;
}