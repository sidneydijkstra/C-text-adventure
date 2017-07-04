#include "person.h"

// person constructor
Person::Person(std::string _name, int maxHealth){
	_personName = _name;
}



void Person::setHealth(int _health){
	_personHealth = _health;
	if (_personHealth > _personMaxHealth) {
		_personHealth = _personMaxHealth;
	}
}

// person deconstructor
Person::~Person() {
}
