#include "data_stat.h"

double max(double *data, int n) {
    double answ = data[0];
    for (int i = 1; i < n; ++i) {
        if (answ < data[i]) {
            answ = data[i];
        }
    }

    return answ;
}

double min(double *data, int n) {
    double answ = data[0];
    for (int i = 1; i < n; ++i) {
        if (answ > data[i]) {
            answ = data[i];
        }
    }

    return answ;
}

double mean(double *data, int n) {
    double sum = 0.;
    for (int i = 0; i < n; i++) {
        sum = sum + data[i];
    }
    return sum / n;
}

double variance(double *data, int n) {
    double sum = 0., mean1 = mean(data, n);
    for (int i = 0; i < n; i++) {
        sum += (data[i] - mean1) * (data[i] - mean1);
    }
    return sum / n;
}

void sort(double *data, int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1 - i; j++) {
            if (data[j] > data[j + 1]) {
                double twink = data[j];
                data[j] = data[j + 1];
                data[j + 1] = twink;
            }
        }
    }
}