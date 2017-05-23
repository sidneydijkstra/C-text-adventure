// commandwords.h

#ifndef PLAYER_H
#define PLAYER_H

#include <iostream>
#include <vector>
#include <string>

#include "room.h"
#include "item.h"

class Player
{
public:
	Player();
	virtual ~Player();

	// go to new room
	void goRoom(std::string first, std::string second);
	// set all the rooms and the current room
	void createRooms();

	// get current room description
	std::string getCurrentRoomDescription();
	// get current room items
	std::string getCurrentRoomItems();

	// damage player
	void damagePlayer(float dmg);
	// heal player
	void healPlayer(float heal);
	// is player dead
	bool isAlive() { if (currentHealth <= 0) return true; else return false; }


	// add new item to player
	bool addItem(std::string name);
	// add item to room and remove it from player
	bool dropItem(std::string name);
	// get all items in inf
	std::string getItemsInInventory();
	// look if you can take this item
	bool canTakeItem(std::string name);


private:
	// player health
	float maxHealth;
	float currentHealth;

	// rooms
	Room* currentRoom;
	Room* outside;
	Room* house;
	Room* attic;
	Room* basement;
	Room* garden;
	Room* roof;

	// items
	std::vector<Item*> inventory;
	float maxWeight = 100; // in kilo
};

#endif
