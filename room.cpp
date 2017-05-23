// room.cpp

#include "room.h"

Room::Room(std::string desc)
{
	this->description = desc;
}

Room::~Room(){
	// delete items
	for (int i = 0; i < items.size(); i++)
	{
		delete items[i];
	}
}

void Room::setExit(std::string direction, Room* neighbor)
{
	exits[direction] = neighbor;
}

Room* Room::getExit(std::string direction)
{
	if (exits.find(direction) != exits.end()) {
		return exits[direction];
	}
	return NULL;
}

std::string Room::getExitString(){
	std::string returnString = "Exits: ";
	std::map<std::string,Room*>::iterator it = exits.begin();
	while (it != exits.end()) {
		returnString += it->first;
		returnString += " ";
		++it;
	}

	return returnString;
}

std::string Room::getItemString() {
	std::string returnString = "Items: ";
	for (int i = 0; i < items.size(); i++){
		returnString += items[i]->getItemName() + " ";
	}
	if (items.size() == 0) {
		returnString = "Nothing";
	}
	return returnString;
}

void Room::addItem(Item * item){
	items.push_back(item);
}

Item* Room::takeItem(std::string name){
	for (int i = 0; i < items.size(); i++){
		if (items[i]->getItemName().compare(name) == 0) {
			Item* item = items[i];
			items.erase(items.begin() + i);
			return item;
		}
	}
	return NULL;
}



