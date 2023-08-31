#include "logger.h"

#include "log_levels.h"

FILE* log_init(char* filename) {
    FILE* file = fopen(filename, "a");
    return file;
}

void logcat(char* filename, char* message, enum log_level level) {
    FILE* file = log_init(filename);
    char answ[1000] = "";
    time_t current_time = time(NULL);
    struct tm* u;
    char time_string[9];
    u = localtime(&current_time);
    strftime(time_string, sizeof(time_string), "%H:%M:%S", u);

    if (level == debug) {
        strcat(answ, "[DEBUG] ");
    } else if (level == info) {
        strcat(answ, "[INFO] ");
    } else if (level == warning) {
        strcat(answ, "[WARNING] ");
    } else if (level == error) {
        strcat(answ, "[ERROR] ");
    }

    strcat(answ, time_string);
    strcat(answ, message);

    fprintf(file, answ);

    log_close(file);
}

void log_close(FILE* file) { fclose(file); }
