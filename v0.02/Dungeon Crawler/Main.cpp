#include "stdafx.h"
#include "iostream"
#include "Structs.h"
#include "Player.h"
#include "Print.h"
#include "Generate.h"

using namespace std;

int main()
{
	Generate gen;
	Print print;
	Player p;
	
	//Structs containing all the information of the game
	dimensions map;
	pos player;
	pos door;
	
	//Generates a starting map, player and door positions
	map = gen.Map();
	player.y = (map.height - 1) / 2;
	player.x = (map.length - 1) / 2;
	door = gen.Door(map);

	bool runnning = true;
	do {
		print.Map(map, player, door);

		player = p.Move(player, map);

		if (player.x == door.x && player.y == door.y) {
			map = gen.Map();
			door = gen.Door(map);
			player.y = (map.height - 1) / 2;
			player.x = (map.length - 1) / 2;
		}
	} while (runnning);

	cin.get();

    return 0;
}