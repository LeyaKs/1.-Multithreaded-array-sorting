#include <stdio.h>
#include "quicksort.h"
#include "dialogue.h"



int main() {
    srand(time(NULL));

    int len = 0;
    int *arr = input_array(&len);       //Enter array by user

    quick_sort(arr, 0, len - 1, cmp);   //Sorting
    output_array(arr, len);             //Print array after sorting
    free(arr);

    return 0;
}