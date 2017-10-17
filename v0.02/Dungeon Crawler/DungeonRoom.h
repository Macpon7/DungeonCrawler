#pragma once
#include "stdafx.h"
#include "Structs.h"
#include <vector>

class DungeonRoom {
public:
	void init();									//Initialize with random room size

	DungeonRoom();

	void createRoom();
	void fillRoom();
	void displayRoom();								//Prints room to std output

	void movePlayerLeft();
	void movePlayerRight();
	void movePlayerUp();
	void movePlayerDown();

	bool playerIsAtDoor();
	bool playerIsOnEnemy();

	Position playerPosition();
	void setPlayerPosition();

	Position doorPosition();
	void setDoorPosition();

	Position enemyPosition();
	void setEnemyPosition();

	Dimensions roomDimensions();
private:
	std::vector<std::vector<char>> map;
	Dimensions dim;
	Position player;
	Position door;
	Position enemy;
};