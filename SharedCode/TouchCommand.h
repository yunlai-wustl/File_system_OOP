// TouchCommand.h: File contains class creating a file and adding it othe filesystem
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include <sstream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum touch_enums {fail_to_create = 1, delete_file};

class TouchCommand : public AbstractCommand {
	private:
		AbstractFileSystem* system_ptr;
		AbstractFileFactory* factory_ptr;
	public:
		TouchCommand(AbstractFileSystem* file_point, AbstractFileFactory* factory_point);
		~TouchCommand();
		void displayInfo();
		int execute(std::string name);
};