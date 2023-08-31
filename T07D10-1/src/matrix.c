#include <stdio.h>
#include <stdlib.h>
#define NSTAT 100

int input_size(int *N, int *M, int opt);
void stat(int matrix[NSTAT][NSTAT], int N, int M);
void dyn_one(int N, int M);
void dyn_two(int N, int M);
void dyn_three(int N, int M);
void output(int **matrix, int N, int M, int flag);
void input(int **matrix, int N, int M, int *flag);

int main() {
    int opt, matrix[NSTAT][NSTAT] = {0}, N, M;
    printf(
        "Выбирете способ записи матрицы:\n1 - статический ограничения по размеру 100 на 100\n2 - "
        "динамический\n3 - динамический\n4 - динамический\n");
    if (scanf("%d", &opt) != 1 || opt > 4 || opt <= 0) {
        printf("n/a");
    } else if (input_size(&N, &M, opt)) {
        if (opt == 1) {
            stat(matrix, N, M);
        } else if (opt == 2) {
            dyn_one(N, M);
        } else if (opt == 3) {
            dyn_two(N, M);
        } else {
            dyn_three(N, M);
        }
    } else {
        printf("n/a");
    }
    return 0;
}

int input_size(int *N, int *M, int opt) {
    int flag = 1;
    if (scanf("%d %d", N, M) != 2 || ((*N <= 0 || *N > NSTAT || *M <= 0 || *M > NSTAT) && opt == 1) ||
        (*N <= 0 || *M <= 0)) {
        flag = 0;
    }

    return flag;
}

void stat(int matrix[NSTAT][NSTAT], int N, int M) {
    int flag = 1, m;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            if (scanf("%d", &m) != 1) {
                flag = 0;
            }
            matrix[i][j] = m;
        }
    }

    if (flag) {
        for (int i = 0; i < N; ++i) {
            printf("%d", matrix[i][0]);
            for (int j = 1; j < M; ++j) {
                printf(" %d", matrix[i][j]);
            }
            if (i != N - 1) printf("\n");
        }
    } else {
        printf("n/a");
    }
}

void dyn_one(int N, int M) {
    int **matrix = malloc(N * M * sizeof(int) + N * sizeof(int *));
    int *str = (int *)(matrix + N);
    int flag = 1;

    for (int i = 0; i < N; i++) {
        matrix[i] = str + M * i;
    }

    if (NULL == matrix || NULL == str) {
        flag = 0;
    }

    input(matrix, N, M, &flag);
    output(matrix, N, M, flag);

    free(matrix);
}

void dyn_two(int N, int M) {
    int flag = 1;
    int **matrix = malloc(N * sizeof(int *));
    for (int i = 0; i < N; i++) {
        matrix[i] = malloc(M * sizeof(int));
        if (NULL == matrix[i]) {
            flag = 0;
        }
    }
    if (NULL == matrix) {
        flag = 0;
    }

    input(matrix, N, M, &flag);
    output(matrix, N, M, flag);

    for (int i = 0; i < N; i++) {
        free(matrix[i]);
    }

    free(matrix);
}

void dyn_three(int N, int M) {
    int **matrix = malloc(N * sizeof(int *));
    int *str = malloc(M * N * sizeof(int));
    int flag = 1;

    for (int i = 0; i < N; i++) {
        matrix[i] = str + M * i;
    }

    if (NULL == matrix || NULL == str) {
        flag = 0;
    }

    input(matrix, N, M, &flag);
    output(matrix, N, M, flag);

    free(str);
    free(matrix);
}

void input(int **matrix, int N, int M, int *flag) {
    int m;

    if (flag) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (scanf("%d", &m) != 1) {
                    *flag = 0;
                }
                matrix[i][j] = m;
            }
        }
    }
}

void output(int **matrix, int N, int M, int flag) {
    if (flag) {
        for (int i = 0; i < N; ++i) {
            printf("%d", matrix[i][0]);
            for (int j = 1; j < M; ++j) {
                printf(" %d", matrix[i][j]);
            }
            if (i != N - 1) printf("\n");
        }
    } else {
        printf("n/a");
    }
}
