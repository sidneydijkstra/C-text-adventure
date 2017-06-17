#include "item.h"

// item constructor
Item::Item(std::string _name, std::string _description, int _weight){
	// set item variables
	_itemName = _name;
	_itemWeight = _weight;
	_itemDescription = _description;
}

// item deconstructor
Item::~Item(){

}
