/**
* @file commandwords.h
*
* @brief The commandwords header file.
*
*/

#ifndef COMMANDWORDS_H
#define COMMANDWORDS_H

#include <iostream>
#include <vector>
#include <string>

/**
* @brief The CommandWords handels all the commands
*/
class CommandWords
{
public:
	CommandWords(); ///< @brief Constructor of the CommandWords
	virtual ~CommandWords(); ///< @brief Destructor of the CommandWords

	/// @brief check if std::string is a command
	/// @param a std::string you wanna check
	/// @return bool
	bool isCommand(std::string);

	/// @brief show all commands
	/// @return void
	void showAll() {
        for(int i = 0; i < validCommands.size(); i++) {
            std::cout << validCommands[i] << " ";
        }
        std::cout << std::endl;
    }

private:
	std::vector<std::string> validCommands; ///< @brief all the valid command
};

#endif /* COMMANDWORDS_H */
