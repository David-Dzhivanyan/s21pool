#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

typedef struct time {
    int year, month, day, hours, minute, second, status, code;
} Struct;

long int str_in_num(Struct struct_file);
void zero_mode(FILE *file);
void one_mod(FILE *file);
void two_mod(FILE *file);
int file_count(FILE *file);
void swap(FILE *file, int j, Struct struct_file, Struct struct_file2);

int main() {
    char *path = malloc(200 * sizeof(char));

    scanf("%s", path);

    FILE *file = NULL;
    file = fopen(path, "rb+");

    int shift = -1;

    if (file != NULL) {
        scanf("%d", &shift);
    } else {
        printf("n/a");
    }

    if (shift == 0) {
        zero_mode(file);
    } else if (shift == 1) {
        one_mod(file);
        zero_mode(file);
    } else if (shift == 2) {
        two_mod(file);
        one_mod(file);
        zero_mode(file);
    }

    fclose(file);
    free(path);
}

void zero_mode(FILE *file) {
    Struct struct_file;
    fseek(file, 0, SEEK_SET);
    while (fread(&struct_file, sizeof(struct_file), 1, file)) {
        printf("%d %d %d %d %d %d %d %d\n", struct_file.year, struct_file.month, struct_file.day,
               struct_file.hours, struct_file.minute, struct_file.second, struct_file.status,
               struct_file.code);
    }
    //    ../datasets/door_state_1
}

void one_mod(FILE *file) {
    Struct struct_file;
    Struct struct_file2;

    int loop = file_count(file);
    fseek(file, 0, SEEK_SET);
    for (int i = 0; i < loop; ++i) {
        for (int j = 0; j < loop; ++j) {
            fseek(file, j * sizeof(struct_file), SEEK_SET);
            fread(&struct_file, sizeof(struct_file), 1, file);
            long int num = str_in_num(struct_file);
            fseek(file, (j + 1) * sizeof(struct_file), SEEK_SET);
            fread(&struct_file2, sizeof(struct_file), 1, file);
            long int num2 = str_in_num(struct_file2);
            if (num > num2) {
                swap(file, j, struct_file, struct_file2);
            }
        }
    }
    //        ../datasets/door_state_1
}

void two_mod(FILE *file) {
    Struct struct_file;
    fseek(file, 0, SEEK_SET);
    if (scanf("%d %d %d %d %d %d %d %d", &struct_file.year, &struct_file.month, &struct_file.day,
              &struct_file.hours, &struct_file.minute, &struct_file.second, &struct_file.status,
              &struct_file.code) == 8) {
        fseek(file, 0, SEEK_END);
        fwrite(&struct_file, sizeof(struct_file), 1, file);
    }
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
    snprintf(num, 10, "%02d", struct_file.hours);
    strcat(str, num);
    snprintf(num, 10, "%02d", struct_file.minute);
    strcat(str, num);
    snprintf(num, 10, "%02d", struct_file.second);
    strcat(str, num);
    return strtol(str, NULL, 10);
}

void swap(FILE *file, int j, Struct struct_file, Struct struct_file2) {
    fseek(file, j * sizeof(struct_file), SEEK_SET);
    fwrite(&struct_file2, sizeof(struct_file), 1, file);
    int index = (j + 1) * sizeof(struct_file);
    fseek(file, index, SEEK_SET);
    fwrite(&struct_file, sizeof(struct_file), 1, file);
}

int file_count(FILE *file) {
    Struct struct_file;
    int answ = 0;
    fseek(file, 0, SEEK_SET);
    while (fread(&struct_file, sizeof(struct_file), 1, file)) {
        answ++;
    }
    return answ;
}