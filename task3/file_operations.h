#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "string_operations.h"

char **read_from_file(const char *, int *);

int write_to_file(char **, int, const char *);

void free_lines(char **, int);