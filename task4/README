# Command line argument parser in C


## Task
Write a command-line argument parser in C (via getopt and
getopt_long). The program accepts the options -m -c -s -t, as well as
----elbrus=[1c+, 2 c+, 2 c3, 4c, 8c, 16c] and any number of non-option strings (without the - and
-- characters in front of them).
You need to parse them in any combination, for example:
prgtms --elbrus=16c file 0 --elbrus=2 c3 file1
(Output example): Options are correct: t, m, c, elbrus=16 c, elbrus=2 c3, non-options:
file0, file1.
prg -tmx --elbrus=16 c file 0
(Output example): Options are incorrect.
Additional task - displaying an incorrect option on the screen

## Project structure <br>
**main.c** ----  The main program entry point. This file contains code for the command-line argument parser.  It uses `getopt_long` to parse options and arguments.<br>


### Compilation
To compile a project, you can use the provided "Makefile".  Run the following command in your terminal from the directory where the "Makefile" is located:
```
make
```
You can also compile manually by writing the following script:
```
gcc -Wall -Wextra -g main.c -o parsing
```

### Usage
Make sure the project is compiled using either make or the manual compilation command shown above. Next, run the script:

```
./parsing
```

