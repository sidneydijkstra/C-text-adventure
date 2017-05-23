
#include "player.h"

Player::Player(){
	maxHealth = 100;
	currentHealth = maxHealth;
}

Player::~Player(){
	// delete rooms
	delete outside;
	delete house;
	delete attic;
	delete basement;
	delete garden;
	delete roof;

	// delete items
	for (int i = 0; i < inventory.size(); i++){
		delete inventory[i];
	}
}

void Player::goRoom(std::string first = "", std::string second = ""){
	if (second.compare("") == 0) {
		std::cout << "Go where?" << std::endl;
		return;
	}

	// Try to leave current room.
	Room* nextRoom = currentRoom->getExit(second);

	if (nextRoom == NULL) {
		std::cout << "There is no door!" << std::endl;
	}else {
		currentRoom = nextRoom;
		std::cout << currentRoom->getLongDescription() << std::endl;
	}
}

void Player::damagePlayer(float dmg){
	if (currentHealth - dmg <= 0) {
		currentHealth = 0;
	}else {
		currentHealth -= dmg;
	}
}

void Player::healPlayer(float heal){
	if (currentHealth + heal >= maxHealth) {
		currentHealth = maxHealth;
	}else{
		currentHealth += heal;
	}
}

bool Player::addItem(std::string name){
	Item* item = currentRoom->takeItem(name);
	if (item != NULL) {
		inventory.push_back(item);
		return true;
	}else {
		return false;
	}
}

bool Player::dropItem(std::string name){
	for (int i = 0; i < inventory.size(); i++) {
		if (inventory[i]->getItemName().compare(name) == 0) {
			currentRoom->addItem(inventory[i]);
			inventory.erase(inventory.begin() + i);
			return true;
		}
	}
	return false;
}

std::string Player::getItemsInInventory(){
	std::string returnString = "Items: ";
	for (int i = 0; i < inventory.size(); i++) {
		returnString += "-" + inventory[i]->getItemName() + " ";
	}if (inventory.size() == 0) {
		returnString = "Nothing";
	}
	return returnString;
}

bool Player::canTakeItem(std::string name){
	Item* item = currentRoom->takeItem(name);
	currentRoom->addItem(item);
	float weight_ = item->getItemWeight();
	for (int i = 0; i < inventory.size(); i++){
		weight_ += inventory[i]->getItemWeight();
	}
	std::cout << weight_ << std::endl;
	if (item != NULL) {
		weight_ == item->getItemWeight();
		if (weight_ <= maxWeight) {
			return true;
		}else {
			return false;
		}
	}else {
		return true;
	}
}

std::string Player::getCurrentRoomDescription() {
	return currentRoom->getLongDescription();
}

std::string Player::getCurrentRoomItems() {
	return currentRoom->getItemString();
}

void Player::createRooms(){
	// create the rooms
	outside = new Room("outside the main entrance of the house.");
	house = new Room("inside the house.");
	attic = new Room("inside the attic.");
	basement = new Room("inside the basement.");
	garden = new Room("inside the garden.");
	roof = new Room("on top of the roof.");

	// initialise room exits
	outside->setExit("north", house);

	house->setExit("up", attic);
	house->setExit("down", basement);
	house->setExit("north", garden);
	house->setExit("south", outside);

	attic->setExit("down", house);
	attic->setExit("up", roof);

	basement->setExit("up", house);

	roof->setExit("down", attic);

	garden->setExit("south", house);

	Item* stick = new Item("stick", "A small stick that you might be able to eat.", 90);
	Item* sand = new Item("sand", "Some sand than can be made into glass with a big oven.", 25);
	outside->addItem(stick);
	outside->addItem(sand);

	this->currentRoom = outside;  // start game outside
}

