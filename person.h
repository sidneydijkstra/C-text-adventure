/**
* @file person.h
*
* @brief The person header file.
*
*/

#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

/**
* @brief The Person class handels all the things a person can do
*/
class Person {
public:
	/// @brief Constructor of the Inventory
	/// @param the name of the person
	/// @param the max health of the person
	Person(std::string name, int maxHealth);
	virtual ~Person();  ///< @brief Destructor of the Inventory

	/// @brief get the current health of the person
	/// @return int
	int getHealth() { return _personHealth; };

	/// @brief set the current health of the person
	/// @param health you wnat to set it to
	/// @return void
	void setHealth(int _health);

	/// @brief get if the person is alive
	/// @return bool
	bool isAlive() { return _personIsAlive; };

	/// @brief heal the Person
	/// @param heal amount
	/// @return void
	void personHeal(int _health);

	/// @brief damage the Person
	/// @param damage amount
	/// @return void
	void personDamage(int _damage);

	/// @brief get the name of the person
	/// @return std::string
	std::string getPersonName() { return _personName; };
private:
	std::string _personName; ///< @brief the name of the person

	int _personHealth = 0; ///< @brief the persons health
	int _personMaxHealth = 0; ///< @brief the persons max health
	bool _personIsAlive = true; ///< @brief the persons is alive
};

#endif /* PERSON_H */