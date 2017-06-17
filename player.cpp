#include "player.h"

// player constructor
Player::Player(){
	_inventory = new Inventory(100);

	_playerMaxHealth = 100;
	_playerHeath = _playerMaxHealth;
}

// heal player
void Player::playerHeal(int _health){
	_playerHeath += _health;	
	
	// player heal message
	std::cout << "You got health for: " << _health << " hp! Your new health is: " << _playerHeath << " hp." << std::endl;

	if (_playerHeath > _playerMaxHealth) {
		_playerHeath = _playerMaxHealth;		
	}
}

// damage player
void Player::playerDamage(int _damage){
	_playerHeath -= _damage;

	// player damage message
	std::cout << "You got damage for: " << _damage << " hp! Your new health is: " << _playerHeath << " hp." << std::endl;

	if (_playerHeath <= 0) {
		_playerHeath = 0;
		_playerIsAlive = false;
	}
}

// get player stats in a string
std::vector<std::string> Player::getPlayerStats(){
	std::vector<std::string> _string;

	_string.push_back("hp:     " + std::to_string(_playerHeath));
	//_string.push_back("max hp: " + std::to_string(_playerMaxHealth));

	return _string;
}

// player deconstructor
Player::~Player() {
}
