// SimpleFileSystem.h: File contains a concrete class that enables the manipulation of a file system
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
// declaration of SimpleFileSystem class goes here
#include "AbstractFileSystem.h"
#include <set>
#include <map>


class SimpleFileSystem : public AbstractFileSystem {
private:
    std::map<std::string, AbstractFile*> files;
    std::set<AbstractFile*> openFiles;
public:
	int addFile(std::string file_name, AbstractFile* ptr);
	int deleteFile(std::string file_name);
	AbstractFile* openFile(std::string file_name) ;
	int closeFile(AbstractFile* ptr);
	std::set<std::string> getFileNames();//added for LSCommand
};