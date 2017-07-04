/**
* @file parser.h
*
* @brief The parser header file.
*
*/

#ifndef PARSER_H
#define PARSER_H

#include "command.h"
#include "commandwords.h"

/**
* @brief The Parser class handels the users input and from the input he creates a Command
*/
class Parser
{
public: 
	Parser(); ///< @brief Constructor of the Parser
	virtual ~Parser(); ///< @brief Destructor of the Parser

	/// @brief get the current Command
	/// @return Command
	Command getCommand();

	/// @brief show all the command the Player can do
	/// @return void
	void showCommands() { commands.showAll(); }

private:
	CommandWords commands;  ///< @brief CommandWords pointer
};

#endif /* PARSER_H */
