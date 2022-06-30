//////////////
//////////////////////////////
CSE 332 Final Project: FileSystem Design 
Authors:
    - Yunlai Chen
    - Peter Yan
    - Doran Wu, 487275
//////////////////////////////
//////////////

/////////////
How Program Works
 - How to Run Program
 - Design Decisions (Division of Labor)
 - Design Procedure for functions
 - Warnings or Errors

 - Trial Runs / Test Cases
    - LS Command
    - Remove Command
    - Touch Command
    - Cat Command
    - Display Command
    - Copy Command
    - Macro Command
    - Rename Command
    - Grep Command
////////////

How to Run Program:
 - use "cd" command to "cd" into Debug folder of this repository
 - program can run successfully simply by typing "Lab5" in terminal (commands are already set up in file system in main and can be continually run because it is using commandprompt run, with rename added as a macro command that can be used)

Design Decisions or those not Specified in Lab Directions/Other things to point out:
 - Division of Labor
    - General Comments: Each group member contributed ideas and code to each file through both individual and also work completed in group sessions with liveshare and discussion in zoom. 
                        Everyone worked on revising and simplifying other's code which can be seen in detail for the commits in the repository. 
                        Below, is a more general but also more specified plan of what each member contributed to this lab. Some put more work in the studios while others in the lab
                        however each person put in a significant work for all the work for the studios and lab.
    - Yunlai:
        - significantly worked on first half of the studios
        - finished display command
        - helped Doran finish copy command 
        - finished macro command with rename
    - Peter:
        - completed a few studio readmes
        - finished cat command
        - helped Doran with copy command
        - worked on testing
    - Doran:
        - finished the latter half of the studios
        - finished ls command
        - finished remove command
        - main worker of copy command
        - finished touch with password proxy command
        - main writer of the readme

