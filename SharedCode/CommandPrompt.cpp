#include <iostream>
#include <sstream>

#include "CommandPrompt.h"
using namespace std;

CommandPrompt::CommandPrompt() : system_ptr(nullptr), factory_ptr(nullptr) {}

CommandPrompt::~CommandPrompt() {}

// sets a command prompt to a given file system
void CommandPrompt::setFileSystem(AbstractFileSystem* ptr) {
	system_ptr = ptr;
}

// sets a command prompt to a given file factory
void CommandPrompt::setFileFactory(AbstractFileFactory* ptr) {
	factory_ptr = ptr;
}

// add user defined commands to our file system simulator
int CommandPrompt::addCommand(std::string key, AbstractCommand* ptr) {
	int old_size = map.size();
	map.insert(pair<string, AbstractCommand*>(key, ptr));
	// ternary operator for checking if command is added
	return (old_size == map.size()) ? fail_com: Success_com;
}

void CommandPrompt::listCommands() {
	// list commands of file system by iterating through map
	for (auto const& pair : map) {
		cout << pair.first << endl;
	}
}

int CommandPrompt::run() {
	while (1) {
		// get prompt of user
		string command = prompt();
		string word;
		stringstream divider(command);
		vector<string> commands;
		// if user quits then return something which stops the while loop
		if (command == "q") return 1;
		while (divider >> word) {
			commands.push_back(word);
		}
		if (commands.size() != 1) {
			// help with a command
			if (commands[0] == "help") {
				// if command does snot exist print out an error statement, or display info if it does exist
				if (map.find(commands[1]) == map.end()) cout << "command does not exist" << endl;
				else map.find(commands[1])->second->displayInfo();
			}
			else {
				// if execute contains multiple words then process them with this for loop
				string param;
				for (int i = 1; i < commands.size(); ++i) {
					param += (commands[i]+" ");
				}
				param.pop_back();
				if (map.find(commands[0]) == map.end()) cout << "command does not exist" << endl;
				else map.find(commands[0])->second->execute(param);
			}
		}
		else {
			// if input is only one word and is help then list all commands
			if (word == "help") {
				listCommands();
			}
			else {
				if (map.find(word) == map.end()) cout << "command does not exist" << endl;
				else map.find(word)->second->execute("");
			}
		}
	}
}


string CommandPrompt::prompt() {
	// this will keep on printing during the run function and prompts user for input
	string input;
	cout << "Enter a command, q to quit, help for a list of commands, or" << "\n" <<
		"help followed by a command name for more information about" << "\n" <<
		"that command." << "\n" <<
		"$ ";
	getline(cin, input);
	return input;
}
