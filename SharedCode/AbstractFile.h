// AbstractFile.h: File contains abstract class for files with pure virtual functions in addition with a few enums
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include <vector>
#include <string>
typedef unsigned int uint;
// declare AbstractFile here. As all methods are virtual and will not be defined, no .cpp file is necessary
class AbstractFileVisitor;

enum result_code{
    Success,
    size_mismatch,
    invalide_pixel,
    operation_not_supprted,
    file_not_exist,
    ptr_is_null,
    file_already_exist,
    file_type_not_supported,
    file_not_opened,
    file_opened_in_system
};

class AbstractFile {
    public:
        virtual std::vector<char> read() = 0;
        virtual int append(std::vector<char> characters) = 0;
        virtual int write(std::vector<char> characters) = 0;
        virtual uint getSize() = 0;
        virtual std::string getName() = 0;
        virtual void accept(AbstractFileVisitor* ptr) = 0;
        virtual AbstractFile* clone(std::string new_name) = 0;
};