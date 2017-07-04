/**
* @file item.h
*
* @brief The item header file.
*
*/

#ifndef ITEM_H
#define ITEM_H

#include <iostream>
#include <string>

class Player;

/**
* @brief The Item class handels all the main fucntions for a Item
*/
class Item {
public:
	/// @brief Constructor of the Item
	/// @param the name of the item
	/// @param the description of the item
	/// @param the weight of the item
	/// @param the player pointer
	Item(std::string _name, std::string _description, int _weight, Player* player);
	virtual ~Item(); ///< @brief Destructor of the Item

	/// @brief the use fucntion for the item
	/// @return void
	virtual void use() { std::cout << "you cant use this item!" << std::endl; };

	/// @brief get the item weight
	/// @return int
	int getItemWeight() { return _itemWeight; };

	/// @brief get the item name
	/// @return std::string
	std::string getItemName() { return _itemName; };

	/// @brief get the item description
	/// @return std::string
	std::string getItemDescription() { return _itemDescription; };

	/// @brief get the player
	/// @return Player
	Player* getPlayer() { return _player; };
private:
	int _itemWeight; ///< @brief the item weight
	std::string _itemName; ///< @brief the item name
	std::string _itemDescription; ///< @brief the item description

	Player* _player; ///< @brief the player pointer
};

#endif /* ITEM_H */