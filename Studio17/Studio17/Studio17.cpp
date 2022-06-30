// Studio17.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "..\..\\SharedCode\ImageFile.h"
using namespace std;
#include <vector>

int main()
{
	vector<char> my_characters = {'X',' ',' ','X','2'};
	ImageFile my_file("my_file");
	my_file.write(my_characters);
	cout << my_file.getName() << endl;
	cout << my_file.getSize() << endl;
	my_file.read();
}

