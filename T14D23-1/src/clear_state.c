#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct time {
    int year, month, day, hours, minute, second, status, code;
} Struct;
long int str_in_num(Struct struct_file);
void zero_mode(FILE *file, char *date_start, char *date_end, char *path);
int formatted(int *day, int *month, int *year, char *date);
void print(FILE *file);

int main() {
    char *path = malloc(200 * sizeof(char));
    char *date_start = malloc(200 * sizeof(char));
    char *date_end = malloc(200 * sizeof(char));

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
        scanf("%s", date_start);
        scanf("%s", date_end);
        zero_mode(file, date_start, date_end, path);
        fclose(file);
        file = fopen(path, "rb+");
        print(file);
        fclose(file);
    }

    free(date_end);
    free(date_start);
    free(path);
}

void zero_mode(FILE *file, char *date_start, char *date_end, char *path) {
    Struct struct_file;
    FILE *temp = NULL;
    char path_temp[100];
    strcpy(path_temp, path);
    strcat(path_temp, "1");
    temp = fopen(path_temp, "wb");
    fseek(file, 0, SEEK_SET);
    int day_start, month_start, year_start;
    int day_end, month_end, year_end;
    long int num_start = formatted(&day_start, &month_start, &year_start, date_start);
    long int num_end = formatted(&day_end, &month_end, &year_end, date_end);
    while (fread(&struct_file, sizeof(struct_file), 1, file)) {
        long int num = str_in_num(struct_file);
        if (!(num > num_start && num < num_end)) {
            fwrite(&struct_file, sizeof(struct_file), 1, temp);
        }
    }
    rename(path_temp, path);
}

void print(FILE *file) {
    Struct struct_file;
    fseek(file, 0, SEEK_SET);
    while (fread(&struct_file, sizeof(struct_file), 1, file)) {
        printf("%d %d %d %d %d %d %d %d\n", struct_file.year, struct_file.month, struct_file.day,
               struct_file.hours, struct_file.minute, struct_file.second, struct_file.status,
               struct_file.code);
    }
    //    ../datasets/door_state_1
}

int formatted(int *day, int *month, int *year, char *date) {
    char str[100] = "";
    char num[100] = "";
    char *cur_word = strtok(date, ".");
    if (cur_word != NULL) *day = strtol(cur_word, NULL, 10);
    cur_word = strtok(NULL, ".");
    if (cur_word != NULL) *month = strtol(cur_word, NULL, 10);
    cur_word = strtok(NULL, ".");
    if (cur_word != NULL) *year = strtol(cur_word, NULL, 10);

    snprintf(num, 10, "%d", *year);
    strcat(str, num);
    snprintf(num, 10, "%02d", *month);
    strcat(str, num);
    snprintf(num, 10, "%02d", *day);
    strcat(str, num);

    return strtol(str, NULL, 10);
}
long int str_in_num(Struct struct_file) {
    char num[10] = "";
    char str[100] = "";
    snprintf(num, 10, "%d", struct_file.year);
    strcat(str, num);
    snprintf(num, 10, "%02d", struct_file.month);
    strcat(str, num);
    snprintf(num, 10, "%02d", struct_file.day);
    strcat(str, num);
    return strtol(str, NULL, 10);
}
