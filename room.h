// room.h

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <map>

#include "inventory.h"

class Room
{
public:
	Room(std::string desc);
	virtual ~Room();

	void setExit(std::string direction, Room* neighbor);
	Room* getExit(std::string direction);

	std::string getLongDescription() { return "You are " + description + '\n' + getExitString(); }
	std::string getExitString();

	// get the inventory
	Inventory* getInventory() { return _inventory; };

private:
	std::string description;
	std::map<std::string, Room*> exits;

	Inventory* _inventory;
};

#endif /* ROOM_H */
