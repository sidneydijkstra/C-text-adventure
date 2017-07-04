/**
* @file command.h
*
* @brief The Command header file.
*
*/

#ifndef COMMAND_H
#define COMMAND_H

#include <string>

/**
* @brief The Command class contains a command of the player
*/
class Command
{
public:
	Command(std::string first = "", std::string second = "", std::string third = ""); ///< @brief Constructor of the Command
	virtual ~Command(); ///< @brief Destructor of the Command

	/// @brief get the first player command
	/// @return td::string
	std::string getCommandWord();

	/// @brief check if command is unknown
	/// @return bool
	bool isUnknown();

	/// @brief get the second command
	/// @return std::string
	std::string getSecondWord();

	/// @brief check if command hase a second word
	/// @return bool
	bool hasSecondWord();

	/// @brief get the third command
	/// @return std::string
	std::string getThirdWord();

	/// @brief check if command hase a third word
	/// @return std::string
	bool hasThirdWord();

private:
	std::string commandWord; ///< @brief the first command
	std::string secondWord; ///< @brief the second command
	std::string thirdWord; ///< @brief the third command
};

#endif /* COMMAND_H */
