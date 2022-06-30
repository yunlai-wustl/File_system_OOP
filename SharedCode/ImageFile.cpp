// definition of ImageFile class here
#include "AbstractFile.h"
#include "ImageFile.h"
#include "BasicDisplayVisitor.h"
#include <iostream>
using namespace std;

ImageFile::ImageFile(string file_name): name(file_name) , size(0){}
// gets number of characters in file
uint ImageFile::getSize() {
    return contents.size();
}
// getss name of image file
string ImageFile::getName() {
    return name;
}

int ImageFile::write(std::vector<char> characters) {
    // gets size of image by converting char to int by subtracting it by 48
    size = characters.back() - 48;
    characters.pop_back();
    // size mismatch
    if((size*size)!=characters.size()) {
        size = 0;
        return size_mismatch;
    }
    for(int i = 0;i<(size*size);++i) {
        if(characters[i] != 'X' && characters[i] != ' ') {
            size = 0;
            return invalide_pixel;
        }
    }
    contents = characters;
    return Success;
}

int ImageFile::append(std::vector<char> characters) {
    return operation_not_supprted;
}
// helper function for finding an image vector position
int ImageFile::findVectorPosition(int x, int y) {
    return y * size + x;
}
// gets image contents
vector<char> ImageFile::read() {
    return contents;
}
// accepting visitor
void ImageFile::accept(AbstractFileVisitor* ptr) {
    if (ptr != 0)
        ptr->visit_ImageFile(this);
}
// gets size of image file
char ImageFile::get_dim()
{
    return size;
}
// function for cloning a function
AbstractFile* ImageFile::clone(string new_name) {
    ImageFile* copy = new ImageFile(new_name);
    copy->append(this->read());
    return copy;
}

