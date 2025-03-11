#pragma once

#include <stdio.h>
#include <sys/stat.h>
#include <time.h>
#include <pwd.h>

void output_info(const struct stat *, const char *); 
void output_file_type(const struct stat *);
void output_owner_name(const struct stat *);
void output_file_permissions(const struct stat *file_info);
