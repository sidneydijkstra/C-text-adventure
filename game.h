// game.h

#ifndef GAME_H
#define GAME_H

#include <string>

#include "parser.h"
#include "command.h"
#include "player.h"

class Game
{
public:
	Game();
	virtual ~Game();

	void play();

private:
	bool processCommand(Command cmd);
	void printWelcome();
	void printHelp();

	Parser parser;
	Player* player;

	std::vector<std::string> infentory;
};

#endif /* GAME_H */
