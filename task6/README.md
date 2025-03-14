# Getting information about files using stat


## Task
Write a C program to get reference information about files
using the stat system call. The file name is passed to the program from the command
line. Get reference information for various file types (regular
file, directory, special byte and block-oriented files)

## Project structure <br>
**main.c** ---- Main program entry point; gets filename, calls stat(), handles errors, and displays results using functions from output_info.c. <br>
**output_info.c** ----  Contains functions to format and display file information (type, permissions, owner name) from the stat() struct.<br>
**output_info.h** ----- Header file declaring the functions in output_info.c.<br>


### Compilation
To compile a project, you can use the provided "Makefile".  Run the following command in your terminal from the directory where the "Makefile" is located:
```
make
```
You can also compile manually by writing the following script:
```
gcc -Wall -Wextra -g main.c output_info.c -o file_info
```

### Usage
Make sure the project is compiled using either make or the manual compilation command shown above. Next, run the script:

```
./file_info
```
