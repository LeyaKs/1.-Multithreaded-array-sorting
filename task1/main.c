#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define LEN 10

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right, int (*cmp)(const void *v1, const void *v2)) {
    srand(time(NULL));
	int pivot_index = left + rand() % (right - left + 1);
    int pivot = arr[pivot_index];
    swap(&arr[pivot_index], &arr[right]);
	int i = left - 1;
	for (int j = left; j <= right; ++j) {
		if (cmp(&arr[j], &pivot) < 0) {
            ++i;
		    swap(&arr[i], &arr[j]);
        }
	}
    swap(&arr[i + 1], &arr[right]);
	return i + 1;
}


void quick_sort(int *arr, int left, int right, int (*cmp)(const void *v1, const void *v2)) {
	if (left < right - 1) {
		int pivot = partition(arr, left, right, cmp);
		quick_sort(arr, left, pivot, cmp);
		quick_sort(arr, pivot + 1, right, cmp);
	}
}


void output_arr(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int cmp(const void *a, const void *b) {
       const int *val1 = (const int *)a;
       const int *val2 = (const int *)b;
       return *val1 - *val2;
   }



int main() {
    int *arr = (int *)malloc(LEN * sizeof(int));
    if (!arr) return 0;
    arr[0] = 12;
    arr[1] = 13;
    arr[2] = 1;
    arr[3] = 10;
    arr[4] = 3;
    arr[5] = 4;
    arr[6] = 12;
    arr[7] = 6;
    arr[8] = 7;
    arr[9] = 0;

    quick_sort(arr, 0, LEN - 1, cmp);
    output_arr(arr, LEN);
    free(arr);

    return 0;
}