studio 18 answers here
1. If we use a concrete file system, every file type needs to be pre-defined. If users are trying to create a new file type likes '.pdf',
	the file system would not work properly.
2. The factory is only responsible for one thing and if that has some bugs, it won't influence other parts.
3. If we have a new file type. what we only need do is to make the code can read/load this file type, without changing any code for other method.
	If we have a lot of concrete factory patterns/file types, the code can be pretty complicated/messy.
4. Code: 	AbstractFileSystem* file_system_ptr = new SimpleFileSystem;
			AbstractFileFactory* file_factory_ptr = new SimpleFileFactory;
			string filename = "a.txt";
			AbstractFile* abstrac_file_ptr = file_factory_ptr->createFile(filename);
			abstrac_file_ptr->write({'c'});
			abstrac_file_ptr->read(); 
	Output: c
