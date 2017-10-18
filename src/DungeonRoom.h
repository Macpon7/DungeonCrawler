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

	bool hasPlayerActed();
	void setPlayerActed(bool in);

	void checkPlayerBlock();
	bool playerIsAtDoor();
	bool playerIsOnEnemy();

	Position playerPosition();
	void setPlayerPosition(Position in);

	Position doorPosition();
	void setDoorPosition(Position in);

	Position enemyPosition();
	void setEnemyPosition(Position in);

	Dimensions roomDimensions();
private:
	std::vector<std::vector<char>> map;
	std::vector<bool> playerBlocked;
	bool playerActed;
	Dimensions dim;
	Position player;
	Position door;
	Position enemy;
};