#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct time {
    int year, month, day, hours, minute, second, status, code;
} Struct;

void zero_mode(FILE *file, char *date);
void formatted(int *day, int *month, int *year, char *date);

int main() {
    char *path = malloc(200 * sizeof(char));
    char *date = malloc(200 * sizeof(char));

    scanf("%s", path);

    FILE *file = NULL;
    file = fopen(path, "rb+");

    int shift = -1;

    if (file != NULL) {
        shift = 0;
    } else {
        printf("n/a");
    }

    if (shift == 0) {
        scanf("%s", date);
        zero_mode(file, date);
    }

    fclose(file);
    free(date);
    free(path);
}

void zero_mode(FILE *file, char *date) {
    Struct struct_file;
    fseek(file, 0, SEEK_SET);
    int go = 1;
    int day, month, year;
    formatted(&day, &month, &year, date);
    while (go && fread(&struct_file, sizeof(struct_file), 1, file)) {
        if (day == struct_file.day && month == struct_file.month && year == struct_file.year) {
            printf("%d", struct_file.code);
            go = 0;
        }
    }
    if (go) {
        printf("n/a");
    }
    //    ../datasets/door_state_2
}

void formatted(int *day, int *month, int *year, char *date) {
    char *cur_word = strtok(date, ".");
    if (cur_word != NULL) *day = strtol(cur_word, NULL, 10);
    cur_word = strtok(NULL, ".");
    if (cur_word != NULL) *month = strtol(cur_word, NULL, 10);
    cur_word = strtok(NULL, ".");
    if (cur_word != NULL) *year = strtol(cur_word, NULL, 10);
}