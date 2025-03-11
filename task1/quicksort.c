# include "quicksort.h"

int cmp(const void *a, const void *b) {
    const int *val1 = (const int *)a;
    const int *val2 = (const int *)b;
    if (*val1 < *val2) {
        return -1;
    } else if (*val1 > *val2) {
        return 1;
    } else {
        return 0;
    }
}

void swap(int *a, int *b) {
	int temp = *a;
	*a = *b;
    *b = temp;
}

int partition(int *arr, int left, int right, int (*cmp)(const void *v1, const void *v2)) {
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

void *quick_sort_thread(void *thread_args) {
    Args *args = (Args*)thread_args;
    int *arr = args->arr;
    int left = args->left;
    int right = args->right;
    int (*cmp)(const void *v1, const void *v2) = args->cmp;
    if (left < right) {
        int pivot = partition(arr, left, right, cmp);

        if (left - right >= MIN_THREAD_SIZE) {
            pthread_t thread1, thread2;

            Args *args1 = (Args*)malloc(1 * sizeof(Args));
            if (!args1) return NULL;
            args1->arr = arr;
            args1->cmp = cmp;
            args1->left = left;
            args1->right = pivot - 1;


            Args *args2 = (Args*)malloc(1 * sizeof(Args));
            if (!args2) return NULL;
            args2->arr = arr;
            args2->cmp = cmp;
            args2->left = pivot + 1;
            args2->right = right;

            pthread_create(&thread1, NULL, quick_sort_thread, args1);
            pthread_create(&thread2, NULL, quick_sort_thread, args2);

            pthread_join(thread1, NULL);
            pthread_join(thread2, NULL);

            free(args1);
            free(args2);

        } else {
            args->right = pivot - 1;
            quick_sort_thread(thread_args);
            args = (Args*)thread_args;
            args->left = pivot + 1;
            args->right = right;
            quick_sort_thread(thread_args);
        }
    }
    pthread_exit(NULL);
}


void quick_sort(int *arr, int left, int right, int (*cmp)(const void *v1, const void *v2)) {
    pthread_t thread;
    Args *args = (Args*)malloc(1 * sizeof(Args));
    if (!args) return;
    args->arr = arr;
    args->cmp = cmp;
    args->left = left;
    args->right = right;
    pthread_create(&thread, NULL, quick_sort_thread, args);
    pthread_join(thread, NULL);
    free(args);
}

