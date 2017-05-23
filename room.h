// room.h

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <map>
#include <string>
#include <vector>

#include "item.h"

class Room
{
public:
	Room(std::string desc);
	virtual ~Room();

	void setExit(std::string direction, Room* neighbor);
	Room* getExit(std::string direction);

	std::string getLongDescription() { return "You are " + description + '\n' + getExitString(); }
	std::string getExitString();

	// get all items in room
	std::string getItemString();

	// add new item to room
	void addItem(Item* item);
	// remove item from room
	Item* takeItem(std::string name);

private:
	std::string description;
	std::map<std::string, Room*> exits;

	std::vector<Item*> items;
};

#endif /* ROOM_H */
