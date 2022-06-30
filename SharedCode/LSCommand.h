// LSCommand.h: File contains concrete class for displaying all files in a filesystem
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include "AbstractCommand.h"
#include "SimpleFileSystem.h"
#include <string>

enum ls_enum {ls_success, ls_fail};

class LSCommand : public AbstractCommand {
	private:
		AbstractFileSystem* system_ptr;
	public:
		LSCommand(AbstractFileSystem* file_point);
		~LSCommand();
		void displayInfo();
		int execute(std::string name);
};