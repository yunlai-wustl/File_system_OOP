// AbstractParsingStrategy.h: File contains abstract class for parsing user input
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include<string>
#include<vector>
class AbstractParsingStrategy
{
public:
	virtual std::vector<std::string> parse(std::string) = 0;
};
