#include "player.h"

// player constructor
Player::Player(){
	_inventory = new Inventory(100);

	_playerMaxHealth = 100;
	_playerHeath = _playerMaxHealth;
}

void Player::setHealth(int _health){
	_playerHeath = _health;
	if (_playerHeath > _playerMaxHealth) { 
		_playerHeath = _playerMaxHealth; 
	}

	if (_playerHeath <= 0) {
		_playerHeath = 0;
		_playerIsAlive = false;
	}
}

// heal player
void Player::playerHeal(int _health){
	_playerHeath += _health;	
	
	if (_playerHeath > _playerMaxHealth) {
		_playerHeath = _playerMaxHealth;		
	}

	// player heal message
	std::cout << "You got health for: " << _health << " hp! Your new health is: " << _playerHeath << " hp." << std::endl;
}

// damage player
void Player::playerDamage(int _damage){
	_playerHeath -= _damage;

	if (_playerHeath <= 0) {
		_playerHeath = 0;
		_playerIsAlive = false;
	}

	// player damage message
	std::cout << "You got damage for: " << _damage << " hp! Your new health is: " << _playerHeath << " hp." << std::endl;
}

// get player stats in a string
void Player::printPlayerStats(){
	std::cout << "--- stats ---" << std::endl;

	std::cout << "hp:     " << std::to_string(_playerHeath) << std::endl;

	std::cout << "--- ----- ---" << std::endl;
}

// player deconstructor
Player::~Player() {
	// delete inventoy
	delete _inventory;
}
