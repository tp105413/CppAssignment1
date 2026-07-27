#pragma once

#include <string>

class Joker {
private:
	std::string name;
	int hp;
	int maxHp;
	int shield;
	int maxShield;
	int level = 1;

public:
	Joker(std::string n, int h, int s, int lv);
	void takeDamage(int damage, std::string handType);
	bool isDead() const;
	void displayJoker() const;
	int getHp() const;
	void spawnJoker();
	void jokerLvUp();
};