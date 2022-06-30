// RemoveCommand.h: File contains concrete class command to remove files
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include <string>

enum rm_enum { rm_success, rm_fail };

class RemoveCommand : public AbstractCommand {
private:
	AbstractFileSystem* system_ptr;
public:
	RemoveCommand(AbstractFileSystem* file_point);
	~RemoveCommand();
	void displayInfo();
	int execute(std::string name);
};