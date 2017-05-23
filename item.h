// item.h

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>
#include <vector>

class Item
{
public:
	Item(std::string name_, std::string description_, float weight_);
	virtual ~Item();

	// get item info
	std::string getItemName() { return name; };
	std::string getItemDescription() { return description; };
	float getItemWeight() { return weight; };
private:
	std::string name;
	std::string description;
	float weight;
};

#endif