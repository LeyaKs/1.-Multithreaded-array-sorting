#pragma once

#include <stdlib.h>
#include <time.h>
#include <pthread.h>

#define MIN_THREAD_SIZE 3

typedef struct {
    int *arr;
    int left;
    int right;
    int (*cmp)(const void *v1, const void *v2);
} Args;


int cmp(const void *, const void *);

void swap(int *, int *);

int partition(int *arr, int, int, int (*cmp)(const void *v1, const void *v2));

void *quick_sort_thread(void *);

void quick_sort(int *, int, int, int (*cmp)(const void *v1, const void *v2));

