// CopyCommand.h: File contains concrete class for copying a file
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include <string>

enum copy_enum { copy_success, copy_fail };

class CopyCommand : public AbstractCommand {
private:
	AbstractFileSystem* system_ptr;
public:
	CopyCommand(AbstractFileSystem* file_point);
	~CopyCommand();
	void displayInfo();
	int execute(std::string file_names);
};