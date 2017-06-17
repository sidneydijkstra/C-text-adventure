// preson.h

#ifndef PRESON_H
#define PRESON_H

#include <iostream>
#include <string>

class Person {
public:
	Person(std::string _name);
	virtual ~Person();

	// get item weight and name
	std::string getPresonName() { return _personName; };
private:
	// some global item variables
	std::string _personName;
};

#endif /* PRESON_H */