#include "stdafx.h"
#include "iostream"
#include "random"
#include "Generate.h"

//Function that generates a random door position on the outer edge of the map
pos Generate::Door(dimensions current)
{
	std::random_device rd;

	pos out;

	int iteration = rd() % 4;
	switch (iteration) {
	case 0:
		out.y = 0;
		out.x = rd() % (current.length - 1);
		break;
	case 1:
		out.y = (current.height - 1);
		out.x = rd() % (current.length - 1);
		break;
	case 2:
		out.y = rd() % (current.height - 1);
		out.x = 0;
		break;
	case 3:
		out.y = rd() % (current.height - 1);
		out.x = (current.length - 1);
		break;
	}
	return out;
}
//Function that generates a map of random-ish length and height
dimensions Generate::Map()
{
	std::random_device rd;

	dimensions out;
	out.length = 11 + (rd() % 5);
	out.height = 5 + (rd() % 3);
	return out;
}

pos Generate::Rock(dimensions current, pos player, pos door)
{
	std::random_device rd;

	pos out;
	do {
		out.x = rd() % (current.length - 1);
		out.y = rd() % (current.height - 1);
	} while ((out.x == player.x && out.y == player.y) || (out.y == door.y && out.x == door.x));
	return out;
}