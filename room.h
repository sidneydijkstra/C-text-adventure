/**
* @file room.h
*
* @brief The room header file.
*
*/

#ifndef ROOM_H
#define ROOM_H

#include <iostream>
#include <string>
#include <vector>
#include <map>

#include "inventory.h"
#include "item.h"
#include "person.h"

/**
* @brief The Room class handles all the Room functions
*/
class Room{
public:
	/// @brief Constructor of the Room
	/// @param the description of the Room
	Room(std::string desc);
	virtual ~Room(); ///< @brief Destructor of the Room

	/// @brief set a new exit of the Room
	/// @param direction of the new Room
	/// @param pointer to the Room
	/// @return void
	void setExit(std::string direction, Room* neighbor);

	/// @brief get a exit of the Room
	/// @param direction of the exit
	/// @return Room
	Room* getExit(std::string direction);

	/// @brief get all the closed rooms
	/// @return std::vector<Room>
	std::vector<Room*> getClosedRooms();

	/// @brief get the long description of the Room
	/// @return std::string
	std::string getLongDescription() { return "You are " + _description + '\n' + getExitString(); }

	/// @brief get the exit string of the Room
	/// @return std::string
	std::string getExitString();

	/// @brief get the Inventory of the Room
	/// @return Inventory
	Inventory* getInventory() { return _inventory; };

	/// @brief get if the Room is open
	/// @return bool
	bool isOpen() { return _isOpen; };

	/// @brief close the room
	/// @return void
	void closeRoom() { _isOpen = false; };

	/// @brief open the room
	/// @return void
	void openRoom() { _isOpen = true; };

	/// @brief add a new Key you can open the door with
	/// @param the Key pointer
	/// @return void
	void addOpenKey(Item* _key) { _keys.push_back(_key); };

	/// @brief try to open the door with a Key
	/// @param the Key pointer
	/// @return void
	void canOpen(Item* _key);

	/// @brief add a new Person to the Room
	/// @param the Person pointer
	/// @return void
	void addPerson(Person* _person) { _persons.push_back(_person); };

	/// @brief remove a Person from the Room
	/// @param the Person pointer
	/// @return void
	void removePerson(Person* _person);

	/// @brief get all the persons in a Room
	/// @return std::vector<Person>
	std::vector<Person*> getAllPersons() { return _persons; };

	/// @brief get a Person in a Room
	/// @param Person name
	/// @return Person
	Person* getPerson(std::string _name);
private:
	std::string _description; ///< @brief the description of the Room
	std::map<std::string, Room*> _exits; ///< @brief list of the exits of the Room

	Inventory* _inventory; ///< @brief the Inventory of the Room

	// key variables
	bool _isOpen = true; ///< @brief is the room open
	std::vector<Item*> _keys; ///< @brief list of Room Keys
	
	std::vector<Person*> _persons; ///< @brief list of Room persons
};

#endif /* ROOM_H */
