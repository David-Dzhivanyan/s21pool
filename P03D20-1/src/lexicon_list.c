#include "lexicon_list.h"

char *lexicon_main() {
    char *answ = malloc(SIZE * sizeof(char));
    int flag = 1;

    fgets(answ, SIZE, stdin);

    formatting(answ, &flag);

    return flag ? answ : NULL;
}

void formatting(char *str, int *flag) {
    del_space(str);

    char answ[SIZE];
    int count = 0, i = 0;
    while (str[i] != '\0' && flag) {
        if (str[i] == 's') {
            if (str[i + 1] == 'i') {
                *flag = operand_validity(str, i, "sin");
                if (*flag) {
                    answ[count] = str[i];
                    count += 1;
                    i += 3;
                }
            } else if (str[i + 1] == 'q') {
                *flag = operand_validity(str, i, "sqrt");
                if (*flag) {
                    answ[count] = 'S';
                    count += 1;
                    i += 4;
                }
            }
        } else if (str[i] == 'c') {
            if (str[i + 1] == 'o') {
                *flag = operand_validity(str, i, "cos");
                if (*flag) {
                    answ[count] = str[i];
                    count += 1;
                    i += 3;
                }
            } else if (str[i + 1] == 't') {
                *flag = operand_validity(str, i, "ctg");
                if (*flag) {
                    answ[count] = 'C';
                    count += 1;
                    i += 3;
                }
            }
        } else if (str[i] == 't') {
            *flag = operand_validity(str, i, "tan");
            if (*flag) {
                answ[count] = str[i];
                count += 1;
                i += 3;
            }
        } else if (str[i] == 'l') {
            *flag = operand_validity(str, i, "ln");
            if (*flag) {
                answ[count] = str[i];
                count += 1;
                i += 2;
            }
        } else {
            answ[count] = str[i];
            count += 1;
            i++;
        }
    }
    if (answ[count]) answ[count] = '\0';
    strcpy(str, answ);
}

int operand_validity(const char *str, int i, const char operand[5]) {
    int count = 0, flag = 1;
    while (operand[count] != '\0' && flag) {
        if (str[i] != operand[count]) {
            flag = 0;
        }
        count += 1;
        i++;
    }
    return flag;
}

void del_space(char *str) {
    char answ[SIZE];
    int count = 0, i = 0;
    while (str[i] != '\n') {
        if (str[i] != ' ') {
            answ[count] = str[i];
            count += 1;
        }
        i++;
    }
    answ[count] = '\0';
    strcpy(str, answ);
}