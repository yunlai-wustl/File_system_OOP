// TextFile.h: File contains concrete class for a txt file
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
// TextFile declaration goes here
#include "AbstractFile.h"
#include <vector>
#include <string>
class TextFile : public AbstractFile{
    private:
        std::vector<char> contents;
        std::string name;
    public:
        TextFile(std::string file_name);
        uint getSize();
        std::string getName();
        int write(std::vector<char> characters);
        int append(std::vector<char> characters);
        std::vector<char> read();
        void accept(AbstractFileVisitor* ptr);
        AbstractFile* clone(std::string new_name);
};

