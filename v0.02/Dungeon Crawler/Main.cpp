#include "stdafx.h"
#include "iostream"
#include "dc.h"

using namespace std;

int main()
{
	//Structs containing all the information of the game
	dimensions map;
	pos player;
	pos door;
	
	//Generates a starting map, player and door positions
	map = Gen::Map();
	player.y = (map.height - 1) / 2;
	player.x = (map.length - 1) / 2;
	door = Gen::Door(map);

	bool runnning = true;
	do {
		Print::Map(map, player, door);

		player = Player::Move(player, map);

		if (player.x == door.x && player.y == door.y) {
			map = Gen::Map();
			door = Gen::Door(map);
			player.y = (map.height - 1) / 2;
			player.x = (map.length - 1) / 2;
		}
	} while (runnning);

	cin.get();

    return 0;
}