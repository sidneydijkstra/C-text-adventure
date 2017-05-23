
#include "game.h"

int main()
{
	Game* game = new Game();;
	game->play();

	// delete game
	delete game;

	return 0;
}
