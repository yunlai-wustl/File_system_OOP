#include "..\..\\SharedCode\PasswordProxy.h"
#include "..\..\\SharedCode\AbstractFileFactory.h"
#include "..\..\\SharedCode\AbstractFileSystem.h"
#include "..\..\\SharedCode\SimpleFileFactory.h"
#include "..\..\\SharedCode\SimpleFileSystem.h"
#include "..\..\\SharedCode\PasswordProxy.h"
#include <iostream>
#include <string>
using namespace std;

int main()
{
	AbstractFileSystem* file_system_ptr = new SimpleFileSystem;
	AbstractFileFactory* file_factory_ptr = new SimpleFileFactory;
	string filename = "a.txt";
	AbstractFile* abstrac_file_ptr = file_factory_ptr->createFile(filename);
	PasswordProxy proxy(abstrac_file_ptr, "abd");
	vector<char>input;
	input.push_back('a');
	input.push_back('b');
	input.push_back('c');

	proxy.write(input);
	vector<char> v = proxy.read();
	std::copy(v.begin(), v.end(),
		std::ostream_iterator<char>(std::cout, " "));

	return 0;
}