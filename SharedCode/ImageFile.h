// ImageFile.h: File contains concrete class for an image file of spaces and X's
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
// Image file class declaration here
#include "AbstractFile.h"
#include <string>
#include <vector>

class ImageFile : public AbstractFile {
	private:
		std::string name;
		std::vector<char> contents;
        char size;
        int findVectorPosition(int x, int y);
    public:
        char get_dim();
        ImageFile(std::string file_name);
        uint getSize();
        std::string getName();
        int write(std::vector<char> characters);
        int append(std::vector<char> characters);
        std::vector<char> read();
        void accept(AbstractFileVisitor* ptr);
        AbstractFile* clone(std::string new_name);
};