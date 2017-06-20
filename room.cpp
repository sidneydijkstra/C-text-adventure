// room.cpp

#include "room.h"

// room constructor
Room::Room(std::string desc){
	_inventory = new Inventory(0);
	this->_description = desc;
}

// room set new exit
void Room::setExit(std::string direction, Room* neighbor){
	_exits[direction] = neighbor;
}

// room get exit
Room* Room::getExit(std::string direction){
	if (_exits.find(direction) != _exits.end()) {
		return _exits[direction];
	}
	return NULL;
}

// get all the rooms that are closed
std::vector<Room*> Room::getClosedRooms(){
	std::vector<Room*> _rooms;
	std::map<std::string, Room*>::iterator _iterator = _exits.begin();
	while (_iterator != _exits.end()) {
		if (!_iterator->second->isOpen()) {
			_rooms.push_back(_iterator->second);
		}
		++_iterator;
	}
	return _rooms;
}

// room get exit string
std::string Room::getExitString(){
	std::string returnString = "Exits: ";
	std::map<std::string,Room*>::iterator it = _exits.begin();
	while (it != _exits.end()) {
		returnString += it->first;
		returnString += " ";
		++it;
	}

	return returnString;
}

// check if can open door then open door
void Room::canOpen(Item* _key){
	for (Item* key : _keys){
		if (key == _key) {
			// MESSAGE: you can open door
			std::cout << "You used your key and opend the door." << std::endl;

			this->openRoom();
			return;
		}
	}
	// MESSAGE: you can't open door
	std::cout << "You do not have the right key." << std::endl;
}

// room deconstructor
Room::~Room() {

}
