# CError handling of system calls in C


## Task
Write a program in C that executes some system
call, such as open, and then outputs the returned error. Use
different ways to output an error message in the program: output the errno value, output
the corresponding message from the system array of error messages sys_errlist[],
calling the perror library function.

## Project structure <br>
**main.c** ----  The main program entry point. This file contains code for demonstrating error handling with the `open` system call.<br>


### Compilation
To compile a project, you can use the provided "Makefile".  Run the following command in your terminal from the directory where the "Makefile" is located:
```
make
```
You can also compile manually by writing the following script:
```
gcc -Wall -Wextra -g main.c -o error_message
```

### Usage
Make sure the project is compiled using either make or the manual compilation command shown above. Next, run the script:

```
./error_message
```

