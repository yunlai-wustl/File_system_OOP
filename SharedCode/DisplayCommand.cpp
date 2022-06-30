#include <iostream>
#include "DisplayCommand.h"
#include "AbstractFileVisitor.h"
#include "MetadataDisplayVisitor.h"
#include "BasicDisplayVisitor.h"
using namespace std;

DisplayCommand::DisplayCommand(AbstractFileSystem* file_point) : system_ptr(file_point) {}

DisplayCommand::~DisplayCommand() {}

void DisplayCommand::displayInfo() {
	cout << "display files contents, ds can be invoked with the command : ds file_name for formatted output or ds file_name -d for non-formatted output" << std::endl;
}

int DisplayCommand::execute(string name) {
	string word;
	stringstream divider(name);
	vector<string> words;
	BasicDisplayVisitor vis;
	//check input words size, if that's less than 2, wrong; if size == 2; then call formatted output; if size == 3 and the 3rd arg is "-d", call unformatted output; else return fail
	while (divider >> word) {
		words.push_back(word);
	}
	if (words.size() == 0) 
	{
		return ds_fail;
	}
	//formatted output
	else if (words.size() == 1)
	{
		AbstractFile* ptr = system_ptr->openFile(name);
		if (ptr == nullptr)
			return ds_fail;
		// uses basic display visitor to print out contents
		ptr->accept(&vis);
		system_ptr->closeFile(ptr);
		return ds_success;
	}
	//unformatted output
	else if (words.size() == 2 && words[1] == "-d")
	{
		AbstractFile* ptr = system_ptr->openFile(words[0]);
		if (ptr == nullptr)
			return ds_fail;
		vector<char>contents = ptr->read();
		// printing out contents
		for (int i = 0; i < contents.size(); i++)
		{
			cout << contents[i];
		}
		if (words[0].back() == 'g')
			cout << "\n";
		system_ptr->closeFile(ptr);
		return ds_success;
	}
	return ds_fail;
}
