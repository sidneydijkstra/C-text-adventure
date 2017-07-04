#include "item.h"

// item constructor
Item::Item(std::string _name, std::string _description, int _weight, Player* player){
	// set item variables
	_itemName = _name;
	_itemWeight = _weight;
	_itemDescription = _description;
	_player = player;
}

// item deconstructor
Item::~Item(){

}
