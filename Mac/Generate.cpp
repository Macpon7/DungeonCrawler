#include "stdafx.h"
#include "Generate.h"
#include <iostream>
#include <random>

//Function that generates a random door position on the outer edge of the map
Position Generate::door(Dimensions current)
{
	std::random_device rd;

	Position out;

	int iteration = rd() % 4;
	switch (iteration) {
	case 0:
		out.y = 0;
		out.x = rd() % (current.width - 1);
		break;
	case 1:
		out.y = (current.height - 1);
		out.x = rd() % (current.width - 1);
		break;
	case 2:
		out.y = rd() % (current.height - 1);
		out.x = 0;
		break;
	case 3:
		out.y = rd() % (current.height - 1);
		out.x = (current.width - 1);
		break;
	}
	return out;
}
//Function that generates a map of random-ish width and height
Dimensions Generate::map()
{
	std::random_device rd;

	Dimensions out;
	out.width = 11 + (rd() % 5);
	out.height = 5 + (rd() % 3);
	return out;
}

Position Generate::player(Dimensions current)
{
	Position out;
	out.y = (current.height - 1) / 2;
	out.x = (current.width - 1) / 2;
	return out;
}

Position Generate::enemy(Dimensions current)
{
	std::random_device rd;

	Position out;

	int iteration = rd() % 4;
	switch (iteration) {
	case 0:
		out.y = 1;
		out.x = 1 + rd() % (current.width - 3);
		break;
	case 1:
		out.y = (current.height - 2);
		out.x = 1 + rd() % (current.width - 3);
		break;
	case 2:
		out.y = 1 + rd() % (current.height - 3);
		out.x = 1;
		break;
	case 3:
		out.y = 1 + rd() % (current.height - 3);
		out.x = (current.width - 2);
		break;
	}
	return out;
}

/*
Stats Generate::EnemyStats()
{

}
*/