#include <stdio.h>
#include "quicksort.h"
#include "dialogue.h"



int main() {
    srand(time(NULL));

    int len = 0;
    int *arr = input_array(&len);

    quick_sort(arr, 0, len - 1, cmp);
    output_array(arr, len);
    free(arr);

    return 0;
}