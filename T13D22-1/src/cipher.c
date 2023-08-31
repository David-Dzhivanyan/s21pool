#if log
#include "log_levels.h"
#include "logger.h"
#endif

#include <dirent.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void one_mode(char *path, char *file_text, FILE *file, int *is_empty);
void two_mode(char *path, char *file_text, char *input, FILE *file, int *is_empty);
void three_mode();
void cipher(char *path, int shift);
void clear(char *path);

int main() {
    char *path = malloc(100 * sizeof(char));
    char *input = malloc(100 * sizeof(char));
    char *file_text = malloc(100 * sizeof(char));
    int mode = 0;
    int is_empty = 0;
    FILE *file = NULL;

    while (mode != -1) {
        mode = 0;
        scanf("%d", &mode);
        if (mode == 1) {
            one_mode(path, file_text, file, &is_empty);
            printf("\n");
        } else if (mode == 2) {
            two_mode(path, file_text, input, file, &is_empty);
            printf("\n");
        } else if (mode == 3) {
            three_mode();
        }
    }

    free(input);
    free(path);
    free(file_text);
}

void one_mode(char *path, char *file_text, FILE *file, int *is_empty) {
    scanf("%s", path);
    file = fopen(path, "r");
    if (file != NULL) {
        while (fgets(file_text, 100, file) != NULL) {
            printf("%s", file_text);
        }
        if (strcmp(file_text, "") == 0) {
            printf("n/a");
#if log
            char str[1000] = " Файл пуст ";
            strcat(str, path);
            strcat(str, "\n");
            logcat("./log_file.txt", str, error);
#endif

            *is_empty = 1;
        } else {
#if log
            char str[1000] = " Открыт файл ";
            strcat(str, path);
            strcat(str, "\n");
            logcat("./log_file.txt", str, info);
#endif
        }
    } else {
        printf("n/a");
#if log
        char str[1000] = " Указан неверный путь\n";
        logcat("./log_file.txt", str, error);
#endif
        strcpy(path, "");
    }
    fclose(file);
}

void two_mode(char *path, char *file_text, char *input, FILE *file, int *is_empty) {
    scanf("%s", input);
    strcat(input, "\n");
    file = fopen(path, "a");
    if (file != NULL && !*is_empty) {
        fprintf(file, input);
        fclose(file);
        file = fopen(path, "r");
        strcpy(file_text, "");
        while (fgets(file_text, 100, file) != NULL) {
            printf("%s", file_text);
        }
        if (strcmp(file_text, "") == 0) {
            printf("n/a");
#if log
            char str[1000] = " Пустой файл ";
            strcat(str, path);
            strcat(str, "\n");
            logcat("./log_file.txt", str, error);
#endif

        } else {
#if log
            char str[1000] = " В файл ";
            strcat(str, path);
            strcat(str, " добавлена строка ");
            strcat(str, input);
            logcat("./log_file.txt", str, info);
#endif
        }
    } else {
        printf("n/a");
#if log
        char str[1000] = " Путь к файлу неопределён\n";
        logcat("./log_file.txt", str, error);
#endif
    }

    fclose(file);
}

void three_mode() {
    char path[100] = "", path_directory[100] = "";
    int shift = 0;
    scanf("%s", path);
    scanf("%d", &shift);
    strcpy(path_directory, path);
    strcat(path_directory, "/");
    DIR *dir = opendir(path_directory);
    struct dirent *dir_file;
    if (dir != NULL) {
        while ((dir_file = readdir(dir))) {
            size_t flen = strlen(dir_file->d_name);
            strcpy(path, path_directory);
            strcat(path, dir_file->d_name);

            if (flen > 2 && strcmp((dir_file->d_name) + flen - 2, ".c") == 0) {
                cipher(path, shift);
            }

            if (flen > 2 && strcmp((dir_file->d_name) + flen - 2, ".h") == 0) {
                clear(path);
            }

            strcpy(path, "./");
        }
#if log
        char str[1000] = " Файлы с расширением .с зашифрованы со сдвигом ";
        char num[100] = "";
        snprintf(num, 100, "%d", shift);
        strcat(str, num);
        strcat(str, "\n");
        logcat("./log_file.txt", str, info);

        strcpy(str, "");

        strcat(str, " Файлы с расширением .h очищены\n");
        logcat("./log_file.txt", str, info);
#endif
        closedir(dir);
    } else {
        printf("n/a\n");
#if log
        char str[1000] = " Указана неверная директория\n";
        logcat("./log_file.txt", str, error);
#endif
    }
}

void cipher(char *path, int shift) {
    FILE *file;
    char file_text[1000], full_file[1000] = "";
    int count = 0;

    file = fopen(path, "r");
    while (fgets(file_text, 100, file) != NULL) {
        strcat(full_file, file_text);
    }
    fclose(file);

    while (full_file[count] != '\0') {
        full_file[count] = full_file[count] + shift % 128;
        count += 1;
    }

    file = fopen(path, "w");
    fprintf(file, full_file);
    fclose(file);
}

void clear(char *path) {
    FILE *file;
    file = fopen(path, "w");
    fclose(file);
}