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

void DungeonRoom::init() {
	Generate gen;
	dim = gen.map();
	door = gen.door(dim);
	player = gen.player(dim);
	enemy = gen.enemy(dim);

	createRoom();
}

DungeonRoom::DungeonRoom() {
	init();
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
}
void DungeonRoom::displayRoom() {
#ifndef __APPLE__
	std::system("CLS"); //Clears the console
#else
    std::system("clear"); //Clears the console
#endif
	fillRoom(); //Fills the map with '#'
	setDoorPosition(); //Places the door
	setEnemyPosition(); //Places the enemy
	setPlayerPosition(); //Places the player
	
	for (std::size_t i = 0; i < map.size(); i++) {
		for (std::size_t j = 0; j < map[0].size(); j++) { //Prints the map
			std::cout << map[i][j];
		}
		std::cout << "\n";
	}
}

void DungeonRoom::movePlayerLeft() {
	player.x--;
}
void DungeonRoom::movePlayerRight() {
	player.x++;
}
void DungeonRoom::movePlayerUp() {
	player.y--;
}
void DungeonRoom::movePlayerDown() {
	player.y++;
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
void DungeonRoom::setPlayerPosition() {
	map[player.y][player.x] = 'P';
}

Position DungeonRoom::doorPosition() {
	return door;
}
void DungeonRoom::setDoorPosition() {
	map[door.y][door.x] = 'D';
}

Position DungeonRoom::enemyPosition() {
	return enemy;
}
void DungeonRoom::setEnemyPosition() {
	Combat combat;
	if (combat.enemyIsAlive())
		map[enemy.y][enemy.x] = 'E';
	if (!combat.enemyIsAlive())
		map[enemy.y][enemy.x] = 'X';
}

Dimensions DungeonRoom::roomDimensions() {
	return dim;
}
