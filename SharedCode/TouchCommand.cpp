#include <iostream>
#include "TouchCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
#include "PasswordProxy.h"
using namespace std;

TouchCommand::TouchCommand (AbstractFileSystem* file_point, AbstractFileFactory* factory_point) : system_ptr(file_point), factory_ptr(factory_point) {}

TouchCommand::~TouchCommand() {}

void TouchCommand::displayInfo() {
	cout << "touch creates a file, touch can be invoked with the command : touch <filename> or touch <file_name> -p to create a password-protected file" << std::endl;
}

int TouchCommand::execute(std::string name) {
	string word;
	stringstream divider(name);
	vector<string> words;
	// get user inputs and process them to vector
	while (divider >> word) {
		words.push_back(word);
	}
	// for password protection
	if (words.size() > 1 && words[1] == "-p") {
		PasswordProxy* helper;
		string input;
		cout << "Type your password: ";
		// get user input
		getline(cin, input);
		// created a password protected file with given passsword
		AbstractFile* proxy = new PasswordProxy(factory_ptr->createFile(words[0]), input);
		if (proxy != nullptr) {
			// if file could be added then return success
			if (system_ptr->addFile(words[0], proxy) == Success) return Success;
			else {
				AbstractFile* delete_ptr = system_ptr->openFile(words[0]);
				delete proxy;
				// prevent memory leak
				system_ptr->closeFile(delete_ptr);
				delete delete_ptr;
				return delete_file;
			}
		}
		else {
			return fail_to_create;
		}
	}
	else {
		// create a regular file without password if -p is not added
		AbstractFile* ptr = factory_ptr->createFile(name);
		if (ptr != nullptr) {
			if (system_ptr->addFile(name, ptr) == Success) return Success;
			else {
				delete ptr;
				return delete_file;
			}
		}
		else {
			return fail_to_create;
		}
	}
}