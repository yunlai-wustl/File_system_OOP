// definitions of metadata visitor here
#include <iostream>
#include "MetadataDisplayVisitor.h"
using namespace std;
// get the metadata of a text file
void MetadataDisplayVisitor::visit_TextFile(TextFile* ptr) {
	cout << ptr->getName() << " ";
	cout << "text" << " ";
	cout << ptr->getSize() << endl;
}
// get the metadata of a text file
void MetadataDisplayVisitor::visit_ImageFile(ImageFile* ptr) {
	cout << ptr->getName() << " ";
	cout << "image" << " ";
	cout << ptr->getSize() << endl;
}