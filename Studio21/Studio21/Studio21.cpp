//#include "..\..\\SharedCode\TouchCommand.h"
//#include "..\..\\SharedCode\CommandPrompt.h"

#include "../../SharedCode/AbstractFileSystem.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include <iostream>

using namespace std;

int main()
{	
	AbstractFileSystem* sfs = new SimpleFileSystem();
	AbstractFileFactory* sff = new SimpleFileFactory();
	TouchCommand* tc = new TouchCommand(sfs, sff);
	tc->execute("file.txt");

	CommandPrompt* cp = new CommandPrompt;
	cp->setFileSystem(sfs);
	cp->setFileFactory(sff);
	int temp_int = cp->addCommand("touch", tc);
	cp->run();
	AbstractFile* file = sfs->openFile("file.txt");
	cout << file->getName() << endl;
	return 0;
}