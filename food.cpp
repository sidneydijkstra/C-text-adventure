#include "food.h"

// food constructor
Food::Food(std::string _name, int _weight){
	_itemName = _name;
	_itemWeight = _weight;
}

// food use function
void Food::use(){
	std::cout << "food is used!" << std::endl;
}

// food deconstructor
Food::~Food(){
}

