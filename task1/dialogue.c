#include "dialogue.h"


//Dialogue for getting array from user
int *input_array(int *len) {
    int size;

    printf("Enter size of array\n");
    int check = get_int(&size, 0, INT_MAX);

    int *arr = (int *)malloc(size * sizeof(int));
    if (!arr) return NULL;

    printf("Enter elements of array:\n");
    for (int i = 0; i < size; ++i) {
        check = get_int(&arr[i], INT_MIN, INT_MAX);
        if (check != 1) {
            free(arr);
            return NULL;
        }
    }

    *len = size;
    return arr;
}


//Reading int value from user
int get_int (int *x, int left, int right) {
    int op=0;
    do {
        op = scanf("%d", x);
        if (op == EOF)  return EOF;
        if (op == 1) {
                if (((*x) >= left) && ((*x) <= right)) {
					scanf("%*[^\n]");
					scanf("%*c");
					return 1;
				}
                else op = 0;
        }
        if (op == 0) {
			puts("Input error. Wrong data. Try again");
            scanf("%*[^\n]");
        }
    }while (op == 0);
    return op;
}


void output_array(int *arr, int len) {
    for (int i = 0; i < len; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
