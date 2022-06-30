// define methods of SimpleFileSystem class here
#include "SimpleFileSystem.h"
#include "TextFile.h"
#include "ImageFile.h"
#include <iostream>
#include <sstream>
#include <cassert>
using namespace std;

int SimpleFileSystem::addFile(string file_name, AbstractFile* ptr)
{
	// check if file exists in map
	map<string, AbstractFile*>::iterator it = files.find(file_name);
	if (it!=files.end())
	{
		cout << "file already exist!" << endl;
		return file_already_exist;
	}
	if (ptr != 0)
	{
		// if it does not exist in map add it to the file system
		files.insert(pair<string, AbstractFile* >(file_name, ptr));
		return Success;
	}
	else
		return ptr_is_null;
}

AbstractFile* SimpleFileSystem::openFile(std::string file_name)
{
	// opens the file and inserts it into a set called open files
	if (files.count(file_name)) {
		if (!openFiles.count(files[file_name])) {
			openFiles.insert(files[file_name]);
			return(files[file_name]);
		}
		else return nullptr;
	}
	else return nullptr;
}

int SimpleFileSystem::closeFile(AbstractFile* ptr)
{
	// closes the file and deletes it from the set, if it is not opened return a failure enumeration
	if (openFiles.count(ptr))
	{
		openFiles.erase(ptr);
		return Success;
	}
	else
		return file_not_opened;
}

int SimpleFileSystem::deleteFile(std::string file_name)
{
	// deletes a file from a map, but only would delete those that are not opened
	map<string, AbstractFile*>::iterator it = files.find(file_name);

	if (it != files.end())
	{
		if (openFiles.count(files[file_name]))
		{
			return file_opened_in_system;
		}
		else
		{
			delete files[file_name];
			files.erase(file_name);

			return Success;
		}
	}
	else
		return file_not_exist;

}

set<string> SimpleFileSystem::getFileNames() {
	// gets all filess of a simple file system
	set<string> file_set;
	for (auto const& pair : files) {
		file_set.insert(pair.first);
	}
	return file_set;
}