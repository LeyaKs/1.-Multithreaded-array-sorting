#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include <time.h>

#define LEN 20
#define MIN -1000
#define MAX 1000

void output_array(int *arr, int first, int last) {
    for (int i = first; i <= last; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int* random_array(int* size) {
    *size = 1 + rand() % LEN;
    int *arr = (int *)malloc(*size * sizeof(int));
    if (!arr) return NULL;
    for (int i = 0; i < *size; ++i) {
        arr[i] = MIN + rand() % (MAX - MIN + 1);
    }
    return arr;
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
    srand(time(NULL));
    int size;
    int *arr = random_array(&size);     //Generate random array
    if (!arr) return 1;
    output_array(arr, 0, size - 1);     //Print array before processing
    int last_elem = 0;
    int first_elem = max_sequence(arr, &last_elem, size);
    output_array(arr, first_elem, last_elem);       //Print array after processing
    free(arr);

    return 0;
}