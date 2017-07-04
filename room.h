// room.h

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "inventory.h"
#include "item.h"
#include "person.h"

class Room{
public:
	Room(std::string desc);
	virtual ~Room();

	// ************ room exits functions ************
	// room exit set and get functions
	void setExit(std::string direction, Room* neighbor);
	Room* getExit(std::string direction);
	std::vector<Room*> getClosedRooms();

	// room string functions
	std::string getLongDescription() { return "You are " + _description + '\n' + getExitString(); }
	std::string getExitString();

	// ************ room inventory functions ************
	// get the inventory
	Inventory* getInventory() { return _inventory; };

	// ************ room key functions ************
	// door open and close functions
	bool isOpen() { return _isOpen; };
	void closeRoom() { _isOpen = false; };
	void openRoom() { _isOpen = true; };

	// door key functions
	void addOpenKey(Item* _key) { _keys.push_back(_key); };

	// check if can open door then open door
	void canOpen(Item* _key);

	// ************ room person functions ************
	void addPerson(Person* _person) { _persons.push_back(_person); };
	void removePerson(Person* _person);

	std::vector<Person*> getAllPersons() { return _persons; };
	Person* getPerson(std::string _name);
private:
	// room description and exits
	std::string _description;
	std::map<std::string, Room*> _exits;

	// room inventory
	Inventory* _inventory;

	// key variables
	bool _isOpen = true;
	std::vector<Item*> _keys;
	
	// person veriables
	std::vector<Person*> _persons;
};

#endif /* ROOM_H */
