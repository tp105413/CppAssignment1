#include <string>
#include <iostream>

#include "BaseCard.h"

BaseCard::BaseCard(Suit s, Rank r) {
	suit = s;
	rank = r;
}

Suit BaseCard::getSuit() const {
	return suit;
}

Rank BaseCard::getRank() const {
	return rank;
}

int BaseCard::getChips() const {
	if (rank == Rank::Ace || rank == Rank::Jack || rank == Rank::Queen || rank == Rank::King) {
		return 10;
	}

	// static_cast take rank value as integer
	return static_cast<int>(rank);
}

// turn rank and suit to string
std::string BaseCard::displayCard() const {
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

void BaseCard::play() {
	std::cout << displayCard() << " ";
}