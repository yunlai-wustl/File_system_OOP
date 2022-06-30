#include <iostream>
#include "RemoveCommand.h"
using namespace std;

RemoveCommand::RemoveCommand(AbstractFileSystem* file_point) : system_ptr(file_point) {}

RemoveCommand::~RemoveCommand() {}

void RemoveCommand::displayInfo() {
	cout << "rm deletes a file currently in the file system, rm can be invoked with the command : rm <filename>" << std::endl;
}

int RemoveCommand::execute(string name) {
	if (name == "") return rm_fail;
	else {
		// get file pointer by opening it and then deleting it
		AbstractFile* ptr = system_ptr->openFile(name);
		system_ptr->closeFile(ptr);
		// if file does not exist
		if (ptr != nullptr) {
			// delete the file from system by calling delete on it
			system_ptr->deleteFile(name);

		}
		else return rm_fail;
		return rm_success;
	}
}