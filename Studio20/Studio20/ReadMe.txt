Studio 20 ReadMe.txt
1. Group member names: Doran Wu, Peter Yan, Yunlai Chen

2. Since the files are password protected, once the passwordproxy is destroyed, there should not be any access to the file. So we need to delete the pointer in destructor. 

4. We created a file and its password proxy. If we want to write something to it, it will ask for password. Only after we input the right password, it can write the contents to this 
	file successfully. Then we tried to read the contents we just wrote by calling read method, it will ask us to input password again to get access to this file,