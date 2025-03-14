#pragma once

#include <stdio.h>
#include <string.h>
#include <ctype.h>


char *trim(char *);

int compare_alphabetical(const void *, const void *);

int compare_length(const void *, const void *);

int compare_reverse_alphabetical(const void *, const void *);