#include <iostream>
#include <string>

#include "Joker.h"

Joker::Joker(std::string n, int h, int s, int lv) {
	name = n;
	maxHp = h;
	hp = maxHp;
	maxShield = s;
	shield = maxShield;
	level = lv;
}

void Joker::takeDamage(int damage, std::string handType) {

	// instant break shield if Big Three
	if(handType == "Big Three" && shield > 0){
		shield = 0;
		std::cout << "Break Shield! ";
	}

	if (shield > 0) {
		if (damage >= shield) {
			damage -= shield;
			shield = 0;
			std::cout << "Break Shield! ";
		}
		else {
			shield -= damage;
			std::cout << "Dealing " << damage << " to Shield!\n";
			damage = 0;
		}
	}

	hp -= damage;
	std::cout << "Dealing " << damage << " damage to Joker!";

	if (hp < 0) {
		hp = 0;
	}
}

bool Joker::isDead() const {
	return hp <= 0;
}

void Joker::displayJoker() const {
	std::cout << std::string(20, '=');
	std::cout << "\n(Lv." << level << ") " << "Joker " << name << "\n";
	std::cout << "Shield: " << shield << "/" << maxShield << "\n";
	std::cout << "HP: " << hp << "/" << maxHp << "\n\n";
}

int Joker::getHp() const {
	return hp;
}

void Joker::spawnJoker() {
	int randomJoker = rand() % 3 + 1;

	switch (randomJoker) {
	case 1:
		name = "B";
		maxHp = 50 * level;
		maxShield = 50;
		break;
	case 2:
		name = "C";
		maxHp = 50;
		maxShield = 50 * level;
		break;
	case 3:
		name = "D";
		maxHp = 1;
		maxShield = 999;
		break;
	}
	hp = maxHp;
	shield = maxShield;
}

void Joker::jokerLvUp() {
	level++;
}