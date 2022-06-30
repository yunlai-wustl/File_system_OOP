// RenameParsingStrategy.h: File is a header file for processing user input
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include "AbstractParsingStrategy.h"
class RenameParsingStrategy :public AbstractParsingStrategy
{
public:
	std::vector<std::string> parse(std::string);
};