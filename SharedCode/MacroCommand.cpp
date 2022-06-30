#include "MacroCommand.h"
#include <iostream>

MacroCommand::MacroCommand(AbstractFileSystem* sys_ptr) :system_ptr(sys_ptr), parse_strategy(nullptr) {}

MacroCommand::~MacroCommand() {}
// add an already defined command to the macrocommand
void MacroCommand::addCommand(AbstractCommand*com)
{
	v_command.push_back(com);
}
// gets user input to uses for macrocommand
void MacroCommand::setParseStrategy(AbstractParsingStrategy* str)
{
	parse_strategy = str;
}
int MacroCommand::execute(std::string input)
{
	// run the macrocommand with a for loop which iterates through all commands of the macrocommand
	std::vector<std::string> cmd_inputs= parse_strategy->parse(input);
	for (int i = 0; i < v_command.size(); i++)
	{
		if(v_command[i]->execute(cmd_inputs[i])!=0)
			return macro_cmd_fail;
	}
	return macro_cmd_success;
}

void MacroCommand::displayInfo()
{
	std::cout << "macrocommand" << std::endl;
}
