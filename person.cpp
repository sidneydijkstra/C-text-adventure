#include "person.h"

// person constructor
Person::Person(std::string _name, int maxHealth){
	_personMaxHealth = maxHealth;
	_personHealth = _personMaxHealth;
	_personName = _name;
}

void Person::setHealth(int _health){
	_personHealth = _health;
	if (_personHealth > _personMaxHealth) {
		_personHealth = _personMaxHealth;
	}

	if (_personHealth <= 0) {
		_personHealth = 0;
		_personIsAlive = false;
	}
}

void Person::personHeal(int _health){
	_personHealth += _health;
	if (_personHealth > _personMaxHealth) {
		_personHealth = _personMaxHealth;
	}
}

void Person::personDamage(int _damage){
	_personHealth -= _damage;
	if (_personHealth <= 0) {
		_personHealth = 0;
		_personIsAlive = false;
	}

	std::cout << _personName << " got damage for: " << _damage << " hp! " << _personName << " new health is: " << _personHealth << " hp." << std::endl;
}

// person deconstructor
Person::~Person() {
}
