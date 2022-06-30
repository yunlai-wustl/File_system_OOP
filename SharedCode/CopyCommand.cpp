#include <iostream>
#include "TextFile.h"
#include "ImageFile.h"
#include "CopyCommand.h"
#include "PasswordProxy.h"
#include "SimpleFileFactory.h"
#include <sstream>
using namespace std;

CopyCommand::CopyCommand(AbstractFileSystem* file_point) : system_ptr(file_point) {}

CopyCommand::~CopyCommand() {}

void CopyCommand::displayInfo() {
	cout << "cp copies a file in the file system, cp can be invoked with the command : cp <file_to_copy> <new_name_with_no_extension>" << endl;
}

int CopyCommand::execute(string file_names) {
	string file;
	stringstream divider(file_names);
	vector<string> files;
	while (divider >> file) {
		files.push_back(file);
	}
	if (files.size() != 2)
		return copy_fail;
	// gets file extension with substring function of string
	string ext = files[0].substr(files[0].length() - 4, files[0].length());
	// open file to get pointere and then close it to prevent errors
	AbstractFile* file_to_copy = system_ptr->openFile(files[0]);
	system_ptr->closeFile(file_to_copy);
	if (file_to_copy== 0)
	{
		return copy_fail;
	}
	// the name file contains both the file without an extension and with the extenssion
	string new_name = files[1] + ext;	
	if (system_ptr->getFileNames().count(new_name)) //file already exist
		return copy_fail;
	if (new_name == files[0]) return copy_fail;
	// call the clone method to make a new file from prototype pattern
	AbstractFile* file_copy=file_to_copy->clone(new_name);
	// add clone to file sysstem
	system_ptr->addFile(new_name, file_copy);
	return copy_success;
}