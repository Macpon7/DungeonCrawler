#include "stdafx.h"
#include "Combat.h"
#include "Structs.h"
#ifndef __APPLE__
#include <conio.h>
#else
#include <ncurses.h>
#define _getch getchar
#endif
#include <random>
#include <iostream>

void Combat::init() {
	player = { "Player", 20, 13, 3, 4 };
	enemy = { "Orc", 12, 10, 4, 4 };
	playerAlive = true;
	enemyAlive = true;
}

void Combat::battle() {
	bool fighting = true;
	std::random_device rd;
#ifndef __APPLE__
	std::system("CLS");
#else
	std::system("clear");
#endif
	do {
		//Prints the player health, enemy health, and actions the player can take
		std::cout << "\n" << player.name << ": " << player.health << " HP\n"
			<< enemy.name << ": " << enemy.health << "HP\n"
			<< "1: Attack " << enemy.name << "\n"
			<< "2: Flee\n\n";

		bool acted = false;
		while (!acted) {
			//Waits for key input
			if (_getch() == '1') { //If the player presses 1 
				if ((rd() % 20) + player.attack >= enemy.defense) {
					std::cout << "You hit " << enemy.name << " for " << player.damage << " damage.\n";
					enemy.health -= player.damage;
					if (enemy.health <= 0) { //Checks to see if enemy is dead
						std::cout << "You killed " << enemy.name << ".\n";
						fighting = false;
						enemyAlive = false;
					}
				}
				else {
					std::cout << "You missed.\n";
				}
				if (fighting) { //If still fighting, enemy atacks
					if ((rd() % 20) + enemy.attack >= player.defense) {
						std::cout << enemy.name << " hit you for " << enemy.damage << " damage.\n";
						player.health -= enemy.damage;
						if (player.health <= 0) { //Checks to see if player is dead
							std::cout << "You died";
							fighting = false;
							playerAlive = false;
						}
					}
					else {
						std::cout << enemy.name << " missed.\n";
					}
				}
				acted = true;
			}
			else if (_getch() == '2') { //If the player presses 2
				std::cout << "You ran away from " << enemy.name << ".\n";
				acted = true;
				fighting = false;
			}
		}
	} while (fighting);
	std::system("pause");
}

bool Combat::playerIsAlive() { //Returns true if the player is alive
	return playerAlive;
}
bool Combat::enemyIsAlive() { //Returns true if the enemy is alive
	return enemyAlive;
}
