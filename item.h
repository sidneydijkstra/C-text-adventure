// item.h

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Player;

class Item {
public:
	Item(std::string _name, std::string _description, int _weight, Player* player);
	virtual ~Item();

	// item use function
	virtual void use() { std::cout << "you cant use this item!" << std::endl; };

	// get item weight and name
	int getItemWeight() { return _itemWeight; };
	std::string getItemName() { return _itemName; };
	std::string getItemDescription() { return _itemDescription; };

	// get player
	Player* getPlayer() { return _player; };
private:
	// some global item variables
	int _itemWeight;
	std::string _itemName;
	std::string _itemDescription;

	Player* _player;
};

#endif /* ITEM_H */