#include <stdio.h>

#define N 15
#define M 13

void output(int **matrix, int n, int m);
void transform(int *buf, int **matr, int n, int m);
void make_picture(int **picture, int n, int m);
void reset_picture(int **picture, int n, int m);

int main() {
    int picture_data[N][M];
    int *picture[N];
    transform(*picture_data, picture, N, M);
    make_picture(picture, N, M);
    return 0;
}

void make_picture(int **picture, int n, int m) {
    int frame_w[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int frame_h[] = {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1};
    int tree_trunk[] = {7, 7, 7, 7};
    int tree_foliage[] = {3, 3, 3, 3};
    int sun_data[6][5] = {{0, 6, 6, 6, 6}, {0, 0, 6, 6, 6}, {0, 0, 6, 6, 6},
                          {0, 6, 0, 0, 6}, {0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};

    reset_picture(picture, n, m);

    int length_frame_w = sizeof(frame_w) / sizeof(frame_w[0]);
    int length_frame_h = sizeof(frame_h) / sizeof(frame_h[0]);
    int length_sun_data = sizeof(sun_data) / sizeof(sun_data[0]);
    int length_sun_data_frame = sizeof(sun_data[0]) / sizeof(sun_data[0][0]);
    int length_tree_foliage = sizeof(tree_foliage) / sizeof(tree_foliage[0]);
    int length_tree_trunk = sizeof(tree_trunk) / sizeof(tree_trunk[0]);

    for (int k = 0; k < length_sun_data; ++k) {
        for (int l = 0; l < length_sun_data_frame; ++l) {
            picture[k + 1][l + 7] = sun_data[k][l];
        }
    }

    for (int p = 0; p < 2; ++p) {
        for (int m = 0; m < length_tree_foliage; ++m) {
            picture[p + 3][m + 2] = tree_foliage[m];
            picture[m + 2][p + 3] = tree_foliage[m];
        }
    }
    for (int t = 0; t < length_tree_trunk; ++t) {
        for (int z = 0; z < length_tree_trunk; ++z) {
            if (t < 2) picture[z + 6][t + 3] = tree_trunk[z];
        }
        picture[10][t + 2] = tree_trunk[t];
    }

    for (int i = 0; i < length_frame_w; i++) {
        picture[0][i] = frame_w[i];
        picture[7][i] = frame_w[i];
        picture[14][i] = frame_w[i];
    }

    for (int j = 0; j < length_frame_h; j++) {
        picture[j][0] = frame_h[j];
        picture[j][6] = frame_h[j];
        picture[j][12] = frame_h[j];
    }

    output(picture, n, m);
}

void reset_picture(int **picture, int n, int m) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            picture[i][j] = 0;
        }
    }
}

void transform(int *buf, int **matr, int n, int m) {
    for (int i = 0; i < n; i++) {
        matr[i] = buf + i * m;
    }
}

void output(int **matrix, int n, int m) {
    for (int i = 0; i < n; ++i) {
        printf("%d", matrix[i][0]);
        for (int j = 1; j < m; ++j) {
            printf(" %d", matrix[i][j]);
        }
        if (i != n - 1) printf("\n");
    }
}
