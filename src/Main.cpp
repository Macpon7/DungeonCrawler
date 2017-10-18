#include "stdafx.h"
#include "stdafx.h"
#include "DungeonRoom.h"
#include "Combat.h"
#ifndef __APPLE__
#include <conio.h>
#else
#include <stdio.h>
#include <unistd.h>
#include <termios.h>
#define _getch getchar
#endif
#include <iostream>

using namespace std;

int main()
{
#ifdef __APPLE__
    struct termios old_tio, new_tio;
    unsigned char c;
    
    /* get the terminal settings for stdin */
    tcgetattr(STDIN_FILENO,&old_tio);
    
    /* we want to keep the old setting to restore them a the end */
    new_tio=old_tio;
    
    /* disable canonical mode (buffered i/o) and local echo */
    new_tio.c_lflag &=(~ICANON & ~ECHO);
    
    /* set the new settings immediately */
    tcsetattr(STDIN_FILENO,TCSANOW,&new_tio);
#endif
    
    
    DungeonRoom room; //When DungeonRoom is called, init(); is performed
    Combat combat; //When Combat is called, init(); is performed
    
    
#ifndef __APPLE__
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
    
#else
    bool running = true;
    do {
        room.displayRoom();
        
        bool moved = false;
        while (!moved) {
            switch (_getch()) {
                case 'a': //Arrow left
                    if (room.playerPosition().x != 0) {
                        room.movePlayerLeft();
                        moved = true;
                    }
                    break;
                case 's': //Arrow right
                    if (room.playerPosition().x != room.roomDimensions().width - 1) {
                        room.movePlayerRight();
                        moved = true;
                    }
                    break;
                case 'w': //Arrow up
                    if (room.playerPosition().y != 0) {
                        room.movePlayerUp();
                        moved = true;
                    }
                    break;
                case 'z': //Arrow down
                    if (room.playerPosition().y != room.roomDimensions().height - 1) {
                        room.movePlayerDown();
                        moved = true;
                    }
                    break;
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
    
#endif
    
    cin.get();
    
    return 0;
}
