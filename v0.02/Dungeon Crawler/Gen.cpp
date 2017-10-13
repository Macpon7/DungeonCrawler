#include "stdafx.h"
#include "iostream"
#include "dc.h"

//Function that generates a random door position on the outer edge of the map
pos Gen::Door(dimensions current)
{
	pos out;

	int iteration = rand() % 4;
	switch (iteration) {
	case 0:
		out.y = 0;
		out.x = rand() % (current.length - 1);
		break;
	case 1:
		out.y = (current.height - 1);
		out.x = rand() % (current.length - 1);
		break;
	case 2:
		out.y = rand() % (current.height - 1);
		out.x = 0;
		break;
	case 3:
		out.y = rand() % (current.height - 1);
		out.x = (current.length - 1);
		break;
	}
	return out;
}
//Function that generates a map of random-ish length and height
dimensions Gen::Map()
{
	dimensions out;
	out.length = rand() % 5 + 7;
	out.height = rand() % 3 + 5;
	return out;
}