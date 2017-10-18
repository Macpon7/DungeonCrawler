#pragma once
#include "stdafx.h"
#include <string>

struct Dimensions {
	int width;
	int height;
};
struct Position {
	int x;
	int y;
};
struct Stats {
	std::string name;
	int health;
	int defense;
	int attack;
	int damage;
};