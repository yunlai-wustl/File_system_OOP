// CommandPrompt.h: File contains a class for constant interaction with file system
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include <map>
#include "AbstractCommand.h"
#include "AbstractFileSystem.h"
#include "AbstractFileFactory.h"
#include <string>

enum com_status { Success_com, fail_com , quit};


class CommandPrompt {
	private:
		std::map<std::string, AbstractCommand*> map;
		AbstractFileSystem* system_ptr;
		AbstractFileFactory* factory_ptr;
	protected:
		void listCommands();
		std::string prompt();
	public:
		CommandPrompt();
		~CommandPrompt();
		void setFileSystem(AbstractFileSystem* ptr);
		void setFileFactory(AbstractFileFactory* ptr);
		int addCommand(std::string key, AbstractCommand* ptr);
		int run();
};

