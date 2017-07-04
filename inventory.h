/**
* @file inventory.h
*
* @brief The inventory header file.
*
*/

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include <string>

#include "item.h"

/**
* @brief The Inventory class handels the Inventory of the Room and the Player
*/
class Inventory{
public:
	/// @brief Constructor of the Inventory
	/// @param the max weight of the inventory
	Inventory(int _weight); 
	virtual ~Inventory(); ///< @brief Destructor of the Inventory

	/// @brief add a new item to inventory
	/// @param name of the item
	/// @param pointer to the item
	/// @return void
	void addItem(std::string _name, Item* _item) { _itemList[_name] = _item; };

	/// @brief remove a item from the inventory
	/// @param name of the item
	/// @return void
	void removeItem(std::string _name) { _itemList.erase(_name); };

	/// @brief get a item fromm the inventory
	/// @param name of the item
	/// @return item
	Item* getItem(std::string _name) { if (_itemList.count(_name) > 0) return _itemList[_name]; else return NULL; };

	/// @brief print all the items in this Inventory
	/// @return void
	void printAllItemNames();

	/// @brief check if inventory has item
	/// @param name of the item
	/// @return bool
	bool hasItem(std::string _name) { if (this->getItem(_name) != NULL) return true; else return false; };

	/// @brief take an item from a inventory
	/// @param name of the item
	/// @param inventory you want to take the item from
	/// @return void
	void take(std::string _name, Inventory* _inventory);

	/// @brief drop an item in a inventory
	/// @param name of the item
	/// @param inventory you want to drop the item in
	/// @return void
	void drop(std::string _name, Inventory* _inventory);

	/// @brief check if you can pick up a item
	/// @param item you want to pick up
	/// @return bool
	bool canPickupItem(Item* _item);
	
	/// @brief check if you can drop a item
	/// @param item you want to drop
	/// @return bool
	bool canDropItem(Item* _item);
private:
	std::map<std::string, Item*> _itemList; ///< @brief list of all the items in inventory
	int _maxWeight = 0; ///< @brief max weight of the inventory

};

#endif /* INVENTORY_H */