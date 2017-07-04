/**
* @file key.h
*
* @brief The key header file.
*
*/

#ifndef KEY_H
#define KEY_H

#include <iostream>
#include <string>

#include "item.h"
#include "player.h"
#include "room.h"

/**
* @brief The Key class can open doors in rooms
*/
class Key : public Item {
public:
	/// @brief Constructor of the Key
	/// @param the player pointer
	/// @param the key name
	/// @param the key description
	/// @param the key weight
	Key(Player* player, std::string name, std::string _description, int weight);
	~Key(); ///< @brief Destructor of the Key

	/// @brief the use fucntion of the item
	/// @return void
	void use();
private:
};

#endif /* KEY_H */