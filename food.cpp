#include "food.h"

// food constructor
Food::Food(Player* player, std::string name, std::string _description, int weight, int healAmount) : Item(name, _description, weight, player) {
	_heal = healAmount;
}

// food use function
void Food::use(){
	getPlayer()->playerHeal(_heal);
}

// food deconstructor
Food::~Food(){
}

