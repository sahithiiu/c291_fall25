// A1problem3.c
#include <stdio.h>
#include <math.h>

int main(void) {
    double x, y;
    char op;
    if (scanf("%lf %c %lf", &x, &op, &y) != 3) return 0;

    switch (op) {
        case '+': printf("%.2f", x + y); break;
        case '-': printf("%.2f", x - y); break;
        case '*': printf("%.2f", x * y); break;
        case '/':
            if (y == 0.0) { printf("Error: dividing by zero"); }
            else printf("%.2f", x / y);
            break;
        case '%': {
            long long a = (long long)x, b = (long long)y;
            if (b == 0) { printf("Error: dividing by zero"); }
            else printf("%.2f", (double)(a % b));
        } break;
        case '^':
            printf("%.2f", pow(x, y));
            break;
        case 'r': { // x r y => x-th root of y
            if (x == 0.0) { printf("Error: dividing by zero"); }
            else printf("%.2f", pow(y, 1.0 / x));
        } break;
        default:
            // Undefined operator: print nothing per spec
            break;
    }
    return 0;
}
