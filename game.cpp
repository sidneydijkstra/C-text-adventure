// game.cpp

#include <iostream>
#include <string>

#include "game.h"

//#include "food.h"
//#include "weapon.h"

//  game constructor
Game::Game(){
	player = new Player();
	this->createRooms();
}

// game deconstructor
Game::~Game(){
	// delete all the rooms
	delete outside;
	delete theatre;
	delete pub;
	delete lab;
	delete office;

	// delete player
	delete player;
}

// create all the rooms
void Game::createRooms(){
	// create the rooms
	outside = new Room("outside the main entrance of the university");
	theatre = new Room("in a lecture theatre");
	pub = new Room("in the campus pub");
	lab = new Room("in a computing lab");
	office = new Room("in the computing admin office");

	Item* apple = new Item("apple", 10);
	Item* handgun = new Item("handgun", 10);

	outside->getInventory()->addItem("apple", apple);
	outside->getInventory()->addItem("handgun", handgun);

	// initialise room exits
	outside->setExit("east", theatre);
	outside->setExit("south", lab);
	outside->setExit("up", pub);

	theatre->setExit("west", outside);

	pub->setExit("down", outside);

	lab->setExit("north", outside);
	lab->setExit("east", office);

	office->setExit("west", lab);

	// set starting room
	player->setCurrentRoom(outside);
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
		// TEMP damage player on entering new room
		player->playerDamage(10);

		// set new room
		player->setCurrentRoom(nextRoom);
		std::cout << player->getCurrentRoom()->getLongDescription() << std::endl;
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
		std::cout << player->getCurrentRoom()->getLongDescription() << std::endl;
		std::cout << rand() % 100000 << std::endl;
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
