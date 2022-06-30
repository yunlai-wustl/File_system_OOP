#include <iostream>
#include <string>
#include "PasswordProxy.h"
using namespace std;

PasswordProxy::PasswordProxy(AbstractFile* file, string pass) : protected_file(file), password(pass) {}

PasswordProxy::~PasswordProxy() { delete protected_file; }
// get user input
string PasswordProxy::passwordPrompt() {
	string input;
	cout << "Type your password: ";
	getline(cin, input);
	return input;
}
// return contents of password protected file
vector<char> PasswordProxy::read() {
	if (passwordPrompt() == password) return protected_file->read();
	else return {};
}
// essentially like initializing a file with chars
int PasswordProxy::write(vector<char> characters) {
	if (passwordPrompt() == password) return protected_file->write(characters);
	else return prompt_error;
}
// append chars to the file
int PasswordProxy::append(vector<char> characters) {
	if (passwordPrompt() == password) return protected_file->append(characters);
	else return prompt_error;
}
// get the number of chars n file
uint PasswordProxy::getSize() {
	return protected_file->getSize();
}
// get the name of a protected file
string PasswordProxy::getName() {
	return protected_file->getName();
}
// if the password is correct use the visitor
void PasswordProxy::accept(AbstractFileVisitor* ptr) {
	if (passwordPrompt() == password) {
		protected_file->accept(ptr);
	}
}
// clones the file by first calling clone on the specific file and then creating a new proxy for it
AbstractFile* PasswordProxy::clone(string new_name) {
	AbstractFile* cp = protected_file->clone(new_name);
	PasswordProxy* copy = new PasswordProxy(cp,password);
	return copy;
}