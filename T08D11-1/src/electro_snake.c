#include <stdio.h>
#include <stdlib.h>
/*
    1 6 7
    2 5 8
    3 4 9
*/

/*
    1 2 3
    6 5 4
    7 8 9
*/
void sort_horizontal(int **matrix, int rows, int column);
int **input_matrix(int rows, int column, int *flag);
void output(int **matrix, int rows, int column, int flag);
void input_size(int *rows, int *column, int *flag);

int main() {
  int **matrix;
  int rows, column, flag = 1;
  input_size(&rows, &column, &flag);
  if (flag){
      matrix = input_matrix(rows, column, &flag);

      output(matrix, rows, column, flag);

      sort_horizontal(matrix, rows, column);

      printf("\n\n");

      output(matrix, rows, column, flag);
  }else{
      printf("n/a");
  }

  free(matrix);
  return 0;
}

void input_size(int *rows, int *column, int *flag) {

  if (scanf("%d %d", rows, column) != 2 || (*rows <= 0 || *column <= 0)) {
    *flag = 0;
  }
}

int **input_matrix(int rows, int column, int *flag) {
  int **matrix = malloc(rows * column * sizeof(int) + rows * sizeof(int *));
  int *str = (int *)(matrix + rows);
  int m;

  for (int i = 0; i < rows; i++) {
    matrix[i] = str + column * i;
  }
  if (NULL == matrix || NULL == str) {
    *flag = 0;
  }

  if (flag) {
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < column; j++) {
        if (scanf("%d", &m) != 1) {
          *flag = 0;
        }
        matrix[i][j] = m;
      }
    }
  }

  return matrix;
}

void output(int **matrix, int rows, int column, int flag) {
  if (flag) {
    for (int i = 0; i < rows; ++i) {
      printf("%d", matrix[i][0]);
      for (int j = 1; j < column; ++j) {
        printf(" %d", matrix[i][j]);
      }
      if (i != rows - 1)
        printf("\n");
    }
  } else {
    printf("n/a");
  }
}

void sort_horizontal(int **matrix, int rows, int column) {
  int length = rows * column;
  while (length--) {
    int direction = 1;
    for (int i = 0; i < rows; i++) {
      for (int j = 0; j < column; j++) {
        if (direction && j < column - 1 && matrix[i][j + 1] < matrix[i][j]) {
          int twink = matrix[i][j];
          matrix[i][j] = matrix[i][j + 1];
          matrix[i][j + 1] = twink;
        } else if (direction && j == column - 1 && i < rows - 1 &&
                   matrix[i + 1][j] < matrix[i][j]) {
          int twink = matrix[i][j];
          matrix[i][j] = matrix[i + 1][j];
          matrix[i + 1][j] = twink;
        } else if (!direction && j < column - 1 &&
                   matrix[i][j + 1] > matrix[i][j]) {
          int twink = matrix[i][j];
          matrix[i][j] = matrix[i][j + 1];
          matrix[i][j + 1] = twink;
        } else if (!direction && j == 0 && i < rows - 1 &&
                   matrix[i + 1][j] < matrix[i][j]) {
          int twink = matrix[i][j];
          matrix[i][j] = matrix[i + 1][j];
          matrix[i + 1][j] = twink;
        }
      }
      direction = !direction;
    }
  }
}
