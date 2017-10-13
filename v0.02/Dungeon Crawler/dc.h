#pragma once

struct dimensions {
	int length;
	int height;
};
struct pos {
	int x;
	int y;
};

namespace Gen { //Every function that generates anything goes here and in gen.cpp
	pos Door(dimensions current);
	dimensions Map();
}

namespace Print { //Every function that prints anything goes here and in print.cpp
	void Map(dimensions current, pos player, pos door);
}

namespace Player { //Every function that has to do with the player goes here and in player.cpp
	pos Move(pos player, dimensions map);
}