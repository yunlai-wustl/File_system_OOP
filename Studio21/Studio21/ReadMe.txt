Studio 21 ReadMe.txt 

Name: Doran, Peter, Yunlai

Q1: why is it importantto declare a virtual destructor in the base class?
Answer: 
we use virtual destructors to destruct the objects and their resources in proper orders. 
If the base delete is not virtual, and we call the function of a derived ptr, then the call is not valid.

Q2: discuss how dependency injection makes the command prompt flexible and reusable
Answer: 
There are 4 parts of the dependency-injection system:
1) services: what we inject;
2) client: depends on the services.
3) interface: how client object uses the services.
4) injector: injects the services into the client.
such design makes the DI system more flexible by nature because now we can break the coupling between code blocks.
if the client object were to directly create an instance of the service, it would introduce a strong coupling between the client and the service implementation. 
In the case of constructor injection (our method):
* we prevent vs2019 from creating any common prompt with less than required injections.
* we make sure such DI system would not change after creation.
therefore it's a better method than Setter Injection or Property Injection for this program.

Q3:
In main(), dynamically allocate a SimpleFileSystem,a SimpleFileFactory, and a TouchCommand object (configured with the file systemand file factory objects).
Create avariable of type CommandPrompt and configure it withthe file system, file factory, andtouch command object you created.
Call run() on thecommand prompt object and testquitting, asking for help, asking for help on thetouch command, and executing the touchcommand.
After quitting and returning from the run function, you should still have direct access to the FileSystem object in main().
You can verify “touch” worked correctly by trying to open the file it created. As the answer to this question, describe the tests you ran.
Answer:
codes:
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

outputs:
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$ touch
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$ help
touch
Enter a command, q to quit, help for a list of commands, or
help followed by a command name for more information about
that command.
$ q
file.txt


