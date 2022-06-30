#include <iostream>
#include "CatCommand.h"
#include "SimpleFileFactory.h"
#include "SimpleFileSystem.h"
using namespace std;

// base initializer list for initializing variables
CatCommand::CatCommand(AbstractFileSystem* file_point) : system_ptr(file_point) {}

CatCommand::~CatCommand() {}

void CatCommand::displayInfo() {
	cout << "Enter data to append to the existing file. Enter :wq to save and exit, enter :q to exit without saving. with -a we append, without -a we overwrite" << endl;
}

int CatCommand::execute(string name) {
	string word;
	stringstream divider(name);
	vector<string> words;
	// gets user input and puts it into a vector
	while (divider >> word) {
		words.push_back(word);
	}
	// gets the file pointer by opening it and then closing it
	AbstractFile* file_ptr = system_ptr->openFile(words[0]); 
	system_ptr->closeFile(file_ptr);
	//if we can open the file
	if (file_ptr != nullptr) {
		//read and print current content to cout
		vector<char> content = file_ptr->read();
		for (int i = 0; i < content.size(); i++) {
			cout << content[i];
		}
		cout << endl;
		//set up for action
		vector<char> add_words;
		string input;
		displayInfo();//display info string to cmd
		while (getline(cin, input) && input != ":wq" && input != ":q") {
			//print current data to add if -a
			if (words.size() > 1 && words[1] == "-a") {
				cout << "current data to add: ";
				for (int i = 0; i < add_words.size(); i++) {
					cout << add_words[i];
				}
				cout << endl;
			}
			//push input to add_words
			for (int j = 0; j < input.size();j++) {
				add_words.push_back(input[j]);
			}
			// each time a new line is pushed push a '\n'
			add_words.push_back('\n');
		}
		// save the file and then quit
		if (input == ":wq") {
			if (add_words.size() > 1) {
				add_words.pop_back();
			}
			if (words.size() > 1) {
				// check if append works if it does not return a fail
				int fail_checker = file_ptr->append(add_words);
				if (fail_checker != Success) {
					return fail_checker;
				}
			}
			else {
				// check if append works if it does not return a fail
				int fail_checker = file_ptr->write(add_words);;
				if (fail_checker != Success) {
					return fail_checker;
				}
			}
			return cat_success;
		}
		else if (input == ":q") {
			// if user does not want to save clear the vector
			if (content.size() > 0) {
				add_words.clear();
			}
			return cat_success;
		}
		else {
			return cat_fail_other;
		}
	}
	else {
		return cat_fail_openFile;
	}
	

}