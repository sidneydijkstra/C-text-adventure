// game.cpp

#include <iostream>
#include <string>

#include "game.h"

#include "food.h"
#include "key.h"

//  game constructor
Game::Game(){
	player = new Player();
	this->createRooms();
}

// create all the rooms
void Game::createRooms(){
	// create the rooms
	bedroom = new Room("in the bedroom where you woke up.");
	closet = new Room("inside the closed. Why?");
	hallway = new Room("in the hallway. No windows, strange.");
	yard = new Room("in the yard its realy dark. So dark i can not even see the stars.");

	// initialise room exits
	bedroom->setExit("east", closet);
	bedroom->setExit("south", hallway);

	closet->setExit("west", bedroom);

	hallway->setExit("north", bedroom);
	hallway->setExit("south", yard);

	yard->setExit("north", hallway);


	// add food to bedroom
	Food* apple = new Food(player, "apple", "A not so good looking apple.", 10, 20);
	bedroom->getInventory()->addItem("apple", apple);


	// close the yard
	Key* yardkey = new Key(player, "yardkey", "A key that from the looks of it might open the door to the yard.", 5);
	closet->getInventory()->addItem("yardkey", yardkey);
	yard->addOpenKey(yardkey);
	yard->closeRoom();

	// set starting room
	player->setCurrentRoom(bedroom);
}

// main play function
void Game::play(){
	this->printWelcome();

	bool finished = false;
	while ( !finished ) {
		Command command = parser.getCommand();
		finished = processCommand(command);
	}
	std::cout << "Thank you for playing. Goodbye!" << std::endl;
}

// go to a new room
void Game::goRoom(Command cmd){
	// check there is a second command
	if(!cmd.hasSecondWord()) {
		std::cout << "Go where?" << std::endl;
		return;
	}

	// get the second word
	std::string direction = cmd.getSecondWord();

	// try to get the room the player calld
	Room* nextRoom = player->getCurrentRoom()->getExit(direction);

	// check if the room exist and then go to it
	if (nextRoom == NULL) {
		std::cout << "There is no door!" << std::endl;
	} else {
		if (nextRoom->isOpen()) {
			// set new room
			player->setCurrentRoom(nextRoom);
			std::cout << player->getCurrentRoom()->getLongDescription() << std::endl;
		}else {
			// MESSAGE: door is closed
			std::cout << "You cant go trough that door becaus its is closed" << std::endl;
		}
	}
}

// process a command
bool Game::processCommand(Command cmd){
	bool wantToQuit = false;

	if(cmd.isUnknown()) {
		std::cout << "I don't know what you mean..." << std::endl;
		return false;
	}

	std::string commandWord = cmd.getCommandWord();

	if (commandWord.compare("help") == 0) {
		this->printHelp();
	}
	else if (commandWord.compare("look") == 0) {
		if (cmd.hasSecondWord()) {
			// display info of item
			if (player->getInventory()->getItem(cmd.getSecondWord()) != NULL) {
				std::cout << player->getInventory()->getItem(cmd.getSecondWord())->getItemDescription() << std::endl;
			}else {
				// MESSAGE: not an item in inv
				std::cout << "That is not an item in you bag." << std::endl;
			}
		}else {
			// display description of room and exits
			std::cout << player->getCurrentRoom()->getLongDescription() << std::endl;
		}
	}
	else if (commandWord.compare("take") == 0) {
		player->getInventory()->take(cmd.getSecondWord(), player->getCurrentRoom()->getInventory());
	}
	else if (commandWord.compare("drop") == 0) {
		player->getInventory()->drop(cmd.getSecondWord(), player->getCurrentRoom()->getInventory());
	}
	else if (commandWord.compare("search") == 0) {
		std::cout << "You look around and find: " << player->getCurrentRoom()->getInventory()->getAllItemNames() << std::endl;
	}
	else if (commandWord.compare("bag") == 0) {
		std::cout << "You look in your bag and find: " << player->getInventory()->getAllItemNames() << std::endl;
	}
	else if (commandWord.compare("use") == 0) {
		if (player->getInventory()->getItem(cmd.getSecondWord()) != NULL) player->getInventory()->getItem(cmd.getSecondWord())->use();
	}
	else if (commandWord.compare("stats") == 0) {
		std::vector<std::string> _string = player->getPlayerStats();
		std::cout << "--- stats ---" << std::endl;
		for (int i = 0; i < _string.size(); i++) {
			std::cout << _string[i] << std::endl;
		}
		std::cout << "--- ----- ---" << std::endl;
	}
	else if (commandWord.compare("go") == 0) {
		this->goRoom(cmd);
	} 
	else if (commandWord.compare("quit") == 0) {
		//wantToQuit = quit(command);
		wantToQuit = true;
	}

	return wantToQuit;
}

// print welcome message
void Game::printWelcome(){
	std::cout << std::endl;
	std::cout << "Welcome to my text adventure!" << std::endl;
	std::cout << "My text adventure is awsome!" << std::endl;
	std::cout << "Type 'help' if you need help." << std::endl;
	std::cout << std::endl;
	std::cout << player->getCurrentRoom()->getLongDescription() << std::endl;
}

// print help message
void Game::printHelp(){
	std::cout << "You are lost. You are alone. You wander" << std::endl;
	std::cout << "around at a random place." << std::endl;
	std::cout << std::endl;
	std::cout << "Your command words are:" << std::endl;
	parser.showCommands();
}

// game deconstructor
Game::~Game() {
	// delete all the rooms
	delete bedroom;
	delete closet;
	delete hallway;
	delete yard;

	// delete player
	delete player;
}
