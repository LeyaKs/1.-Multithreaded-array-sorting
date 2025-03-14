# Multithreaded array sorting (pthreads)


## Task
Write a multithreaded C program using the pthreads library to sort an array in parallel using any method.

## Project structure <br>
**main.c** ----  The main program. Handles user input (array size and elements), initializes the array, launches the parallel sort, and prints the sorted array.<br>
**dialogue.c** ----  Contains functions for user interaction: getting the array size and elements from the user.<br>
**quicksort.c** ---- Implements the parallel quicksort algorithm using pthreads. This includes the recursive partitioning and thread management.<br>
**dialogue.h** ----- The header file for `dialogue.c`.<br>
**quicksort.h** ---- The header file for `quicksort.c`. It declares the function prototypes, the `Args` struct (used to pass data to threads)<br>


### Compilation
To compile a project, you can use the provided "Makefile".  Run the following command in your terminal from the directory where the "Makefile" is located:
```
make
```
You can also compile manually by writing the following script:
```
gcc -Wall -Wextra -g main.c quicksort.c dialogue.c -o quicksort
```

### Usage
Make sure the project is compiled using either make or the manual compilation command shown above. Next, run the script:

```
./quicksort
```

