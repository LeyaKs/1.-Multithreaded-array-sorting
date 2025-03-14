# Finding the increasing subsequence with the maximum sum


## Task
Write a program in any language that implements the following algorithm: Given a finite one-dimensional array of random integers. Find the maximum
continuous sequence of numbers with the maximum sum of elements in it.
A continuous sequence means that each successive
number is greater than the previous one.

## Project structure <br>
**main.c** ----  The main program entry point. It includes array generation, searching for a subsequence, and printing the result<br>


### Compilation
To compile a project, you can use the provided "Makefile".  Run the following command in your terminal from the directory where the "Makefile" is located:
```
make
```
You can also compile manually by writing the following script:
```
gcc -Wall -Wextra -g main.c -o sequence
```

### Usage
Make sure the project is compiled using either make or the manual compilation command shown above. Next, run the script:

```
./sequence
```
