// person.h

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

class Person {
public:
	Person(std::string name, int maxHealth);
	virtual ~Person();

	// player health functions
	int getHealth() { return _personHealth; };
	void setHealth(int _health);
	bool isAlive() { return _personIsAlive; };

	// get person name
	std::string getPersonName() { return _personName; };
private:
	// some global player variables
	std::string _personName;

	// player health
	int _personHealth = 0;
	int _personMaxHealth = 0;
	bool _personIsAlive = true;
};

#endif /* PERSON_H */