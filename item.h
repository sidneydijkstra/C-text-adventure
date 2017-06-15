// item.h

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Item {
public:
	Item(std::string _name, int _weight);
	virtual ~Item();

	// item use function
	virtual void use() { std::cout << "you cant use this item!" << std::endl; };


	int getItemWeight() { return _itemWeight; };
	std::string getItemName() { return _itemName; };
private:
	int _itemWeight;
	std::string _itemName;
};

#endif /* ITEM_H */