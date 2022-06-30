// AbstractFileSystem.h: File contains abstract class for file system with pure virtual functions for manipulating file system
// Author: Yunlai Chen, Peter Yan, Doran Wu
#pragma once
// declaration of the interface all file systems provide goes here
#include <string>
#include <set>
#include "AbstractFile.h"
class AbstractFileSystem {
	public:
		virtual int addFile(std::string file_name,AbstractFile *ptr)=0;
		virtual int deleteFile(std::string file_name) = 0;
		virtual AbstractFile* openFile(std::string file_name) = 0;
		virtual int closeFile(AbstractFile* ptr) = 0;
		virtual std::set<std::string> getFileNames() = 0;//added for LSCommand
};