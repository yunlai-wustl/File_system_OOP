#include <iostream>
#include "vector"
#include "GrepDisplayVisitor.h"
using namespace std;
// gets the name of the current pointer
void GrepDisplayVisitor::visit_TextFile(TextFile* ptr) {
	cout << ptr->getName() << endl;
}
// nothing for image as stated in instructions
void GrepDisplayVisitor::visit_ImageFile(ImageFile* ptr) {}