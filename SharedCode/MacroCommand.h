// MacroCommand.h: File contains class for setting up macrocommands which enable a single command to call multiple commands
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include "AbstractCommand.h"
#include "AbstractParsingStrategy.h"
#include "AbstractFileSystem.h"

enum Macro_cmd_result {macro_cmd_success,macro_cmd_fail};

class MacroCommand :public AbstractCommand {
private:
	std::vector<AbstractCommand*> v_command;
	AbstractParsingStrategy* parse_strategy;
	AbstractFileSystem* system_ptr;
public:
	MacroCommand(AbstractFileSystem*);
	~MacroCommand();

	void addCommand(AbstractCommand* com);
	void setParseStrategy(AbstractParsingStrategy* str);
	void displayInfo();
	int execute(std::string name);
};
