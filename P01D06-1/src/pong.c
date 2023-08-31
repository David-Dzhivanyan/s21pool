#include <stdio.h>

int directResolver(char dir, int n);
int goalChecker(int x_ball, int x_max);
int mvRacket(int player, int racket, int btn, int y_max);
int render(int x_ball, int y_ball, int x_max, int y_max, int racket1, int racket2, int player1Score,
           int player2Score);
int fieldRender(int x_ball, int y_ball, int y_max, int x_max, int racket1, int racket2, int player1Score,
                int player2Score);
char dirSwitcher(char dir);

int main() {
    const int x_max = 86, y_max = 27;
    int btn, enter, finish = 0, x = 3, y = y_max / 2, racket1 = y_max / 2 - 1, racket2 = y_max / 2 - 1, goal,
                    player1Score = 0, player2Score = 0;
    char x_dir = 'u', y_dir = 'u';
    render(x, y, x_max, y_max, racket1, racket2, player1Score, player2Score);
    while (finish != 1) {
        btn = getchar();
        enter = getchar();
        fflush(stdin);
        if (enter != 10 || (btn != 32 && btn != 122 && btn != 97 && btn != 107 && btn != 109)) {
            render(x, y, x_max, y_max, racket1, racket2, player1Score, player2Score);
            btn = 0;
            continue;
        }
        x = directResolver(x_dir, x);
        y = directResolver(y_dir, y);
        racket1 = mvRacket(1, racket1, btn, y_max);
        racket2 = mvRacket(2, racket2, btn, y_max);
        goal = goalChecker(x, x_max);
        if (goal) {
            if (x == 2) {
                x = 3;
                y = racket1 + 1, x_dir = 'u';
                player2Score = player2Score + 1;
            } else if (x == (x_max - 2)) {
                x = x_max - 3;
                y = racket2 + 1, x_dir = 'd';
                player1Score = player1Score + 1;
            }
            y_dir = dirSwitcher(y_dir);
        }
        if (x == 3 && y == 1) {  // левый верхний угол
            if (racket1 == 1) {
                x_dir = 'u', y_dir = 'u';
            } else {
                y_dir = 'u';
            }
        } else if (y == (y_max - 1) && x == 3) {  // левый нижний угол
            if (racket1 + 2 == y_max - 1) {
                x_dir = 'u', y_dir = 'd';
            } else {
                y_dir = 'd';
            }
        } else if (y == (y_max - 1) && x == (x_max - 3)) {  // правый нижний угол
            if (racket2 + 2 == y_max - 1) {
                x_dir = 'd', y_dir = 'd';
            } else {
                y_dir = 'd';
            }
        } else if (y == 1 && x == (x_max - 3)) {  // правый верхний угол
            if (racket2 == 1) {
                x_dir = 'd', y_dir = 'u';
            } else {
                y_dir = 'u';
            }
        } else if (y == (y_max - 1) && 0 < x && x < x_max) {  // нижняя стенка
            y_dir = 'd';
        } else if (x == (x_max - 3) && 0 < y && y < y_max) {  // правая стенка
            if (y >= racket2 && y <= racket2 + 2) {
                x_dir = 'd';
            }
        } else if (y == 1 && 0 < x && x < x_max) {  // верхняя стенка
            y_dir = 'u';
        } else if (x == 3 && 0 < y && y < y_max) {  // левая стенка
            if (y >= racket1 && y <= racket1 + 2) {
                x_dir = 'u';
            }
        }
        finish = render(x, y, x_max, y_max, racket1, racket2, player1Score, player2Score);
    }
}

char dirSwitcher(char dir) {
    if (dir == 'u') {
        return 'd';
    } else {
        return 'u';
    }
}

int goalChecker(int x_ball, int x_max) {
    if (x_ball == 2) {
        return 1;
    } else if (x_ball == (x_max - 2)) {
        return 1;
    }
    return 0;
}

int directResolver(char dir, int n) {
    if (dir == 'u') {
        return n += 1;
    } else
        return n -= 1;
}

int render(int x_ball, int y_ball, int x_max, int y_max, int racket1, int racket2, int player1Score,
           int player2Score) {
    printf("\e[1;1H\e[2J");
    if (player1Score == 21 || player2Score == 21) {
        int winner;
        if (player1Score == 21) {
            winner = 1;
        } else {
            winner = 2;
        }
        printf("Player %d won!!!\n", winner);
        return 1;
    }
    fieldRender(x_ball, y_ball, y_max, x_max, racket1, racket2, player1Score, player2Score);
    return 0;
}

int fieldRender(int x_ball, int y_ball, int y_max, int x_max, int racket1, int racket2, int player1Score,
                int player2Score) {
    for (int i = -1; i <= y_max; i++) {
        for (int j = 0; j <= x_max; j++) {
            if (i == -1) {
                if (j < x_max / 2 - 2) {
                    printf(" ");
                } else if (j == x_max / 2 - 2) {
                    printf("%d : %d", player1Score, player2Score);
                }
            } else if ((i == 0 && (j == 0 || j == x_max)) || (i == y_max && (j == 0 || j == x_max))) {
                printf("+");
            } else if (i == 0 || i == y_max) {
                printf("-");
            } else if (j == 0 || j == x_max) {
                printf("|");
            } else if (j == x_ball && i == y_ball) {
                printf("o");
            } else {
                if (j == 2 && i >= racket1 && i <= racket1 + 2) {
                    printf("]");
                } else if (j == x_max - 2 && i >= racket2 && i <= racket2 + 2) {
                    printf("[");
                } else {
                    printf(" ");
                }
            }
        }
        printf("\n");
    }
    return 0;
}

int mvRacket(int player, int racket, int btn, int y_max) {
    if (player == 1) {
        if ((btn == 97 || btn == 'A') && racket != 1) {
            return racket - 1;
        } else if ((btn == 122 || btn == 'Z') && racket + 2 != y_max - 1) {
            return racket + 1;
        } else
            return racket;
    }
    if (player == 2) {
        if ((btn == 107 || btn == 'K') && racket != 1) {
            return racket - 1;
        } else if ((btn == 109 || btn == 'M') && racket + 2 != y_max - 1) {
            return racket + 1;
        } else {
            return racket;
        }
    }
    return racket;
}
