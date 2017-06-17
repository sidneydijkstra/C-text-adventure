// command.h

#ifndef COMMAND_H
#define COMMAND_H

#include <string>

class Command
{
public:
	Command(std::string first = "", std::string second = "", std::string third = "");
	virtual ~Command();

	std::string getCommandWord();
	bool isUnknown();
	std::string getSecondWord();
	bool hasSecondWord();
	std::string getThirdWord();
	bool hasThirdWord();

private:
	std::string commandWord;
	std::string secondWord;
	std::string thirdWord;
};

#endif /* COMMAND_H */
