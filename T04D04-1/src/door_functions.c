#include <math.h>
#include <stdio.h>

double verzieraAgnesey(double x);
double bernoulliLemniscata(double x);
double quadraticHyperbola(double x);

int main() {
    const double piInterval = M_PI * 2 / 41;
    double point = M_PI * (-1);
    for (int i = 0; i <= 41; i++) {
        if (isnan(bernoulliLemniscata(point))) {
            printf("%.7lf | %.7lf | - | %.7lf\n", point, verzieraAgnesey(point), quadraticHyperbola(point));
        } else {
            printf("%.7lf | %.7lf | %.7lf | %.7lf\n", point, verzieraAgnesey(point),
                   bernoulliLemniscata(point), quadraticHyperbola(point));
        }
        point = point + piInterval;
    }
    return 1;
}

double verzieraAgnesey(double x) { return 1 / (1 + pow(x, 2)); }

double bernoulliLemniscata(double x) { return sqrt(sqrt(1 + 4 * x * x) - x * x - 1); }

double quadraticHyperbola(double x) { return 1 / (x * x); }