# Parallel file copying using fork


## Task
Write a program in C: open a file (of any size without
restrictions), readable. The file name is passed from the command line. After
When opening a file, create a parallel process using fork. In both processes
, create your own files for writing, read information from a shared file and copy it to
your own output files (not on the screen). Display the contents of the received
files from the spawned process after writing to the file and from the parent
process, waiting for the spawned process to complete.

## Project structure <br>
**main.c** ----  This file contains the main program logic. It handles command-line argument parsing, opens the input file, forks a child process, waits for the child process to finish, and prints the content of the output files.  Error handling for file operations and `fork()` is included.<br>
**file_operations.c** ----  This file contains the functions `copy_file()` and `print_file()`.  `copy_file()` copies data from one `FILE *` pointer to another. `print_file()` prints the contents of a file to standard output.<br>
**file_operations.h** ----- This header file declares the function prototypes for `copy_file()` and `print_file()`.<br>


### Compilation
To compile a project, you can use the provided "Makefile".  Run the following command in your terminal from the directory where the "Makefile" is located:
```
make
```
You can also compile manually by writing the following script:
```
gcc -Wall -Wextra -g main.c file_operations.c -o copy_file
```

### Usage
Make sure the project is compiled using either make or the manual compilation command shown above. Next, run the script:

```
./copy_file
```
