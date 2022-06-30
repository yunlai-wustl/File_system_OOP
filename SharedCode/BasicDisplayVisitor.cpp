// definitions of basic display visitor here
#include <iostream>
#include "vector"
#include "BasicDisplayVisitor.h"
using namespace std;

void BasicDisplayVisitor::visit_TextFile(TextFile* ptr) {
    // read contents of file into vector
    vector<char> contents = ptr->read();
    // use a for loop to print out all contents of file
    for(int i = 0;i<contents.size();++i) {
        cout << contents[i];
    }
    // print out a new line after printing out contents of file
    cout << endl;
}

void BasicDisplayVisitor::visit_ImageFile(ImageFile* ptr) {
    // read contents of file into vector
    vector<char> contents = ptr->read();
    // use helper file to get dimensions of image
    int size = ptr->get_dim();
    int cur_val = 0;
    // declare a temporary variable to use when using the for loop to know when to print out a new line
    for (int index = 0; index < contents.size(); ++index) {
        cout << contents[index];
        ++cur_val;
        if (cur_val == size) {
            cout << endl;
            cur_val = 0;
        }    
    }
}

