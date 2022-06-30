// Studio18.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "..\..\\SharedCode\AbstractFile.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	AbstractFileSystem* file_system_ptr = new SimpleFileSystem;
	AbstractFileFactory* file_factory_ptr = new SimpleFileFactory;
	string filename = "a.txt";
	AbstractFile* abstrac_file_ptr = file_factory_ptr->createFile(filename);
	abstrac_file_ptr->write({ 'c' });
	vector<char> contents = abstrac_file_ptr->read();
	contents.push_back('d');
	for (int i = 0; i < contents.size(); i++)
	{
		cout << contents[i] << endl;
	}
	return 0;
}