#include "stdafx.h"
#include "iostream"
#include "dc.h"
using namespace std;

//Function that prints the map, player and door
void Print::Map(dimensions current, pos player, pos door)
{
	system("CLS"); //Clears the console

	char ** map = new char *[current.height]; //Defines the map
	for (int i = 0; i < current.height; i++) {
		map[i] = new char[current.length];
	}

	for (int i = 0; i < current.height; i++) {
		for (int j = 0; j < current.length; j++) { //Fills the map with #
			map[i][j] = '#';
		}
	}

	map[door.y][door.x] = 'D'; //Places the foor on the map
	map[player.y][player.x] = 'P'; //Places the player on the map

	for (int i = 0; i < current.height; i++) {
		for (int j = 0; j < current.length; j++) { //Prints the map
			cout << map[i][j];
		}
		cout << "\n";
	}
}