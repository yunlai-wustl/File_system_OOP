// AbstractFileFactory.h: File contains abstract class for the file factory with pure virtual function for creating files that will be defined in concrete classes with either txt or img or anything else you declare
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include <string>
#include "AbstractFile.h"
class AbstractFileFactory
{
public:
	virtual AbstractFile* createFile(std::string file_name) = 0;
};