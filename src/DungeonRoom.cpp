#include "stdafx.h"
#include "DungeonRoom.h"
#include "Generate.h"
#include "Combat.h"
#include <iostream>

#ifdef __APPLE__
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#endif

DungeonRoom::DungeonRoom() {
	init();
}

void DungeonRoom::init() {
	Generate gen;
	dim = gen.map();
	door = gen.door(dim);
	player = gen.player(dim);
	enemy = gen.enemy(dim);
	playerBlocked.assign(4, false);

	createRoom();
}

void DungeonRoom::createRoom() {
	map.resize(dim.height);
	for (int i = 0; i < dim.height; i++) {
		map[i].resize(dim.width, '#');
	}
}
void DungeonRoom::fillRoom() {
	for (std::size_t i = 0; i < map.size(); i++) {
		for (std::size_t j = 0; j < map[0].size(); j++) { //Fills the map with '#'
			map[i][j] = '#';
		}
	}
	map[door.y][door.x] = 'D';		//Places the door, enemy, and player on the map
	map[enemy.y][enemy.x] = 'E';
	map[player.y][player.x] = 'P';
}
void DungeonRoom::displayRoom() {
#ifndef __APPLE__
	std::system("CLS"); //Clears the console
#else
	std::system("clear"); //Clears the console
#endif
	fillRoom(); //Fills the map with '#'

	for (std::size_t i = 0; i < map.size(); i++) {
		for (std::size_t j = 0; j < map[0].size(); j++) { //Prints the map
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}
}

void DungeonRoom::movePlayerUp() {
	if (!playerBlocked[0]) {
		player.y--;
		playerActed = true;
	}
}
void DungeonRoom::movePlayerRight() {
	if (!playerBlocked[1]) {
		player.x++;
		playerActed = true;
	}
}
void DungeonRoom::movePlayerDown() {
	if (!playerBlocked[2]) {
		player.y++;
		playerActed = true;
	}
}
void DungeonRoom::movePlayerLeft() {
	if (!playerBlocked[3]) {
		player.x--;
		playerActed = true;
	}
}

bool DungeonRoom::hasPlayerActed() {
	return playerActed;
}
void DungeonRoom::setPlayerActed(bool in) {
	playerActed = in;
}

void DungeonRoom::checkPlayerBlock() {
	//Checks if the player is blocked by walls
	if (player.y - 1 < 0) playerBlocked[0] = true; //Above the player
	else playerBlocked[0] = false;

	if (player.x + 2 > map[0].size()) playerBlocked[1] = true; //To the right of the player
	else playerBlocked[1] = false;

	if (player.y + 2 > map.size()) playerBlocked[2] = true; //Below the player
	else playerBlocked[2] = false;

	if (player.x - 1 < 0) playerBlocked[3] = true; //To the left of the player
	else playerBlocked[3] = false;
}

bool DungeonRoom::playerIsAtDoor() {
	if (player.x == door.x && player.y == door.y)
		return true;
	else
		return false;
}
bool DungeonRoom::playerIsOnEnemy() {
	if (player.x == enemy.x && player.y == enemy.y)
		return true;
	else
		return false;
}

Position DungeonRoom::playerPosition() {
	return player;
}
void DungeonRoom::setPlayerPosition(Position in) {
	player.x = in.x;
	player.y = in.y;
}

Position DungeonRoom::doorPosition() {
	return door;
}
void DungeonRoom::setDoorPosition(Position in) {
	map[door.y][door.x] = 'D';
}

Position DungeonRoom::enemyPosition() {
	return enemy;
}
void DungeonRoom::setEnemyPosition(Position in) {
	enemy.x = in.x;
	enemy.y = in.y;
}

Dimensions DungeonRoom::roomDimensions() {
	return dim;
}