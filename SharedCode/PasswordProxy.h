// PasswordProxy.h: File contains class for setting up a password protected file
// Author: Yunlai Chen, Peter Yan, Doran Wu

#pragma once
#include "AbstractFile.h"
#include <string>
#include <vector>

enum proxy_error {prompt_error=1};

class PasswordProxy : public AbstractFile {
	private:
		AbstractFile* protected_file;
		std::string password;
	protected:
		std::string passwordPrompt();
	public:
		PasswordProxy(AbstractFile* file, std::string pass);
		~PasswordProxy();
		std::vector<char> read();
		int write(std::vector<char> characters);
		int append(std::vector<char> characters);
		uint getSize();
		std::string getName();
		void accept(AbstractFileVisitor* ptr);
		AbstractFile* clone(std::string new_name);
};
