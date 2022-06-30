#include <iostream>
#include "TextFile.h"
#include "ImageFile.h"
#include "GrepCommand.h"
#include "GrepDisplayVisitor.h"
#include "SimpleFileFactory.h"
#include <sstream>
using namespace std;

GrepCommand::GrepCommand(AbstractFileSystem* file_point) : system_ptr(file_point) {}

GrepCommand::~GrepCommand() {}

void GrepCommand::displayInfo() {
	cout << "grep displays all files that in the file system that contain a certain string (image files will not be searched), grep can be invoked with the command : grep <string_to_search_for>" << endl;
}

int GrepCommand::execute(string str) {
	set<string> my_files = system_ptr->getFileNames();
	// if string to be checked is empty then do not print anything and return an error
	if (str == "") {
		return grep_fail;
	}
	// call new grep displayvisitor
	AbstractFileVisitor* afv = new GrepDisplayVisitor;
	// iterate through each file to check if string is in the contents of file
	for (auto file : my_files) {
		string ext = file.substr(file.length() - 4, file.length());
		if(ext == ".txt") {
			AbstractFile* file_searched = system_ptr->openFile(file);
			string to_be_searched = "";
			vector<char> chars = file_searched->read();
			// creating a string from chars
			for (auto i : chars) {
				to_be_searched += i;
			}
			// essentially checking if substring in string
			if (to_be_searched.find(str) != string::npos) {
				afv->visit_TextFile((TextFile*)file_searched);
			}
			system_ptr->closeFile(file_searched);
		}
	}
	return grep_success;
}