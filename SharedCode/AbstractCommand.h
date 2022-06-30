// AbstractCommand.h: File contains abstract class for commands with pure virtual functions
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include <string>

class AbstractCommand {
	public:
		virtual int execute(std::string name) = 0;
		virtual void displayInfo() = 0;
		virtual ~AbstractCommand() = default;
};