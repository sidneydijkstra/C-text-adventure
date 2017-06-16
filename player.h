// player.h

#ifndef PLAYER_H
#define PLAYER_H

#include "room.h"
#include "inventory.h"

class Player{
public:
	Player();
	virtual ~Player();

	// player currentroom functions
	Room* getCurrentRoom() { return _currentroom; };
	void setCurrentRoom(Room* _room) { _currentroom = _room; };

	// player health functions
	int getHealth() { return _playerHeath; };
	void setHealth(int _health) { _playerHeath = _playerHeath; if (_playerHeath > _playerMaxHealth) { _playerHeath = _playerMaxHealth; } };
	bool isAlive() { return _playerIsAlive; };

	void playerHeal(int _health);
	void playerDamage(int _damage);

	// get the inventory
	Inventory* getInventory() { return _inventory; };

private:
	// player currentroom
	Room* _currentroom = NULL;

	// player health
	int _playerHeath = 0;
	int _playerMaxHealth = 0;
	bool _playerIsAlive = true;

	// player inventory
	Inventory* _inventory;
};

#endif /* PLAYER_H */