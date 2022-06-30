//  Define the TextFile class here
#include "TextFile.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
using namespace std;

TextFile::TextFile(string file_name): name(file_name) {}

uint TextFile::getSize() {
    return contents.size();
}

string TextFile::getName() {
    return name;
}
// basically like initializing a file with some text
int TextFile::write(std::vector<char> characters) {
    contents = characters;
    return (contents == characters)?0:-1;
}
// add text to file
int TextFile::append(std::vector<char> characters) {
    contents.insert(contents.end(), characters.begin(), characters.end());
    return 0;
}
// return contents of file into vector of characters
vector<char> TextFile::read() {
    return contents;
}
// visit the text file called on the abstract file ptr
void TextFile::accept(AbstractFileVisitor* ptr) {
    if (ptr != 0)
        ptr->visit_TextFile(this);
}
// clone the file instead of calling factory
AbstractFile * TextFile::clone(string new_name) {
    TextFile* copy = new TextFile(new_name);
    copy->append(this->read());
    return copy;
}