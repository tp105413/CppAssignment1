#pragma once

#include <string>

class Joker {
private:
	std::string name;
	int hp;
	int shield;

public:
	Joker(std::string n, int h, int s);
};