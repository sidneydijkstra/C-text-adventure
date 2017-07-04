#include "inventory.h"

// inventory constructor
Inventory::Inventory(int _weight){
	// set max weight
	_maxWeight = _weight;
}

// take someting from inv that you give
void Inventory::take(std::string _name, Inventory* _inventory){
	if (canPickupItem(_inventory->getItem(_name))) {
		this->addItem(_name, _inventory->getItem(_name));
		_inventory->removeItem(_name);
		std::cout << "You took a " << _name << "." << std::endl;
		return;
	}
	//std::cout << "you cant take that or it is not on the ground" << std::endl;
}

// drop a item if inv can get item
void Inventory::drop(std::string _name, Inventory* _inventory){
	if (_inventory->canDropItem(this->getItem(_name))) {
		_inventory->addItem(_name, this->getItem(_name));
		this->removeItem(_name);
		std::cout << "You dropt a " << _name << "." << std::endl;
		return;
	}
	//std::cout << "you cant drop that or you dont have that" << std::endl;
}

// get the weight and look if you can pick this up
bool Inventory::canPickupItem(Item* _item){
	// check if item exists
	if (_item == NULL) {
		// MESSAGE: inventory does not contain item
		std::cout << "That is not around you at the moment." << std::endl;
		return false;
	}

	// check if _maxWeight == NULL (then inventory has no max)
	if (_maxWeight == 0) {
		return true;
	}

	// get new item weight
	int _weight = _item->getItemWeight();

	// get rest items weight
	std::map<std::string, Item*>::iterator _iterator = _itemList.begin();
	while (_iterator != _itemList.end()) {
		_weight += _iterator->second->getItemWeight();
		++_iterator;
	}

	// check if new weight is alowed
	if (_weight <= _maxWeight) {
		return true;
	}
	// MESSAGE: item to heavy
	std::cout << "That item is to heavy." << std::endl;
	return false;
}

// get the weight and look if you can drop this up
bool Inventory::canDropItem(Item * _item){
	// check if item exists
	if (_item == NULL) {
		// MESSAGE: inventory does not contain item
		std::cout << "`You cant drop something you dont have." << std::endl;
		return false;
	}

	// check if _maxWeight == NULL (then inventory has no max)
	if (_maxWeight == 0) {
		return true;
	}

	// get new item weight
	int _weight = _item->getItemWeight();

	// get rest items weight
	std::map<std::string, Item*>::iterator _iterator = _itemList.begin();
	while (_iterator != _itemList.end()) {
		_weight += _iterator->second->getItemWeight();
		++_iterator;
	}

	// check if new weight is alowed
	if (_weight <= _maxWeight) {
		return true;
	}

	// MESSAGE: item to heavy
	std::cout << "That item is to heavy." << std::endl;
	return false;
}

// get all the names of items
void Inventory::printAllItemNames() {
	std::string _string;

	std::map<std::string, Item*>::iterator _iterator = _itemList.begin();
	while (_iterator != _itemList.end()) {
		_string += _iterator->first + " ";
		++_iterator;
	}

	if (_string.compare("") == 0) {
		_string =  "nothing";
	}

	std::cout << _string << std::endl;
}

// inventory deconstructor
Inventory::~Inventory() {
	// remove items
	std::map<std::string, Item*>::iterator _iterator = _itemList.begin();
	while (_iterator != _itemList.end()) {
		delete _iterator->second;
		++_iterator;
	}
}
