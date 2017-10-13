#include "stdafx.h"
#include "iostream"
#include "dc.h"
using namespace std;

//Function that prompts the player to move in a direction
pos Player::Move(pos player, dimensions map)
{
	char command; //What the player wants to do
	cout << "\nWhat direction do you want to move? (u, d, l, r)\n:";
	cin >> command;
	switch (command) { //Moves the player in the direction they typed
	case 'u': {
		if (player.y != 0) {
			player.y--;
		}
		else {
			cout << "Invalid move.\n";
			system("pause");
		}
		break;
	}
	case 'd': {
		if (player.y != (map.height - 1)) {
			player.y++;
		}
		else {
			cout << "Invalid move.\n";
			system("pause");
		}
		break;
	}
	case 'r': {
		if (player.x != (map.length - 1)) {
			player.x++;
		}
		else {
			cout << "Invalid move.\n";
			system("pause");
		}
		break;
	}
	case 'l': {
		if (player.x != 0) {
			player.x--;
		}
		else {
			cout << "Invalid move.\n";
			system("pause");
		}
		break;
	}
	default: {
		cout << "Unknown command.\n";
		system("pause");
	}
	}
	return player;
}
