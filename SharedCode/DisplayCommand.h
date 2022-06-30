// DisplayCommand.h: File contains concrete class for displaying contents of file with a visitor
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include <string>
#include <sstream>

enum ds_enum { ds_success, ds_fail };

class DisplayCommand : public AbstractCommand {
private:
	AbstractFileSystem* system_ptr;
public:
	DisplayCommand(AbstractFileSystem* file_point);
	~DisplayCommand();
	void displayInfo();
	int execute(std::string name);
};