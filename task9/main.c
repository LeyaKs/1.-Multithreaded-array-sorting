#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

#define LEN 9

void output_array(int *arr, int first, int last) {
    for (int i = first; i <= last; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}


int max_sequence(int *arr, int *last_elem, int size) {
    int curr_sum = arr[0];
    int max_sum = curr_sum;
    int first_elem = 0, max_first_elem = 0;
    for (int i = 1; i < size; ++i) {
        if (arr[i] <= arr[i - 1]) {
            if (max_sum < curr_sum) {
                max_sum = curr_sum;
                *last_elem = i - 1;
                max_first_elem = first_elem;
            }
            curr_sum = 0;
            first_elem = i;
        }
        curr_sum += arr[i];
    }
    if (max_sum < curr_sum) {
        *last_elem = size - 1;
        max_first_elem = first_elem;
    }
    return max_first_elem;
}



int main() {

    int *arr = (int *)malloc(LEN * sizeof(int));
    if (!arr) return 0;
    arr[0] = 200;
    arr[1] = 201;
    arr[2] = 200;
    arr[3] = 200;
    arr[4] = 200;
    arr[5] = 200;
    arr[6] = 200;
    arr[7] = 200;
    arr[8] = 201;

    int last_elem = 0;
    int first_elem = max_sequence(arr, &last_elem, LEN);
    output_array(arr, first_elem, last_elem);
    free(arr);

    return 0;
}