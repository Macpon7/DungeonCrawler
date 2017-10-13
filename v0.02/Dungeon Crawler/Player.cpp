#include "stdafx.h"
#include "iostream"
#include "Player.h"
#include "conio.h"

using namespace std;

//Function that prompts the player to move in a direction
	
pos Player::Move(pos player, dimensions map)
{
	bool moved = false;
	while (!moved) {
		if (_getch() == 224) {
			switch (_getch()) {
			case 72: //Arrow up
				if (player.y != 0) {
					player.y--;
					moved = true;
				}
				break;
			case 80: //Arrow down
				if (player.y != map.height - 1) {
					player.y++;
					moved = true;
				}
				break;
			case 77: //Arrow right
				if (player.x != map.length - 1) {
					player.x++;
					moved = true;
				}
				break;
			case 75: //Arrow left
				if (player.x != 0) {
					player.x--;
					moved = true;
				}
				break;
			}
		}
	}
	return player;
}