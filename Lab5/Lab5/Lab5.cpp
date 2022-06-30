#include <iostream>
#include <set>
#include "../../SharedCode/TextFile.h"
#include "../../SharedCode/ImageFile.h"
#include "../..//SharedCode/SimpleFileFactory.h"
#include "../../SharedCode/SimpleFileSystem.h"
#include "../../SharedCode/BasicDisplayVisitor.h"
#include "../../SharedCode/MetadataDisplayVisitor.h"
#include "../../SharedCode/PasswordProxy.h"
#include "../../SharedCode/TouchCommand.h"
#include "../../SharedCode/CommandPrompt.h"
#include "../../SharedCode/LSCommand.h"
#include "../../SharedCode/RemoveCommand.h"
#include "../../SharedCode/CatCommand.h"
#include "../../SharedCode/DisplayCommand.h"
#include "../../SharedCode/CopyCommand.h"
#include "../../SharedCode/MacroCommand.h"
#include "../../SharedCode/RenameParsingStrategy.h"
#include "../../SharedCode/GrepDisplayVisitor.h"
#include "../../SharedCode/GrepCommand.h"
using namespace std;

int main()
{
	SimpleFileSystem* sfs = new SimpleFileSystem();
	SimpleFileFactory* sff = new SimpleFileFactory();
	CommandPrompt* cp = new CommandPrompt;
	AbstractCommand* ls = new LSCommand(sfs);
	AbstractCommand* remove = new RemoveCommand(sfs);
	AbstractCommand* touch = new TouchCommand(sfs,sff);
	AbstractCommand* cat = new CatCommand(sfs);
	AbstractCommand* display = new DisplayCommand(sfs);
	AbstractCommand* copy = new CopyCommand(sfs);
	AbstractCommand* grep = new GrepCommand(sfs);
	string filename = "file.txt";
	AbstractFile* file = new TextFile(filename);
	sfs->addFile(filename, file);
	vector<char> v = { 'h','i' };
	file->write(v);
	string another = "another.txt";
	AbstractFile* another_file = new TextFile(another);
	sfs->addFile(another, another_file);
	vector<char> content = { 'h','i' };
	another_file->write(v);
	MacroCommand* mc = new MacroCommand(sfs);
	RenameParsingStrategy* rps = new RenameParsingStrategy;
	AbstractCommand* cpc = new CopyCommand(sfs);
	AbstractCommand* rmc = new RemoveCommand(sfs);
	mc->setParseStrategy(rps);
	mc->addCommand(cpc);
	mc->addCommand(rmc);
	cp->setFileSystem(sfs);
	cp->setFileFactory(sff);
	cp->addCommand("ls",ls);
	cp->addCommand("rm", remove);
	cp->addCommand("touch", touch);
	cp->addCommand("cat", cat);
	cp->addCommand("ds", display);
	cp->addCommand("cp", copy);
	cp->addCommand("rn", mc);
	cp->addCommand("grep", grep);
	cp->run();
}


