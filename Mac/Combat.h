#pragma once
#include "stdafx.h"
#include "Structs.h"

class Combat {
public:
	void init();

	void battle();

	bool playerIsAlive();
	bool enemyIsAlive();
private:
	Stats player;
	Stats enemy;
	bool playerAlive;
	bool enemyAlive;
};