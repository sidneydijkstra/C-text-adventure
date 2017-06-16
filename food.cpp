#include "food.h"

// food constructor
Food::Food(Player* player, std::string name, int weight, int healAmount) : Item(name, weight) {
	_player = player;
	_heal = healAmount;
}

// food use function
void Food::use(){
	_player->playerHeal(_heal);
}

// food deconstructor
Food::~Food(){
}

