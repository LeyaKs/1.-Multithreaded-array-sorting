# Logical expression parser


## Task
Develop a logical expression parser in C or C++ that calculates the values of variables. Example of an expression: (A AND B) OR (C AND NOT D)

## Project structure <br>
**main.cpp** ----  The main program file. This is where the expression and variable values are entered, the parser is called, and the result is output.<br>
**funcs.cpp** ---- A file with the implementation of functions for parsing and calculating a logical expression.<br>
**funcs.h** ----- A header file declaring function prototypes from funcs.cpp .<br>


### Compilation
To compile a project, you can use the provided "Makefile".  Run the following command in your terminal from the directory where the "Makefile" is located:
```
make
```
You can also compile manually by writing the following script:
```
gcc -Wall -Wextra -g main.cpp funcs.cpp -o logical_expression
```

### Usage
Make sure the project is compiled using either make or the manual compilation command shown above. Next, run the script:

```
./logical_expression
```
