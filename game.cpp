// game.cpp

#include <iostream>
#include <string>

#include "game.h"

Game::Game(){
	player = new Player();
	player->createRooms();
}

Game::~Game(){
	// delete player
	delete player;
}

void Game::play(){
	this->printWelcome();

	bool finished = false;
	while ( !finished ) {
		Command command = parser.getCommand();
		finished = processCommand(command);
	}
	std::cout << "Thank you for playing. Goodbye!" << std::endl;
}


bool Game::processCommand(Command cmd){
	bool wantToQuit = false;

	if(cmd.isUnknown()) {
		std::cout << "I don't know what you mean..." << std::endl;
		return false;
	}

	std::string commandWord = cmd.getCommandWord();
	// on help
	if (commandWord.compare("help") == 0) { 
		this->printHelp();
	} 
	// on go
	else if (commandWord.compare("go") == 0) { 
		player->goRoom(cmd.getCommandWord(), cmd.getSecondWord());
	} 
	// on quit
	else if (commandWord.compare("quit") == 0) { 
		///wantToQuit = quit(command);
		wantToQuit = true;
	}
	// on look
	else if (commandWord.compare("look") == 0) { 
		std::cout << "You look around you and see that" << std::endl;
		std::cout << player->getCurrentRoomDescription() << std::endl;
	}
	// on search
	else if (commandWord.compare("search") == 0) { 
		std::cout << "You search around and found:" << std::endl;
		std::cout << player->getCurrentRoomItems() << std::endl;
	}
	// on inf
	else if (commandWord.compare("inv") == 0) {
		std::cout << "You look in your bag and find:" << std::endl;
		std::cout << player->getItemsInInventory() << std::endl;
	}
	// on take
	else if (commandWord.compare("take") == 0) { 
		if (player->canTakeItem(cmd.getSecondWord())) {
			if (player->addItem(cmd.getSecondWord())) {
				std::cout << "You took a " << cmd.getSecondWord() << ", nice!" << std::endl;
			}else {
				std::cout << "You can not take something that is not around you." << std::endl;
			}
		}else {
			std::cout << "You can not take that item its to heavy." << std::endl;
		}
	}
	// on drop
	else if (commandWord.compare("drop") == 0) { 
		if (player->dropItem(cmd.getSecondWord())) {
			std::cout << "You drop a " << cmd.getSecondWord() << " in this room, nice!" << std::endl;
		}else {
			std::cout << "You can not drop something that you dont have." << std::endl;
		}
	}

	return wantToQuit;
}

void Game::printWelcome(){
	std::cout << std::endl;
	std::cout << "Welcome to Zuul!" << std::endl;
	std::cout << "Zuul is a new, incredibly boring adventure game." << std::endl;
	std::cout << "Type 'help' if you need help." << std::endl;
	std::cout << std::endl;
}

void Game::printHelp(){
	std::cout << "You are lost. You are alone. You wander" << std::endl;
	std::cout << "around at a random house you found." << std::endl;
	std::cout << std::endl;
	std::cout << "Your command words are:" << std::endl;
	parser.showCommands();
}
