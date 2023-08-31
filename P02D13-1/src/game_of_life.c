#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <termios.h>
#include <time.h>
#include <unistd.h>

#define ROWS 25
#define COLUMN 80

int **field_initialization();                         //инициализирует поле
void output(int **matrix);                            //рисует поле
int life_or_die(int **matrix, int rows, int column);  //проверяет жива клетка или нет
void rerender_field(int **matrix, int **twink);  //генерирует следующее поколение
int life(int **matrix, int rows, int column);    //проверяет оживет ли клетка
int die(int **matrix, int rows, int column);     //проверяет умрёт ли живая клетка
int neighbours(int **matrix, int rows, int column);  //считает соседей клетки
int **clone(int **matrix);                           //клонирует матрицу
int kbhit();  //обеспечивает ввод с клавиатуры не прерывая цикл
int extinction(int **matrix);  //проверяет есть ли хоть одна живая клетка

int main() {
    int **field, speed = 100000, exit = 0;

    field = field_initialization();

    printf("\033[0d\033[2J");

    if (freopen("/dev/tty", "r", stdin) == NULL) exit = 1;

    while (exit == 0 && extinction(field)) {
        if (kbhit()) {
            int key = getchar();
            if (key == 'W' || key == 'w') {  // Увеличить скорость
                speed -= 50000;
                if (speed <= 0) speed = 50000;
            } else if (key == 'S' || key == 's') {  // Уменьшить скорость
                speed += 50000;
            } else if (key == 'Q' || key == 'q') {  // Выход из программы
                exit = 1;
            }
        }
        output(field);
        printf("Текущая скорость: %d мс\n", speed / 1000);

        usleep(speed);
        int **twink = clone(field);
        rerender_field(field, twink);
        printf("\033[0d\033[2J");

        free(twink);
    }

    free(field);
    return 0;
}

int **field_initialization() {
    int **matrix = malloc(ROWS * COLUMN * sizeof(int) + ROWS * sizeof(int *));
    int *str = (int *)(matrix + ROWS);
    int m;

    for (int i = 0; i < ROWS; i++) {
        matrix[i] = str + COLUMN * i;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMN; j++) {
            scanf("%d", &m);
            matrix[i][j] = m;
        }
    }

    return matrix;
}

int extinction(int **matrix) {
    int flag = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMN; j++) {
            if (matrix[i][j] == 1) flag = 1;
        }
    }
    return flag;
}

int **clone(int **matrix) {
    int **twink = malloc(ROWS * COLUMN * sizeof(int) + ROWS * sizeof(int *));
    int *str = (int *)(twink + ROWS);

    for (int i = 0; i < ROWS; i++) {
        twink[i] = str + COLUMN * i;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMN; j++) {
            twink[i][j] = matrix[i][j];
        }
    }
    return twink;
}

void output(int **matrix) {
    for (int i = 0; i < ROWS; ++i) {
        if (matrix[i][0] == 0)
            printf(" ");
        else
            printf("o");
        for (int j = 1; j < COLUMN; ++j) {
            if (matrix[i][j] == 0)
                printf(" ");
            else
                printf("o");
        }
        printf("\n");
    }
}

void rerender_field(int **matrix, int **twink) {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLUMN; j++) {
            matrix[i][j] = life_or_die(twink, i, j);
        }
    }
}

int life_or_die(int **matrix, int rows, int column) {
    int result;

    if (matrix[rows][column] == 0) {
        result = life(matrix, rows, column);
    } else {
        result = die(matrix, rows, column);
    }

    return result;
}

int life(int **matrix, int rows, int column) {
    int life = 0, neighbors_count = neighbours(matrix, rows, column);
    if (neighbors_count == 3) {
        life = 1;
    }
    return life;
}

int die(int **matrix, int rows, int column) {
    int die = 1, neighbors_count = neighbours(matrix, rows, column);
    if (neighbors_count < 2 || neighbors_count > 3) {
        die = 0;
    }
    return die;
}

int neighbours(int **matrix, int rows, int column) {
    int neighbors = 0;
    for (int i = -1; i <= 1; i++) {
        for (int j = -1; j <= 1; j++) {
            if (i == 0 && j == 0) continue;  // пропуск ячейки
            int newRow = rows + i;
            int newColumn = column + j;
            if (newRow < 0)
                newRow = ROWS - 1;  // Если новая строка меньше нуля, переносим ее в конец матрицы
            else if (newRow >= ROWS)
                newRow = 0;  // Если новая строка больше или равна ROWS, переносим ее в начало матрицы
            if (newColumn < 0)
                newColumn = COLUMN - 1;  // Если новый столбец меньше нуля, переносим его в конец матрицы
            else if (newColumn >= COLUMN)
                newColumn = 0;  // Если новый столбец больше или равен COLUMNS, переносим его в начало матрицы
            if (matrix[newRow][newColumn] == 1) {  // Проверка жив ли сосед
                neighbors += 1;
            }
        }
    }
    return neighbors;
}

// Функция для проверки нажатия клавиш на клавиатуре
int kbhit() {
    struct timeval tv;
    fd_set read_fd;

    // Установка времени ожидания на 0
    tv.tv_sec = 0;
    tv.tv_usec = 0;

    // Очистка и установка дескриптора
    FD_ZERO(&read_fd);
    FD_SET(0, &read_fd);

    // Проверка дескриптора на наличие данных для чтения
    if (select(1, &read_fd, NULL, NULL, &tv) == -1) return 0;

    if (FD_ISSET(0, &read_fd)) return 1;

    return 0;
}
