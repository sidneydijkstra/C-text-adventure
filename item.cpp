#include "item.h"

// item constructor
Item::Item(std::string _name, int _weight){
	// set item name and weight
	_itemName = _name;
	_itemWeight = _weight;
}

// item deconstructor
Item::~Item(){

}
