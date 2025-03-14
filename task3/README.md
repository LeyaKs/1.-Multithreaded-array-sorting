# Multivariate sorting of text file lines


## Task
Write a program in C: Sort the lines of a text file in various ways. The program has 3 command line arguments: input file (arbitrary size without restrictions),
output file, sorting method. Sort the input file using the specified method, delete empty lines without visible characters, and output the sorted data to the output file and to the screen.

## Project structure <br>
**main.c** ----  The main program entry point.  Handles command-line argument parsing, calls functions to read the input file, perform the sorting, write the output file, and cleans up memory.<br>
**file_operations.c** ----  Implements functions for reading and writing to files.  This includes reading lines from the input file and writing the sorted lines to the output file.  Handles file I/O operations.<br>
**string_operations.c** ---- Contains functions for processing strings, such as removing leading/trailing whitespace (trimming) and comparing strings for sorting.  Handles string manipulation.<br>
**file_operations.h** ----- The header file for `file_operations.c`. Declares the function prototypes for file operations.<br>
**string_operations.h** ---- The header file for `string_operations..c`. Declares the function prototypes for string functions<br>


### Compilation
To compile a project, you can use the provided "Makefile".  Run the following command in your terminal from the directory where the "Makefile" is located:
```
make
```
You can also compile manually by writing the following script:
```
gcc -Wall -Wextra -g main.c file_operations string_operations.c -o sorting_strings
```

### Usage
Make sure the project is compiled using either make or the manual compilation command shown above. Next, run the script:

```
./sorting_strings
```

