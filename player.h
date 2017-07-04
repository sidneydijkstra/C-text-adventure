/**
* @file player.h
*
* @brief The player header file.
*
*/

#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"
#include "inventory.h"

/**
* @brief The Player class handels all the Player functions
*/
class Player{
public:
	Player(); ///< @brief Constructor of the Player
	virtual ~Player(); ///< @brief Destructor of the Player

	/// @brief get the current Room
	/// @return Room
	Room* getCurrentRoom() { return _currentroom; };

	/// @brief set the current Room
	/// @param the new Room
	/// @return void
	void setCurrentRoom(Room* _room) { _currentroom = _room; };

	/// @brief get Player current health
	/// @return int
	int getHealth() { return _playerHeath; };

	/// @brief set Player current health
	/// @param health you want to set it to
	/// @return void
	void setHealth(int _health);

	/// @brief get if Player  is alive
	/// @return bool
	bool isAlive() { return _playerIsAlive; };

	/// @brief heal the player
	/// @param heal amount
	/// @return void
	void playerHeal(int _health);

	/// @brief damage the player
	/// @param damage amount
	/// @return void
	void playerDamage(int _damage);

	/// @brief get the Inventory of the Player
	/// @return Inventory
	Inventory* getInventory() { return _inventory; };

	/// @brief print player stats
	/// @return void
	void printPlayerStats();

private:
	Room* _currentroom = NULL; ///< @brief the current Room of the Player

	int _playerHeath = 0; ///< @brief health of the Player
	int _playerMaxHealth = 0; ///< @brief max health of the Player
	bool _playerIsAlive = true; ///< @brief is the player alive

	Inventory* _inventory; ///< @brief the Inventory of the Player
};

#endif /* PLAYER_H */