Design Procedure for functions:
 - LSCommand
    - first function checks whether user uses command with no additional arguments or one more, if there is one more and it is -m then that is fine however if none of these
      occur then command is not successfully executed
    - if there is no command line arguments, function does a standard ls in which metadata is not shown and files are displayed in a method to which two files are displayed on each line
      and that is implemented by using the function getFileNames that we wrote earlier which gets all files and puts them in a set
    - then we use a for loop to iterate through each value in the set and print out each element which would be the file name and each time a line is filled up with two files
      it goes to the next line
    - the metadata display visitor on the other hand invoked by "-m" will be employed similar to the standard ls but will also use the metadatadisplayvisitor on each element
      to get the metadata of a file, and there will be file for each line rather than 2 files per line

 - Remove Command
    - first function checks if a name is passed, if string is empty instantly return a failure enumeration
    - then function gets a pointer for file to delete by calling the open file function on that and then closing it right after to avoid any errors
    - then function checks whether or not that ptr is null (if it is null it does not exist so return a failure enum), if it is not null call delete on that file 
      and return success

 - TouchCommand
    - first check if user invokes command with an empty string or correctly and with either just a filename or both a filename and a "-p" for password protection, 
      if it is an empty string return a failure enumeration
    - this is done with stringstream to separate out values
    - with touch it uses the file factory to create a file and then if created successfuly adds it to the file system, if there is a "-p" then it creates a password
      proxy after calling create file on that specific file
    - if the file could not be added properly it will delete the file by deleting the pointer at the memory location

 - CatCommand
    - similar to previous commands it will use a vector to store all the strings that user enters with the command
    - first tries opening the file to get a pointer, if that pointer is null return a failure enumeration if not continue
    - then we get user input from command and store into a vector, if user uses "-a" then we append those contents of that vector into our file vector and if not then
      we overwrite by replacing the old vector with the new vector
    - but those two only occur if user enters ":wq" rather than ":q" at the end, if it is ":q" then nothing changes with file and nothing is saved

 - DisplayCommand
    - similar to previous commands it will use a vector to store all the strings that user enters with the command
    - first tries opening the file to get a pointer, if that pointer is null return a failure enumeration if not continue
    - if command is invoked with "" then it is formmated output then we use the basic display visitor by calling accept (depends if "" or "-d") 
    - if command is invoked with "-d", then we don't use visitor and we print out contents of file from read function with for loop and then close after that ends

 - CopyCommand
    - similar to previous commands it will use a vector to store all the strings that user enters with the command
    - first tries opening the original file to get a pointer, if that pointer is null return a failure enumeration if not continue
    - because we need to use prototype pattern rather than file factory our team first decided use to copy constructors but then we decided instead to use a clone function that is in 
      each of the concrete classes which takes two pointers, a pointer to the original file and a second parameter which holds the string of the new name to call that file
    - in our copy command function we call clone, and we can simply call on an abstract file pointer without having to call it on a specific text, image, or password proxy
      because we have the clone function in concrete classes which fits the prototype pattern
    - if the clone works properly then we add that file to the file system and return a success enumeration

 - MacroCommand
    - first they use a rename parsing startegy to get a user input and convert it into inputs for the commands
    - execute function works by calling the parse strategy on input and then for all commands added to the macrocommand iterate through each of them 
      with a for loop
    - if any of them returns a non-zero enumeration then return a failure enumeration for macro command, if all return zero return a success eeenumeration

 - Rename
    - this is a macrocommand composed of the copy and remove command, which first you declare a macrocommand, set a parse strategy for it, and then add the copy
      and then remove command to that macrocommand
    - int the command prompt it works by invoking "rn <existing-file_name-with_extension> <new_file_name_no_ext>"

 - Grep
    - first we created a new display visitor that simply prints out the file name given a pointer
    - in the execute function for this command first we check whether the user entered a string or if it is blank, if it is blank return a failure enumeration (design choice)
    - if there is input then create a new display visitor for grep
    - then we iterate through all the files, if the file is an image then skip it, if it is a text file then search it by using the string
    - we convert the contents of file into a string
    - then we call the find function to check if the user enterred input is a substring of the string that represents the contents of the file 
      (cited from https://www.geeksforgeeks.org/string-find-in-cpp/#:~:text=String%20find%20is%20used%20to,of%20starting%20position%20is%200.)

Warnings/Errors:
 - C26812: enumeration warning which is due to an old

(* made sure to pass all test cases before doing these more custom tests, and all these tests are run with the file simulation with command prompt run which is an infinite while loop and ends when :q is pressed)
(to set these tests up we initially created two files called ("file.txt") and ("another.txt") before calling command prompt run with the chars 'h' and 'i' written to both files)
Trial Runs / Test Cases:
 - Help Command Test Cases
    - Standard Help listing all commands in filesystem
        - Input: help
        - Output:   cat
                    cp
                    ds
                    ls
                    rm
                    rn
                    touch
        - Explanation: listed all commands added to the command prompt which makes sense
    - Help with a command in filesystem
        - Input: help ls
        - Output: ls displays all files currently in the file system, ls can be invoked with the command : ls or ls -m for metadata
        - Explanation: this makes sense because ls lists all commands and help with ls just displays info for that command
 - LS Command Test Cases
    - calling command without metadata addition (no -m)
        - Input: ls
        - Output: another.txt file.txt
        - Explanation: makes sense in which two files are printed on same line with space separating them and no metadata
    - calling command with metadata addition (with -m)
        - Input: ls -m
        - Output: another.txt text 2
                  file.txt text 2
        - Explanation: shows a file for each line and displays the type of file which makes sense because they are both txt and contain two characters 'h' and 'i'
    - calling command with weird addition that is not supported by command
        - Input: ls -p
        - Output:
        - Explanation: nothing happens because command does not support it
 - Remove Command Test Cases
    - calling remove correctly on file that exists (and then calling ls)
        - Input: rm another.txt
        - Output: file.txt
        - Explanation: successfuly removed another.txt from file
    - calling remove on file that does not exists
        - Input: rm exist.txt
        - Output: another.txt file.txt
        - Explanation: file does not exist in filesystem so nothing was deleted
    - calling remove on copy and checking if original still exists (created a copy called copy.txt from file.txt, and then calling ls)
        - Input: rm copy.txt
        - Output before rm: another.txt copy.txt
                            file.txt
        - Output after rm: another.txt file.txt
        - Explanation: only that specific file of that pointer is deleted not original so we know deep copy iss created
    - calling remove on more than one file
        - Input: rm another.txt file.txt
        - Output:
        - Explanation: does not work could only call rm on one file
 - Touch Command Test Cases
    - calling touch correctly on a new file that is not in file system yet (then calling ls)
        - Input: touch one_more.img
        - Output: another.txt file.txt
                  one_more.img
        - Explanation: adds it to the file system successfuly (also tried without extension and it didn't work so passed string must have a proper extension)
    - calling touch with more than one file as command line arguments (then calling ls)
        - Input: touch a.txt b.txt
        - Output: a.txt b.txt another.txt
                  file.txt
        - Explanation: "a.txt b.txt" is one file which looks weird but is still added to file system properly
    - calling touch on a file that already exists
        - Input: touch file.txt
        - Output: file already exists!
        - Explanation: makes sense because each filename should be unique
 - Cat Command Test Cases (all on file.txt)
    - calling cat command properly without -a, so appending (then calling display)
        - Input: there my name is
        - Output: hi there my name is
        - Explanation: file i
    - calling cat command properly with -a, so rewriting (then calling display)
        - Input: hello
        - Output: hello
        - Explanation: file is rewritten with the hi replaced by hello
    - calling cat command with a weird command line argument
        - Input: cat file.txt -p
        - Output: 
        - Explanation: nothing happens because "-p" is not supported by cat
    - calling cat command on a file that does not exists
        - Input: cat hello.txt
        - Output:
        - Explanation: file does not exist so the standard space for input is not displayed
    - calling cat command on a password protected file (creating a file first called password.txt)
        - Input: touch password.txt -p
                 cat password.txt
        - Output: Type your password: pass
                  Enter data to append to the existing file. Enter :wq to save and exit, enter :q to exit without saving. with -a we append, without -a we overwrite
        - Explanation: this makes sense because in order to concatenate or overwrite a file you need password protection
 - Display Command Test Cases
    - displaying a file that exists with -d
        - Input: ds hello.txt
        - Output: hi
        - Explanation: because formatted hi is printed on line and then a new line is added wiith the standard prompt
    - displaying a file that exists without -d
        - Input: ds hello.txt -d
        - Output: hiEnter a command, q to quit, help for a list of commands, or
                  help followed by a command name for more information about
                  that command.
        - Explanation: unformatted input makes sense
    - displaying a file that does not exists
        - Input: ds fille.txt
        - Output:
        - Explanation: nothing happens because file could not be opened
 - Copy Command Test Cases
    - calling copy on a non-existent file in system (calling ls)
        - Input: cp fille.txt fil
        - Output: 
        - Explanation: nothing happens because a copy cannot be made on something that doese not exist
    - calling copy on an existing file (then calling ls -m)
        - Input:  cp another.txt another_one.txt
        - Output: another.txt text 2
                  another_one.txt text 2
                  file.txt text 2
        - Explanation: file is copied fine and contents seem to have also been copied
 - Macro Command Test Cases
    - testing rename on a non-existent file
        - Input: rn fil.txt hello.txt
        - Output:
        - Explanation: nothing happens because file isn ot in system
    - testing rename on a existing file (then calling ls and display)
        - Input: rn file.txt fil
        - Output with ls: another.txt fil.txt
        - Output with ds on file: hi
        - Explanation: file is properly renamed and contents tays the same
    - testing rename on a existing file to another file that is existing (then calling display)
        - Input: rn file.txt another
        - Output: another.txt file.txt
        - Explanation: nothing changes because another is already the name for another file
 - Grep Command Test Cases
    - calling grep with a blank string passed as a command line argument
        - Input: grep
        - Output:
        - Explanation: nothing happens which is also expected
    - calling grep correctly with a string "hi"
        - Input: grep hi
        - Output: another.txt
                  file.txt
        - Explanation: both files contain hi which is expected
    - calling grep correctly but with a string that should not be in any files
        - Input: grep bye
        - Output:
        - Explanation: nothing listed so that is expected
