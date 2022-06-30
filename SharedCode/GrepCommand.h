// GrepCommand.h: File contains concrete class for displaying all files that contain a string that user inputs
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include <string>

enum grep_enum { grep_success, grep_fail };

class GrepCommand : public AbstractCommand {
private:
	AbstractFileSystem* system_ptr;
public:
	GrepCommand(AbstractFileSystem* file_point);
	~GrepCommand();
	void displayInfo();
	int execute(std::string str);
};