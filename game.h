// game.h

#ifndef GAME_H
#define GAME_H

#include <string>

#include "parser.h"
#include "command.h"
#include "room.h"
#include "player.h"
#include "inventory.h"
#include "item.h"

class Game{
public:
	Game();
	virtual ~Game();

	// main play function
	void play();

private:
	// game funtions
	void goRoom(Command command);
	void createRooms();
	bool processCommand(Command cmd);
	void printWelcome();
	void printHelp();

	// player
	Player* player;

	// parser
	Parser parser;

	// rooms
	Room* bedroom; // room 1
	Room* closet; // room 2 
	Room* hallway; // room 3
	Room* yard; // room 4
};

#endif /* GAME_H */
