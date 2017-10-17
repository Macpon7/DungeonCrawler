#include "stdafx.h"
#include "stdafx.h"
#include "DungeonRoom.h"
#include "Combat.h"
#include <conio.h>
#include <iostream>

using namespace std;

int main()
{
	DungeonRoom room; //When DungeonRoom is called, init(); is performed
	Combat combat; //When Combat is called, init(); is performed
	
	bool running = true;
	do {
		room.displayRoom();

		bool moved = false;
		while (!moved) {
			if (_getch() == 224) {
				switch (_getch()) {
				case 75: //Arrow left
					if (room.playerPosition().x != 0) {
						room.movePlayerLeft();
						moved = true;
					}
					break;
				case 77: //Arrow right
					if (room.playerPosition().x != room.roomDimensions().width - 1) {
						room.movePlayerRight();
						moved = true;
					}
					break;
				case 72: //Arrow up
					if (room.playerPosition().y != 0) {
						room.movePlayerUp();
						moved = true;
					}
					break;
				case 80: //Arrow down
					if (room.playerPosition().y != room.roomDimensions().height - 1) {
						room.movePlayerDown();
						moved = true;
					}
					break;
				}
			}
		}

		if (room.playerIsOnEnemy()) {
			combat.init();
			combat.battle();
		}
		if (room.playerIsAtDoor()) {
			room.init();
		}
	} while (running);

	cin.get();

    return 0;
}