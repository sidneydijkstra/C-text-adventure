// inventory.h

#ifndef INVENTORY_H
#define INVENTORY_H

#include <iostream>
#include <map>
#include <string>

#include "item.h"

class Inventory{
public:
	Inventory(int _weight);
	virtual ~Inventory();

	// inventory functions
	void addItem(std::string _name, Item* _item) { _itemList[_name] = _item; };
	void removeItem(std::string _name) { _itemList.erase(_name); };
	Item* getItem(std::string _name) { if (_itemList.count(_name) > 0) return _itemList[_name]; else return NULL; };
	std::string getAllItemNames();

	// take someting from inv that you give
	void take(std::string _name, Inventory* _inventory);
	// drop a item if inv can get item
	void drop(std::string _name, Inventory* _inventory);

	// get the weight and look if you can pick this up
	bool canPickupItem(Item* _item);
	// get the weight and look if you can drop this up
	bool canDropItem(Item* _item);
private:
	// item list
	std::map<std::string, Item*> _itemList;
	int _maxWeight = 0;

};

#endif /* INVENTORY_H */