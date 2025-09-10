// A1problem2.c
#include <stdio.h>

int main(void) {
    int a, b, c;
    if (scanf("%d %d %d", &a, &b, &c) != 3) return 0;

    if (a <= 0 || b <= 0 || c <= 0 || a + b + c != 180) {
        printf("Invalid");
        return 0;
    }

    printf("valid");

    if (a == 90 || b == 90 || c == 90) {
        printf(" right");
    } else if (a > 90 || b > 90 || c > 90) {
        printf(" obtuse");
    } else {
        printf(" acute");
    }

    int is_isosceles = (a == b) || (a == c) || (b == c);
    if (is_isosceles) {
        printf(" isosceles");
        if (a == 60 && b == 60 && c == 60) {
            printf(" equilateral");
        }
    }
    return 0;
}
