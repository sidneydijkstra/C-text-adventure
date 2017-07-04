/**
* @file game.h
*
* @brief The Game header file.
*
*/

#ifndef GAME_H
#define GAME_H

#include <string>

#include "parser.h"
#include "command.h"
#include "room.h"
#include "player.h"
#include "inventory.h"
#include "item.h"

/**
* @brief The Game class is the main class of the project
*/
class Game{
public:
	Game(); ///< @brief Constructor of the Game
	virtual ~Game(); ///< @brief Destructor of the Game

	/// @brief the main play function
	/// @return void
	void play();

	/// @brief go to a new room
	/// @param the current command
	/// @return void
	void goRoom(Command command);

	/// @brief create all the rooms
	/// @return void
	void createRooms();

	/// @brief process a command
	/// @param the current command
	/// @return void
	bool processCommand(Command cmd);

	/// @brief print the welcom message
	/// @return void
	void printWelcome();

	/// @brief print the help message
	/// @return void
	void printHelp();

private:

	Player* player; ///< @brief the player pointer

	Parser parser; ///< @brief the parser pointer

	Room* bedroom; ///< @brief the bedroom pointer
	Room* closet; ///< @brief the closet pointer
	Room* hallway; ///< @brief the hallway pointer
	Room* yard; ///< @brief the yard pointer
};

#endif /* GAME_H */
