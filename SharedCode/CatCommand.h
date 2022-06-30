// CatCommand.h: File contains concrete class for appending or overwriting a file
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include <sstream>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"

enum cat_enums { cat_success = 0, cat_fail_other, cat_fail_openFile};

class CatCommand : public AbstractCommand {
private:
	AbstractFileSystem* system_ptr;
public:
	CatCommand(AbstractFileSystem* file_point);
	~CatCommand();
	void displayInfo();
	int execute(std::string name);
};
