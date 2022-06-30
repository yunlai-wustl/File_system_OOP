#include "RenameParsingStrategy.h"
#include <sstream>

std::vector<std::string> RenameParsingStrategy::parse(std::string user_input)
{
	// process user input for macrocommands
	std::vector<std::string> v_str;
	std::string file;
	std::stringstream divider(user_input);
	v_str.push_back(user_input);
	divider >> file;
	v_str.push_back(file);
	return v_str;
}