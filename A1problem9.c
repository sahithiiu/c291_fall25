// A1problem9.c
#include <stdio.h>

int main(void) {
    double alpha = 0.1, beta = 0.02, delta = 0.01, gamma = 0.1;
    double x = 40.0, y = 9.0;
    double dt = 0.01;
    int N = 1000;

    for (int t = 1; t <= N; ++t) {
        double dx = (alpha * x - beta * x * y) * dt;
        double dy = (delta * x * y - gamma * y) * dt;
        x += dx;
        y += dy;
        printf("Time step: %d, Prey (x): %.2f, Predators (y): %.2f\n", t, x, y);
    }
    return 0;
}
