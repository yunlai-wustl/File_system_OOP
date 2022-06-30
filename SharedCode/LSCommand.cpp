#include <iostream>
#include "LSCommand.h"
#include "AbstractFileVisitor.h"
#include "MetadataDisplayVisitor.h"
using namespace std;

LSCommand::LSCommand(AbstractFileSystem* file_point) : system_ptr(file_point) {}

LSCommand::~LSCommand() {}

void LSCommand::displayInfo() {
	cout << "ls displays all files currently in the file system, ls can be invoked with the command : ls or ls -m for metadata" << std::endl;
}

int LSCommand::execute(string name) {
	// standard ls because of empty string
	if (name == "") {
		set<string> my_files = system_ptr->getFileNames();
		int count = 0;
		// enables you to have two files on one line when you display it
		for (auto i : my_files) {
			cout << i << " ";
			count++;
			if (count == 2) {
				cout << endl;
				count = 0;
			}
		}
		// then print a new line
		if (count != 2) {
			cout << endl;
		}
		return ls_success;
	}
	// metadata for ls command
	else if (name == "-m") {
		set<string> my_files = system_ptr->getFileNames();
		AbstractFileVisitor* afv = new MetadataDisplayVisitor;
		// printss out a file with its metadata
		for (auto i : my_files) {
			AbstractFile* file = system_ptr->openFile(i);
			// checks whether file is a txt or image file and then calling visit on it
			file->accept(afv);
			system_ptr->closeFile(file);
		}
		return ls_success;
	}
	else return ls_fail;
}