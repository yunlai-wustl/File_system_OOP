// SimpleFileFactory.h: File contains concrete class for creating a file
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
// Studio 18 - simplefilefactory class declaration goes here
#include "AbstractFileFactory.h"
class SimpleFileFactory : public AbstractFileFactory {
public:
	AbstractFile* createFile(std::string file_name);

};