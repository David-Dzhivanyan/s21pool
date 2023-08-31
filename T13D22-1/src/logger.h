#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#include "log_levels.h"

#ifndef LOGGER_H
#define LOGGER_H

FILE *log_init(char *path);
void logcat(char *path, char *message, enum log_level level);
void log_close(FILE *file);

#endif
