// studio 18 - simple file factory definitions
#include <iostream>
#include "SimpleFileFactory.h"
#include <sstream>
#include "ImageFile.h"
#include "TextFile.h"
using namespace std;

AbstractFile* SimpleFileFactory::createFile(string file_name) {
	string extension;
	stringstream ss(file_name);
	while (getline(ss, extension, '.'))
	{
		continue;
	}
	AbstractFile* ptr;
	// depending on the extension will make new files bassed on that
	if (extension == "txt") {
		ptr = new TextFile(file_name);
	}
	else if (extension == "img") {
		ptr = new ImageFile(file_name);
	}
	else {
		return nullptr;
	}
	return ptr;
}
