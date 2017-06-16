// room.h

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "inventory.h"
#include "item.h"

class Room{
public:
	Room(std::string desc);
	virtual ~Room();

	// room exit set and get functions
	void setExit(std::string direction, Room* neighbor);
	Room* getExit(std::string direction);
	std::vector<Room*> getClosedRooms();

	// room string functions
	std::string getLongDescription() { return "You are " + _description + '\n' + getExitString(); }
	std::string getExitString();

	// get the inventory
	Inventory* getInventory() { return _inventory; };

	// door open and close functions
	bool isOpen() { return _isOpen; };
	void closeRoom() { _isOpen = false; };
	void openRoom() { _isOpen = true; };

	// door key functions
	void addOpenKey(Item* _key) { _keys.push_back(_key); };

	// check if can open door then open door
	void canOpen(Item* _key);
private:
	// room description and exits
	std::string _description;
	std::map<std::string, Room*> _exits;

	// room inventory
	Inventory* _inventory;

	// key variables
	bool _isOpen = true;
	std::vector<Item*> _keys;
};

#endif /* ROOM_H */
