/**
* @file food.h
*
* @brief The food header file.
*
*/

#ifndef FOOD_H
#define FOOD_H

#include <iostream>
#include <string>

#include "item.h"
#include "player.h"

/**
* @brief The Food is an item
*/
class Food : public Item {
public:
	Food(Player* player, std::string name, std::string _description, int weight, int healAmount); ///< @brief Constructor of the Food
	~Food(); ///< @brief Destructor of the Food

	/// @brief the food use commmand to use the food
	/// @return void
	void use();
private:
	int _heal = 0; ///< @brief the amount this food will heal
};

#endif /* FOOD_H */